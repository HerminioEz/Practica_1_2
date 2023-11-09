#include <ostream>
#include "List.h"
#include <exception>

template <typename T>
class ListArray : public List<T> {

    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE = 1;
        void resize(int new_size);
    public:

        ListArray();
        ~ListArray();
        int size(void) const override {
            return n;
        }

        T operator[](int pos){
            if (pos >= 0 && pos < n){
                return arr[pos];
            } else {
                throw std::out_of_range("fuera del intervalo");
            }
        };
        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
            for (int i = 0; i < list.n; i++) {
                out << list.arr[i] << "\n";
            }
            return out;
        };
        void insert(int pos, T e) override;
        void append(T e) override;
        void prepend(T e) override;
        T remove(int pos) override;
        T get(int pos) override;
        int search(T e) override;
        bool empty() override;
};
template <typename T>
ListArray<T>::ListArray(){
    arr = new T[MINSIZE];
    n = 0;
    max = MINSIZE;
}
template <typename T>
ListArray<T>::~ListArray(){
    delete arr;
}
template <typename T>
void ListArray<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw std::out_of_range("fuera del intervalo");
    } else {
        for (int i = n; i >= pos+1; i--) {
            arr[i] = arr[i-1];
        }
        arr[pos] = e;
        n++;
    }
}


template <typename T>
void ListArray<T>::append(T e) {
    if (n >= max-1) {
        resize(n+1);
    }
    insert(n,e);


}

template <typename T>
void ListArray<T>::prepend(T e) {
    if (n >= max-1) {
        resize(n+1);
    }
    insert(0, e);
}

template <typename T>
T ListArray<T>::remove(int pos) {
    T r = arr[pos];
    if (pos < 0 || pos > n-1) {
        throw std::out_of_range("fuera del intervalo");
    } else {
        for (int i = pos; i < n; i++) {
            arr[i] = arr[i+1];
        }
        n--;
    }
    return r;

}

template <typename T>
T ListArray<T>::get(int pos) {
    if (pos < 0 || pos > n-1) {
        throw std::out_of_range("fuera del intervalo");
    } else {
        return arr[pos];
    }
}

template <typename T>
int ListArray<T>::search(T e) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == e) {
            return i;
        }
    }
    return -1;
}

template <typename T>
bool ListArray<T>::empty() {
    if (n > 0) {
        return false;
    } else {
        return true;
    }
}

template <typename T>
void ListArray<T>::resize(int new_size) {
    T* newArr = new T[new_size];
    for (int i = 0; i < n; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    max = new_size;
}