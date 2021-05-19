#include <iostream>
#include <utility>
#include <type_traits>



template <size_t i, typename ...Args>
class TupleBase;

template <size_t i>
class TupleBase<i> 
{
public:
    TupleBase() = default;
};

template <size_t i, typename Head, typename ...Args>
class TupleBase<i, Head, Args...> : public TupleBase<i + 1, Args...>
{
protected:

public:
    Head value;

    TupleBase() : TupleBase<i + 1, Args...>(), value() {}

    template <typename Head2, typename ...Args2>
    explicit TupleBase(Head2&& head, Args2&&... args) : TupleBase<i + 1, Args...>(std::forward<Args2>(args)...), value(std::forward<Head2>(head)) {}

    //template <typename Head2, typename ...Args2>
    //TupleBase(const TupleBase& other) : TupleBase<i + 1, Args...>(other), TupleNode<i, Head>(other.TupleNode<i, Head_other>::value) {}
    //template <size_t i_other, typename Head_other, typename ...Args_other>
    //TupleBase(TupleBase&& other) : TupleBase<i + 1, Args>(other), TupleNode<i, Head>(other.TupleNode<i, Head_other>::value) {}

    ~TupleBase() = default;
};

template<typename... Args>
using Tuple = TupleBase<0, Args...>;


/*
template <typename T, std::size_t i, typename Head>
constexpr int CountType(const TupleBase<i, Head>&)
{
	return (std::is_same_v<T, Head> ? 1 : 0);
}
template <typename T, std::size_t i, typename Head, typename ...Args>
constexpr int CountType(const TupleBase<i, Head, Args...>& tuple)
{
	return CountType<T, i + 1, Args...>(tuple) + (std::is_same_v<T, Head> ? 1 : 0);
}
*/
template <typename T, typename ...Args>
struct CountType;

template <typename T>
struct CountType<T>
{
	static const int val = 0;
};

template <typename T, typename Head, typename ...Args>
struct CountType<T, Head, Args...>
{
	static const int val = CountType<T, Args...>::val + std::is_same_v<T, Head>;
};



template <std::size_t i, typename Head, typename ...Args>
constexpr Head& Get(TupleBase<i, Head, Args...>& tuple)
{
    return tuple.value;
}
template <std::size_t i, typename Head, typename ...Args>
constexpr const Head& Get(const TupleBase<i, Head, Args...>& tuple)
{
    return tuple.value;
}
template <std::size_t i, typename Head, typename ...Args>
constexpr Head&& Get(TupleBase<i, Head, Args...>&& tuple)
{
    return std::move(tuple.value);
}


template<typename T, size_t i, typename Head, typename ...Args, 
	typename std::enable_if_t<!std::is_same_v<T, Head>>* = nullptr>
constexpr const T& Get(const TupleBase<i, Head, Args...>& tuple);
template<typename T, size_t i, typename Head, typename ...Args, 
	typename std::enable_if_t<std::is_same_v<T, Head> && CountType<T, Args...>::val == 0>* = nullptr>
constexpr const T& Get(const TupleBase<i, Head, Args...>& tuple);

template<typename T, size_t i, typename Head, typename ...Args, 
	typename std::enable_if_t<!std::is_same_v<T, Head>>*>
constexpr const T& Get(const TupleBase<i, Head, Args...>& tuple)
{
	return Get<T, i + 1, Args...>(tuple);
}
template<typename T, size_t i, typename Head, typename ...Args, 
	typename std::enable_if_t<std::is_same_v<T, Head> && CountType<T, Args...>::val == 0>*>
constexpr const T& Get(const TupleBase<i, Head, Args...>& tuple)
{
    std::cerr << "[" << i << "]";
    return tuple.value;
}








#include <iostream>

struct Accounter
{
    explicit Accounter(int) { std::cerr << "A"; }
    Accounter(const Accounter& /*other*/) { std::cerr << "Ac"; }
    Accounter(Accounter&& /*other*/) { std::cerr << "Am"; }
    Accounter& operator=(const Accounter& /*other*/) { std::cerr << "A=c"; return *this; }
    Accounter& operator=(Accounter&& /*other*/) { std::cerr << "A=m"; return *this; }
};

std::ostream& operator<<(std::ostream& os, const Accounter& /*acc*/)
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
    Tuple<int, Accounter, double> t3(0, a, 0.0);
    std::cout << "\n";
    const Accounter b(0);
    Tuple<Accounter, int, Accounter, Accounter> t4(Accounter(2), 0, Accounter(3), b);
    std::cout << "::" << CountType<Accounter, int, Accounter, Accounter>::val;
    std::cout << "::" << CountType<Accounter, int, Accounter>::val;
    std::cout << "::" << CountType<Accounter, int>::val;
    std::cout << "\n";

    std::cout << Get<0>(t3);
    std::cout << Get<1>(t4);
    std::cout << Get<2>(Tuple<Accounter, int, Accounter, Accounter>(a, 0, Accounter(4), a));

    std::cout << Get<int>(t3);
    std::cout << Get<Accounter>(t3);
    std::cout << Get<int>(t4);
    std::cout << Get<int>(Tuple<Accounter, Accounter, Accounter, int>(a, Accounter(4), a, 0));
    //std::cout << Get<Accounter>(Tuple<Accounter, Accounter, Accounter, int>(a, Accounter(4), a, 0));
}

