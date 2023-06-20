#include <iostream>

using namespace std;

/*
1. Primal template 
template<int a,int b>
struct primeUtil{   // Doesn't have any <> here

2. Partila specialization
template<int a>
struct primeUtil<a,1>  // have partial matching here <>

3. Full specialization
template<>
struct prime<1>{  // have empty <> template and <1> value completely matches


*/
template<int a,int b>
struct primeUtil{
    inline static constexpr bool value = static_cast<bool>(a%b) && primeUtil<a,b-1>::value;
};

template<int a>
struct prime{
    inline static constexpr bool value = primeUtil<a,a/2>::value;
};

// Full specialization
template<>
struct prime<1>{
    inline static constexpr bool value = false;
};


//partial specialization
template<int a>
struct primeUtil<a,1>{
    inline static constexpr bool value = true;
};


int main()
{
    static_assert(prime<1>::value == false);
    static_assert(prime<2>::value == true);
    static_assert(prime<17>::value == true);
    static_assert(prime<4>::value == false);
    static_assert(prime<64>::value == false);
    static_assert(prime<105>::value == false);
    return 0;
}

