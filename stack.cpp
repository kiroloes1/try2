#include <iostream>
using namespace std;

template<typename T>
class stackWithLinkedList
{
private:
    struct node
    {
        T data;
        node* next;
    };
    node* top;

public:
    // Constructor
    stackWithLinkedList() {
        top = NULL;
    }

    // Push: Add element to top
    void push(T value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;

       
    }

    // Pop without returning value
    void pop() {
        if (isEmpty()) {
            cout << "The stack is empty." << endl;
            return;
        }
        node* temp = top;
        top = top->next;
        delete temp;
    }

    // Pop and return value
    void pop(T &element) {
        if (isEmpty()) {
            cout << "The stack is empty." << endl;
            return;
        }
        element = top->data;
        node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek top element
    T peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty.");
        }
        return top->data;
    }

    // Display all stack elements
    void display() {
        if (isEmpty()) {
            cout << "The stack is empty." << endl;
            return;
        }
        node* current = top;
        cout << "Stack elements (top to bottom):" << endl;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor
    ~stackWithLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }
};
