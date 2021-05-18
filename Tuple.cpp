#include <iostream>
#include <utility>


template<std::size_t i, typename T>
struct TupleNode 
{
    T value;
    TupleNode() = default;
    TupleNode(const T& val) : value(val) { /*std::cerr << "TNc";*/ }
    TupleNode(T&& val) : value(std::move(val)) { /*std::cerr << "TNm";*/ }
    TupleNode(const TupleNode& TN) : value(TN.value) { /*std::cerr << "TN=c";*/ }
    TupleNode(TupleNode&& TN) : value(std::move(TN.value)) { /*std::cerr << "TN=m";*/ }
};



template <size_t i, typename ...Args>
class TupleBase;

template <size_t i>
class TupleBase<i> 
{
public:
    TupleBase() = default;
};

template <size_t i, typename Head, typename ...Args>
class TupleBase<i, Head, Args...> : public TupleBase<i + 1, Args...>, public TupleNode<i, Head>
{
protected:

public:
    TupleBase() : TupleBase<i + 1, Args...>(), TupleNode<i, Head>() {}
    template <typename Head2, typename ...Args2>
    TupleBase(Head2&& first, Args2&&... args) : TupleBase<i + 1, Args...>(std::forward<Args2>(args)...), TupleNode<i, Head>(std::forward<Head2>(first)) {}

    //template <typename Head2, typename ...Args2>
    //TupleBase(const TupleBase& other) : TupleBase<i + 1, Args...>(other), TupleNode<i, Head>(other.TupleNode<i, Head_other>::value) {}
    //template <size_t i_other, typename Head_other, typename ...Args_other>
    //TupleBase(TupleBase&& other) : TupleBase<i + 1, Args>(other), TupleNode<i, Head>(other.TupleNode<i, Head_other>::value) {}

    ~TupleBase() = default;
};

template<typename... Args>
using Tuple = TupleBase<0, Args...>;


template<std::size_t i, typename Head, typename ...Args>
Head& Get(TupleBase<i, Head, Args...>& tuple)
{
    return tuple.TupleNode<i, Head>::value;
}
template<std::size_t i, typename Head, typename ...Args>
const Head& Get(const TupleBase<i, Head, Args...>& tuple)
{
    return tuple.TupleNode<i, Head>::value;
}
template<std::size_t i, typename Head, typename ...Args>
Head&& Get(TupleBase<i, Head, Args...>&& tuple)
{
    return std::move(tuple.TupleNode<i, Head>::value);
}

//template<typename T, size_t j, size_t i, typename Head, typename ...Args>
//constexpr T& Get(TupleBase<i, Head, Args...>& tuple, decltype(std::declval<TupleBase<i, Head, Args...>>().TupleNode<j, T>::value) q = T())
//{
//    return tuple.TupleNode<j, T>::value;
//}
//template<typename T, size_t j, size_t i, typename Head, typename ...Args>
//constexpr const T& Get(const TupleBase<i, Head, Args...>& tuple, decltype(std::declval<TupleBase<i, Head, Args...>>().TupleNode<j, T>::value) q = T())
//{
//    return tuple.TupleNode<j, T>::value;
//}
//template<typename T, size_t j, size_t i, typename Head, typename ...Args>
//constexpr T&& Get(TupleBase<i, Head, Args...>&& tuple, decltype(std::declval<TupleBase<i, Head, Args...>>().TupleNode<j, T>::value) q = T())
//{
//    return tuple.TupleNode<j, T>::value;
//}
//template <typename T>
//struct get_by_t
//{
//    static T val;
//
//    template <size_t j, size_t i, typename Head, typename ...Args>
//    get_by_t(const TupleBase<i, Head, Args...>& tuple) : val(tuple.TupleNode<j, T>::value) {}
//};

template<typename T, size_t i, typename ...Args>
constexpr const T& Get(const TupleBase<i, T, Args...>& tuple);
template<typename T, size_t i, typename ...Args>
constexpr const T& Get(const TupleBase<i, Args...>& tuple);

template<typename T, size_t i, typename Head, typename ...Args>
constexpr const T& _Get(const TupleBase<i, Head, Args...>& tuple)
{
    return Get<T, i + 1, Args...>(tuple);
}

template<typename T, size_t i, typename ...Args>
constexpr const T& Get(const TupleBase<i, Args...>& tuple)
{
    return _Get<T, i, Args...>(tuple);
}
template<typename T, size_t i, typename ...Args>
constexpr const T& Get(const TupleBase<i, T, Args...>& tuple)
{
    return tuple.TupleNode<i, T>::value;
}


//template<typename T, size_t i, typename Head, typename ...Args>
//constexpr const T& _Get(const WithArgs<Head, Args...>& tuple)
//{
//    std::cout << "c" << i << " " << typeid(Head).name() << "|";
//    return Get<T, i + 1, Args...>(tuple);
//}
//template<typename T, size_t i, typename ...Args>
//constexpr const T& Get(const WithArgs<Args...>& tuple)
//{
//    std::cout << "b" << i << " " << typeid(T).name() << "|";
//    return _Get<T, i, Args...>(tuple);
//}
//template<typename T, size_t i, typename ...Args>
//constexpr const T& Get(const WithArgs<T, Args...>& tuple)
//{
//    std::cout << "a" << i << " " << typeid(T).name() << "|";
//    return tuple.h;
//}


#include <iostream>

struct Accounter
{
    explicit Accounter(int) { std::cerr << "A"; }
    Accounter(const Accounter& other) { std::cerr << "Ac"; }
    Accounter(Accounter&& other) { std::cerr << "Am"; }
    Accounter& operator=(const Accounter& other) { std::cerr << "A=c"; return *this; }
    Accounter& operator=(Accounter&& other) { std::cerr << "A=m"; return *this; }
};

std::ostream& operator<<(std::ostream& os, const Accounter& acc)
{
    return os << "<acc<";
}



int main()
{
  /*  Tuple<int, std::pair<double, float>>();
    Tuple<int, std::pair<double, float>>(0, std::pair<double, float>(2.0, 1.0));

    const int i = 1;
    double k = 2;
    Tuple<int> qwe(i);
    Tuple<int, double>(i, k);*/

    Accounter a(0);
    const Tuple<Accounter, int, Accounter> t3(a, 0, Accounter(1));
    std::cout << "\n";
    const Accounter b(0);
    Tuple<Accounter, int, Accounter, Accounter> t4(Accounter(2), 0, Accounter(3), b);
    std::cout << "\n";

    std::cout << Get<0>(t3);
    std::cout << Get<1>(t4);
    std::cout << Get<2>(Tuple<Accounter, int, Accounter, Accounter>(a, 0, Accounter(4), a));


    std::cout << Get<int>(t3);
    std::cout << Get<Accounter>(t3);
    //std::cout << Get<int>(t4);
    //std::cout << Get<int>(Tuple<Accounter, int, Accounter, Accounter>(a, 0, Accounter(4), a));
}
