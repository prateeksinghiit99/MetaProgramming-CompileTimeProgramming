#include <iostream>
#include <type_traits>

using namespace std;

void print(){
    cout<<endl;
}

template<typename Head, typename...Tail>
void print(const Head& head,const Tail&...tail){
    cout<<head<<" ";
    print(tail...);
}

int main()
{
    print();
    print(1);
    print(1,1.90);
    print("Hehe",'x',768);

    return 0;
}
