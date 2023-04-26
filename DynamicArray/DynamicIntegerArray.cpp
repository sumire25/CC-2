// DynaIntArr ////////////////////

#include <iostream>
using namespace std;

class DynamicIntegerArray{
    private:
        int *data;
        int size;
    public:
        DynamicIntegerArray(){
            this->size = 0;
            data = new int[0];
        }
        DynamicIntegerArray(int arr[], int size){
            this->size = size;
            data = new int[size];
            for(int i=0; i<size; i++)
                data[i] = arr[i];
        }
        DynamicIntegerArray(const DynamicIntegerArray &o){
            this->size = o.size;
            data = new int[o.size];
            for(int i=0; i<o.size; i++)
                data[i] = o.data[i];
        }
        void print() const{
            cout<<"[ ";
            for(int i=0; i<size; i++)
                cout<< data[i]<<" ";
            cout<<"]"<<endl;
        }
        ~DynamicIntegerArray() {
            delete[] data;
        }
        void pushback(int n){
            int aux[size];
            //int* aux = new int[size];
            for(int i=0; i<size; i++)
                aux[i] = data[i];
            delete [] data;
            size++;
            data = new int[size];
            for(int i=0; i<size-1; i++)
                data[i] = aux[i];
            data[size-1] = n;
        }
        void insert(int n, int pos){
            int aux[size];
            //int* aux = new int[size];
            for(int i=0; i<size; i++)
                aux[i] = data[i];
            delete [] data;
            size++;
            data = new int[size];
            for(int i=0; i<pos; i++)
                data[i] = aux[i];
            data[pos] = n;
            for(int i=pos+1; i<size; i++)
                data[i] = aux[i-1];
        }
        void remove(int pos){
            int aux[size];
            //int* aux = new int[size];
            for(int i=0; i<size; i++)
                aux[i] = data[i];
            delete [] data;
            size--;
            data = new int[size];
            for(int i=0; i<pos; i++)
                data[i] = aux[i];
            for(int i=pos; i<size; i++)
                data[i] = aux[i+1];
        }
};
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
}