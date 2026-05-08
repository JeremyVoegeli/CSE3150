#include <iostream>
#include <string>
#include <algorithm>
using std::cout, std::endl, std::string;

template<typename T, int SIZE>
class Queue {
private:
    T* front = new T[SIZE];
    T* back = front;
public:
    void enqueue(T val){
        *back = val;
        back++;
    }

    T dequeue(){
        T result = *front;

        for(T* p = front; p < back; p++){
            *p = *(p + 1);
        }

        back--;
        return result;
    }

    T peek(){
        return *front;
    }

    bool isEmpty(){
        return (front == back);
    }
};

template<int SIZE>
class Queue<string, SIZE>{
private:
    string* front = new string[SIZE];
    string* back = front;
public:
    void enqueue(string val){
        std::transform(val.begin(), val.end(), val.begin(), ::toupper);
        cout << "Emnqueuing [" << val << "]" << endl;
        *back = val;
        back++;
    }
};

int main(){
    Queue<int, 100> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    Queue<string, 50> q2;
    q2.enqueue("hello");
    q2.enqueue("world");
    return 0;
}