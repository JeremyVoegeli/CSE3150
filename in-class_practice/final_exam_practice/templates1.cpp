#include <iostream>
using std::cout, std::endl;

template <typename T, int SIZE>
class Stack{
private:
    T* arr = new T[SIZE];
    int top = 0;
public:
    ~Stack(){
        delete[] arr;
    }

    void push(T val){
        *(arr + top)= val;
        top++;
    }

    T pop(){
        top--;
        T popped = *(arr + top);
        return popped;
    }

    T peek(){
        return *(arr + top - 1);
    }

    bool isEmpty(){
        return (top == 0);
    }
};

template <int SIZE>
class Stack<bool, SIZE> {
public:
    void push(bool val){
        cout << "Pushing true/false" << endl;
    }
};

int main(){
    Stack<int, 100> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << s1.pop() << s1.pop() << s1.pop() << endl;

    Stack<bool, 50> s2;
    s2.push(true);
    s2.push(false);

    return 0;
}