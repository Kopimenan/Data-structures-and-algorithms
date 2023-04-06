#include <iostream>
#include<chrono>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void Push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    void Pop() {
        if (top == nullptr) {
            cout << "Error: stack underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int StackTop() {
        if (top == nullptr) {
            cout << "Error: stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void Display(){
        Node* iter;
        iter=top;
        while(iter!=nullptr){
            cout<<iter->data<<" ";
            iter=iter->next;
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
