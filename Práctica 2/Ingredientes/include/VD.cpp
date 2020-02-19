#include "VD.h"
template <class T>
void VD<T>::Resize(int siz){
    
    T* aux = new T[siz];
    int min = (siz < n) ? siz:n;
    for(int i = 0; i < min; i++)
        aux[i] = data[i];
    
    reserved = siz;
    n = min;
    delete [] data;
    data = aux;
}

template <class T>
void VD<T>::Copy(const VD<T> &orig){
    if(data != 0)
        Free();
    
    reserved = orig.reserved;
    n = orig.n;
    data = new T[reserved];
    for(int i = 0; i < n; i++)
        data[i] = orig.data[i];
}

template <class T>
void VD<T>::Free(){
    delete [] data;
    reserved = 0;
    n = 0;
}

template <class T>
VD<T>::VD(int siz){
    reserved = siz;
    n = 0;
    data = new T[reserved];
}

template <class T>
VD<T>::VD(const VD<T> &orig){
    data = 0;
    Copy(orig);
}

template <class T>
VD<T>::~VD(){
    Free();
}

template <class T>
VD<T>& VD<T>::operator =(const VD<T> &orig){
    if(this != &orig){
        Free();
        Copy(orig);
    }
    
    return *this;
}

template <class T>
void VD<T>::Insert(const T &d, int pos){
    if(n>= (reserved/2))
        Resize(2*reserved);
    
    for(int i = n; i > pos; i--)
        data[i] = data[i-1];
    
    data[pos] = d;
    n++;
}

template <class T>
void VD<T>::Erase(int pos){
    for(int i = pos; i < n-1; i++)
        data[i] = data[i+1];
    
    n--;
    
    if(n < (reserved/4))
        Resize(reserved/2);
}