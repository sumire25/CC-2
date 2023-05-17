#ifndef MYINTARRAY_H
#define MYINTARRAY_H
#include <iostream>

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
            std::cout<<"[ ";
            for(int i=0; i<size; i++)
                std::cout<< data[i]<<" ";
            std::cout<<"]"<<std::endl;
        }
        ~DynamicIntegerArray() {
            delete[] data;
        }
        void pushback(int n){
            size++;
            int* aux = new int[size];
            for(int i=0; i<size-1; i++)
                aux[i] = data[i];
            delete [] data;
            aux[size-1] = n;
            data = aux;
        }
        void insert(int n, int pos){
            size++;
            int* aux = new int[size];
            for(int i=0; i<pos; i++)
                aux[i] = data[i];
            aux[pos] = n;
            for(int i=pos+1; i<size; i++)
                aux[i] = data[i-1];
            delete [] data;
            data = aux;
        }
        void remove(int pos){
            size--;
            int* aux = new int[size];
            for(int i=0; i<pos; i++)
                aux[i] = data[i];
            for(int i=pos; i<size; i++)
                aux[i] = data[i+1];
            delete [] data;
            data = aux;
        }
};
#endif
