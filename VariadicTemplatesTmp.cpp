
#include <iostream>
#include <string>
#include <utility>

//
//template <typename T>
//void f(const T&) { std::cout << "TC&"; }
//template <typename T>
//void f(T&) { std::cout << "T&"; }
//template <typename T>
//void f(T&&) { std::cout << "T&&"; }
//
//
//template <typename T>
//void knowtype(T x) = delete;
//
//
//
//
//
//template <typename T, typename ... Args>
//struct screate;
//
//template <typename T, typename Head, typename ... Args>
//struct screate<T, Head, Args...>
//{
//    screate(Head&& head, Args&& ... args) {
//        std::cout << "Hs&&";
//        f(std::forward<decltype(head)>(head));
//    }
//};
//
//template <typename T>
//struct screate<T>
//{
//    screate() {
//    }
//};
//
//
//
//
//
//
//
//template <typename T, typename Head, typename ...Args>
//struct tmp
//{
//    template <typename Head2, typename ... Args2>
//    void f(Head2&& head, Args2&&... args)
//    //void f(Head&& head, Args&&... args)
//    {
//        std::cout << head << "<<<";
//    }
//};
//
//
//template <typename T>
//T create() {
//    return T();
//}
//
//template <typename T, typename Head, typename ... Args>
//T create(Head&& head, Args&& ... args) {
//
//    //knowtype(head);
//    std::cout << "H&&";
//    f(std::forward<decltype(head)>(head));
//    create<T>(std::forward<Args>(args)...);
//    return T(head, std::forward<Args>(args)...);
//}
//
//struct MyStruct {
//    MyStruct() {}
//    MyStruct(int i) {}
//    MyStruct(int i, int d) {}
//    MyStruct(int i, int d, int s) {}
//    MyStruct(int i, int d, int s, int q) {}
//};

template <typename Head, typename ...Args>
struct WithArgs;

template <typename Head>
struct WithArgs<Head>
{
    Head h;
    template <typename Head2>
    WithArgs(Head2&& h) : h(std::forward<Head>(h)) {}
};

template <typename Head, typename ...Args>
struct WithArgs : WithArgs<Args...>
{
    Head h;
    template <typename Head2, typename ...Args2>
    WithArgs(Head2&& h,Args2&&... args) : WithArgs<Args...>(std::forward<Args>(args)...),h(std::forward<Head>(h)) {}
};



//template<typename T, size_t i, typename ...Args> //, typename = std::enable_if_t<!std::is_same_v<T, Head>>
//constexpr const T& Get(const WithArgs<Args...>& tuple);
//
//
//template<typename T, size_t i, typename Head, typename ...Args>
//constexpr const T& Get(const WithArgs<T, Args...>& tuple)
//{
//    std::cout << i;
//    return T();
//}
//template<typename T, size_t i, typename ...Args> //, typename = std::enable_if_t<!std::is_same_v<T, Head>>
//constexpr const T& Get(const WithArgs<Head, Args...>& tuple)
//{
//    return Get<T, i + 1, Args...>(tuple);
//}

template<typename T, size_t i, typename ...Args> //, typename = std::enable_if_t<!std::is_same_v<T, Head>>
constexpr const T& Get(const WithArgs<Args...>& tuple);
template<typename T, size_t i, typename ...Args>
constexpr const T& Get(const WithArgs<T, Args...>& tuple);

template<typename T, size_t i, typename Head, typename ...Args>
constexpr const T& _Get(const WithArgs<Head, Args...>& tuple)
{
    std::cout << "c" << i << " " << typeid(Head).name() << "|";
    return Get<T, i + 1, Args...>(tuple);
}

template<typename T, size_t i, typename ...Args>
constexpr const T& Get(const WithArgs<Args...>& tuple)
{
    std::cout << "b" << i << " " << typeid(T).name() << "|";
    return _Get<T, i, Args...>(tuple);
}
template<typename T, size_t i, typename ...Args> 
constexpr const T& Get(const WithArgs<T, Args...>& tuple)
{
    std::cout << "a" << i << " " << typeid(T).name() << "|";
    return tuple.h;
}


int main() 
{
    Get<double, 0>(WithArgs<int, double, int>(0,0,0));
    Get<double, 0>(WithArgs<int, double>(0,0));
    Get<double, 0>(WithArgs<int, int, float, double>(0,0,0,0));

    /*int ia = 0;
    const int ib = 1;
    int&& ic = 2;
    create<MyStruct>(1, ia, ib, ic);
    tmp<int, int, int, int, int> ttmp;
    ttmp.f(1, ia, ib, ic);*/

    //std::cout << std::endl;

    //// Lvalues
    //const int five = 5;
    //screate<int, int> s(five);
    //int myFive = create<int>(five);
    //std::cout << "myFive: " << myFive << std::endl;

    //std::string str{ "Lvalue" };
    //std::string str2 = create<std::string>(str);
    //std::cout << "str2: " << str2 << std::endl;

    //// Rvalues
    //int myFive2 = create<int>(5);
    //std::cout << "myFive2: " << myFive2 << std::endl;

    //std::string str3 = create<std::string>(std::string("Rvalue"));
    //std::cout << "str3: " << str3 << std::endl;

    //std::string str4 = create<std::string>(std::move(str3));
    //std::cout << "str4: " << str4 << std::endl;

    //// Arbitrary number of arguments
    //double doub = create<double>();
    //std::cout << "doub: " << doub << std::endl;

    //MyStruct myStr = create<MyStruct>(2011, 3.14, str4);


    //std::cout << std::endl;

}
