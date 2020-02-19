#ifndef VD_H
#define VD_H

template <class T>
class VD{
    private:
        T* data;
        int n;
        int reserved;
        void Resize(int siz);
        void Copy(const VD<T> &orig);
        void Free();
    public:
        /**
         * @brief Contructor por defecto y con parametro
         * @param siz: elementos a reservar para el vector dinamico
         * @note si no se proporciona un valor para tam se tomara como 10
         */
        VD(int siz = 10);
        
        /**
         * @brief Constructor de copia
         * @param orig: vector dinamico origen
         */
        VD(const VD<T> &orig);
        
        /**
         * @brief Destructor. Elimina la memoria asociada al vector dinamico
         */
        ~VD();
        
        /**
         * @brief Operador de asignacion
         * @param orig: vector dinamico fuente
         * @return una referencia a objeto VD<T>
         */
        VD<T>& operator=(const VD<T> &orig);
        
        /**
         * @brief Obtiene el numero de elementos almacenados en el vector dinamico
         * @return entero que contiene el numero de elementos del vector
         */
        int size() const {return n;}
        
        /**
         * @brief Consulta y modifica el elemento i-esimo
         * @param i: posicion del elemento
         * @return una referencia al elemento i-esimo del vector dinamico
         */
        T& operator[](int i) {return data[i];} //Version no constante
        const T operator[] (int i) const {return data[i];}    //Version constante
        
        /**
         * @brief Inserta un objeto en la posicion pos del vector dinamico
         * @param d: objeto a insertar
         * @param pos: posicion donde insertar
         * @pre pos debe estar comprendido entre 0 y size()
         * @post aumenta en uno el vector dinamico
         */
        void Insert(const T &d, int pos);
        
        /**
         * @brief Elimina el elemento en la posicion pos
         * @param pos: posicion del elemento a borrar
         */
        void Erase(int pos);
};

#include "VD.cpp"

#endif /* VD_H */

