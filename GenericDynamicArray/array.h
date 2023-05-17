#ifndef MYARRAY_H
#define MYARRAY_H
#include <iostream>

template <typename T>
class Array{
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Array<U>&);
    private:
        T *data;
        int size;
    public:
        Array(){
            this->size = 0;
            data = new T[0];
        }
        Array(T arr[], int size){
            this->size = size;
            data = new T[size];
            for(int i=0; i<size; i++)
                data[i] = arr[i];
        }
        Array(const Array &o){
            this->size = o.size;
            data = new T[o.size];
            for(int i=0; i<o.size; i++)
                data[i] = o.data[i];
        }
        ~Array() {
            delete[] data;
        }
        void pushback(T n){
            size++;
            T* aux = new T[size];
            for(int i=0; i<size-1; i++)
                aux[i] = data[i];
            delete [] data;
            aux[size-1] = n;
            data = aux;
        }
        void insert(T n, int pos){
            size++;
            T* aux = new T[size];
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
            T* aux = new T[size];
            for(int i=0; i<pos; i++)
                aux[i] = data[i];
            for(int i=pos; i<size; i++)
                aux[i] = data[i+1];
            delete [] data;
            data = aux;
        }
        T& operator[](int i) {
            return data[i];
        }
};
template <typename T>
std::ostream& operator<<(std::ostream& output, const Array<T>& A) {
    output << "[ ";
    for(int i=0; i<A.size; i++)
        output << A.data[i] << " ";
    output << "]" << std::endl;
    return output;
}

#endif