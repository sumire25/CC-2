// DynaIntArr ////////////////////

#include "array.h"
#include "complex.h"
#include <random>
using namespace std;

int main(){
    Array<int> I;
    Array<float> F;
    Array<char> H;
    Array<Complex> C;
    //random
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(-9, 9);

    cout << "Mostramos un array de integers al cual le anadimos 5 elementos:" << endl;
    for(int i=0; i<5; i++)
        I.pushback(dis(gen));
    cout << "I: "<< I << endl;

    cout << "Mostramos un array de floats al cual le anadimos 5 elementos:" << endl;
    for(int i=0; i<5; i++)
        F.pushback(float(dis(gen)) / dis(gen));
    cout << "F: "<< F << endl;

    cout << "Mostramos un array de chars al cual le anadimos 5 elementos:" << endl;
    for(int i=0; i<5; i++)
        H.pushback(106 + dis(gen));
    cout << "H: "<< H << endl;

    cout << "Mostramos un array de complex al cual le anadimos 5 elementos:" << endl;
    for(int i=0; i<5; i++)
        C.pushback(Complex(dis(gen), dis(gen)));
    cout << "C: "<< C << endl;

    cout << "Insertamos en C[2]: C[0] * C[1]\nUsando sobrecarga en los operadores '[]' y '*'" << endl;
    C.insert(C[0] * C[1], 2);
    cout << "C: "<< C << endl;

    cout << "Removemos C[0]:" << endl;
    C.remove(0);
    cout << "C: "<< C << endl;

    cout << "Insertamos en C[2]: C[1] / C[0]\nAhora sobrecargando al operador '/'" << endl;
    C.insert(C[1] / C[0], 2);
    cout << "C: "<< C << endl;
    
    return 0;
}