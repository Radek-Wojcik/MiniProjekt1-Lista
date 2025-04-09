#include <iostream>

template <typename T>
class DynamicArray {
private:
    T* array;        
    int capacity;    
    int length;      

public:
    // Deklaracja konstruktora i destruktora
    DynamicArray(int initCapacity = 10);
    ~DynamicArray();

    // Deklaracja metody dodającej element
    void push_back(const T& value);

    // Deklaracja operatora umożliwiającego dostęp przez indeks
    T& operator[](int index);

    // Deklaracja metod pomocniczych
    int size() const;
    int getCapacity() const;
};
