#include <iostream>

using namespace std;

template <typename T>
class DynamicArray {
private:
    T* array;
    int capacity;
    int length;

    // Metoda powiększająca tablice
    void resize() {
        capacity *= 2;                                    // Podwojenie pojemności
        T* newArray = new T[capacity];                    // Nowa tablica o zwiększonej pojemności

        // Kopiowanie elementów do nowej tablicy
        for (int i = 0; i < length; ++i) {
            newArray[i] = array[i];
        }

        delete[] array;                                   // Zwolnienie pamięci starej tablicy
        array = newArray;                                 // Przypisanie wskaźnika do nowej tablicy
    }

public:
    // Konstruktor
    DynamicArray(int initCapacity = 10)
        : capacity(initCapacity), length(0)
    {
        array = new T[capacity];
    }

    // Destruktor
    ~DynamicArray() {
        delete[] array;
    }

    // Metoda dodająca element
    void push_back(const T& value);
    if (length == capacity) {                            // Sprawdzenie, czy tablica jest pełna
        resize();
    }
    array[length++] = value;                             // Dodanie elementu i zwiększenie licznika

    // Zabezpieczenie przed odowłaniem do elementu spoza zakresu
    T& operator[](int index) {
        if (index < 0 || index >= length) {              // Sprawdzenie, czy indeks mieści się w zakresie
            cerr << "Indeks poza zakresem!" << endl;     // Błąd krytyczny, zakończenie progrsamu
            exit(EXIT_FAILURE);
        }
        return array[index];
    }

    // Deklaracja metod pomocniczych
    int size() const;
    int getCapacity() const;
};

int main() {
    // Testowanie poprawności inicjalizacji i zwolnienia pamięci
    DynamicArray<int> arr(5);
    return 0;
}