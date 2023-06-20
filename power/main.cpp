#include <iostream>

using namespace std;

template<int a,int b>
struct power{
    inline static constexpr int value = a * power<a,b-1>::value;
};

template<int a>
struct power<a,0>{
    inline static constexpr int value = 1;
};

int main()
{
    static_assert(power<3,3>::value == 27);
    static_assert(power<4,3>::value == 64);
    return 0;
}
