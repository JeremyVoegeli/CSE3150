#include <iostream>
#include <concepts>
using std::cout, std::endl;

template <typename T>
concept Sortable = requires (T a, T b){
    {a < b} -> std::convertible_to<bool>;
    {a > b} -> std::convertible_to<bool>;
    {a == b} -> std::convertible_to<bool>;
    {cout << a};
};

template <Sortable T, int SIZE>
class SortedList {
private:
    T* arr = new T[SIZE];
    int length = 0;
public:
    SortedList(){
        cout << "This is the constructor" << endl;
    }
    ~SortedList(){
        delete[] arr;
        cout << "This is the destructor" << endl;
    }

    void insert(T val){
        if(length == 0){
            *(arr) = val;
        } else {
            for(int i = 0; i < length; i++){
                if(*(arr + i) > val){
                    T temp = *(arr + i);
                    *(arr + i) = val;
                    val = temp;
                }
            }  
            *(arr + length) = val;
        }
        
        length++;
    }

    void remove(T val){
        int i = 0;
        while(*(arr + i) != val){i++;}

        for(int j = i; j < length; j++){
            *(arr + j) = *(arr + j + 1);
        }
        length--;
    }

    void print(){
        for(int i = 0; i < length; i++){
            cout << *(arr + i) << endl;
        }
    }
};

int main(){
    SortedList<int, 100> l;

    l.insert(4);
    l.insert(2);
    l.insert(16);
    l.print();

    return 0;
}