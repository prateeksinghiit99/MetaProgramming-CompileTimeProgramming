#include <iostream>
#include<type_traits>

using namespace std;
template<int...Args> // <int...Args>
struct Vector;

/*
It can accept 

Vector<>
Vector<1>
Vector<23,1>
Vector<456,78,9>



template<typename Vector>
struct uniq{// meta function
    using type = xxx;
};



vector<int> uniq(vector<int> input){
    vector<int> output;
    for(int i=0;i<input.size();){
        int j = i;
        output.push_back(input[i]);
        while(i<input.size() && input[j]==input[i] )
            i++;
    }
    return output;
}
*/

//primary template
template<typename InpVector,typename OutVector = Vector<> >
struct uniq;

//partial specialization of templates
// Case-1 where 1st 2nd elements are same, don't include it in output
template<int i,int...tail,int...outVecElems>
struct uniq <Vector<i,i,tail...> , Vector<outVecElems...> >{
    using type = typename uniq< Vector<i,tail...> , Vector<outVecElems...> >::type;
};

//partial specialization of templates
// Case-2 where 1st 2nd elements are different, include it in output
template<int i,int...tail,int...outVecElems>
struct uniq <Vector<i,tail...> , Vector<outVecElems...> >{ 
    using type = typename uniq <Vector<tail...>, Vector<outVecElems...,i> >::type;
};

//partial specialization of templates
// Case-3 Input vector is empty 
// Base condition for recursion
template<typename OutVector>
struct uniq <Vector<> , OutVector >{ 
    using type = OutVector;
};

//uniq<Vector<1,2,2,2,3,4,4,5>>::type == vector<1,2,3,4,5>
//static_assert( std::is_same_v<  uniq<Vector<1,2,2,2,3,4,4,5>>::type , vector<1,2,3,4,5>   > );

int main()
{
    static_assert( std::is_same_v< typename uniq<Vector<1,2,2,2,3,4,4,5>>::type , Vector<1,2,3,4,5>   >);
    static_assert( std::is_same_v< typename uniq<Vector<1,2,2,2,3,4,4,1,1,5>>::type , Vector<1,2,3,4,1,5>   >);
    
    return 0;
}

