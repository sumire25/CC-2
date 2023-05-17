// DynaIntArr ////////////////////

#include "dyint.h"
#include "complex.h"
using namespace std;

int main(){
    int l[] = {1,2,3,4,5};
    int size = 5;
	DynamicIntegerArray L = DynamicIntegerArray(l, size);
    L.print();
    L.pushback(1000000);
    L.print();
    L.insert(0,0);
    L.print();
    L.remove(1);
    L.print();
    cout<<"chupame la pinga"<<endl;
    Complex<float> f;
    //Complex<string> s;
    Complex<int> i;
    f.setSize(.6);
    //s.setSize("bcp");
    i.setSize(54);
    f.print();
    //s.print();
    i.print();
    return 0;
}