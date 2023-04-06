#include <iostream>
#include <chrono>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void Push(int x) {
        if (top >= MAX_SIZE - 1) {
            cout << "Error: stack overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void Pop() {
        if (top < 0) {
            cout << "Error: stack underflow\n";
            return;
        }
        top--;
    }

    int stackTop() {
        if (top < 0) {
            cout << "Error: stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top < 0;
    }

    bool isFull(){
        return top==MAX_SIZE;
    }

    void Display(){
        for(int i=0; i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    Stack s;
    
    auto start = chrono::steady_clock::now();
    s.Push(8);
    s.Push(10);
    s.Push(5);
    s.Push(11);
    s.Push(15);
    s.Push(23);
    s.Push(6);
    s.Push(18);
    s.Push(20);
    s.Push(17);
    s.Display();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Display();
    s.Push(4);
    s.Push(30);
    s.Push(3);
    s.Push(1);
    s.Display();

    auto end = chrono::steady_clock::now();
    auto time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count();


cout << time_taken <<"micro seconds"<< endl;
    
    return 0;
}
