#include <iostream>


template<std::size_t i, typename T>
struct TupleNode {
    T value;
    TupleNode() = default;
    TupleNode(const T& val) : value(val) { std::cerr << "TNc"; }
    TupleNode(T&& val) : value(std::move(val)) { std::cerr << "TNm"; }
    TupleNode(const TupleNode& TN) : value(TN.value) { std::cerr << "TN=c"; }
    TupleNode(TupleNode&& TN) : value(std::move(TN.value)) { std::cerr << "TN=m"; }
};


template <size_t i, typename ...Args>
class TupleBase;

template <size_t i>
class TupleBase<i> 
{

};

template <size_t i, typename Head, typename ...Args>
class TupleBase<i, Head, Args...> : public TupleBase<i + 1, Args...>, TupleNode<i, Head>
{
protected:

public:
    explicit TupleBase() : TupleBase<i + 1, Args...>(), TupleNode<i, Head>() {}

    //explicit TupleBase(const Head& first, const Args&... args) : TupleBase<i + 1, Args...>(args), TupleNode<i, Head>(first) { std::cerr << "TBc" << i << " "; }
    explicit TupleBase(Head&& first, Args&&... args);
    explicit TupleBase(const Head&& first, Args&&... args);

    //template <size_t i_other, typename Head_other, typename ...Args_other>
    //TupleBase(const TupleBase& other) : TupleBase<i + 1, Args>(other), TupleNode<i, Head>(other.TupleNode<i, Head_other>::value) {}
    //template <size_t i_other, typename Head_other, typename ...Args_other>
    //TupleBase(TupleBase&& other) : TupleBase<i + 1, Args>(other), TupleNode<i, Head>(other.TupleNode<i, Head_other>::value) {}

    ~TupleBase() = default;
};

template <size_t i, typename Head, typename ...Args>
TupleBase<i, Head, Args...>::TupleBase(Head&& first, Args&&... args) : TupleBase<i + 1, Args...>(std::forward<Args>(args)...),
                                                   TupleNode<i, Head>(std::forward<Head>(first)) { std::cerr << "TBm." << i; }
template <size_t i, typename Head, typename ...Args>
TupleBase<i, Head, Args...>::TupleBase(const Head&& first, Args&&... args) : TupleBase<i + 1, Args...>(std::forward<Args>(args)...),
                                                        TupleNode<i, Head>(first) { std::cerr << "TBm," << i; }




template<typename... Args>
using Tuple = TupleBase<0, Args...>;




#include <iostream>

struct Accounter
{
    Accounter(int) { std::cerr << "A"; }
    Accounter(const Accounter& other) { std::cerr << "Ac"; }
    Accounter(Accounter&& other) { std::cerr << "Am"; }
    Accounter& operator=(const Accounter& other) { std::cerr << "A=c"; return *this; }
    Accounter& operator=(Accounter&& other) { std::cerr << "A=m"; return *this; }
};

int main()
{
    Tuple<int, std::pair<double, float>> t;
    Tuple<int, std::pair<double, float>> t2(0, std::pair<double, float>(2.0, 1.0));

    Accounter a(0);
    Tuple<Accounter, int, Accounter> t3(a, 0, Accounter(1));
    Tuple<Accounter, int, Accounter, Accounter> t4(Accounter(2), 0, Accounter(3), a);
    Tuple<Accounter, int, Accounter, Accounter> t5(a, 0, Accounter(4), a);
}
