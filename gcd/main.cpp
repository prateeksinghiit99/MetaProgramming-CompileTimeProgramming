#include <iostream>
#include <type_traits>
using namespace std;

template<int a,int b>
struct GCD {
    inline static constexpr int value = GCD<b,a%b>::value;
};


// Partial specialization of template
template<int a>
struct GCD <a,0>{
    inline static constexpr int value = a;
};

int main()
{
    static_assert(GCD<9,24>::value == 3);

    return 0;
}