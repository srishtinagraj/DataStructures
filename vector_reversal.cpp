#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class LinkedListStack {
private:
    Node<T>* head;
    int size;

public:
    LinkedListStack() : head(nullptr), size(0) {}

    ~LinkedListStack() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(T data) {
        Node<T>* newNode = new Node<T>{data, head};
        head = newNode;
        size++;
    }

    T pop() {
        if (head == nullptr) {
            throw std::runtime_error("Error: Stack is empty");
        }
        Node<T>* temp = head;
        T data = head->data;
        head = head->next;
        delete temp;
        size--;
        return data;
    }

    T peek() {
        if (head == nullptr) {
            throw std::runtime_error("Error: Stack is empty");
        }
        return head->data;
    }

    int getSize() const {
        return size;
    }
};

template <typename T>
void reverseVector(std::vector<T>& inputVector) {
    LinkedListStack<T> stack;
    // Push elements onto the stack
    for (const T& value : inputVector) {
        stack.push(value);
    }
    // Pop elements from the stack back into the vector to reverse it
    for (size_t i = 0; i < inputVector.size(); ++i) {
        inputVector[i] = stack.peek();
        stack.pop();
    }
}

int main() {
    LinkedListStack<int> stack;
    vector<int> vec = {1, 2, 3, 4};
    reverseVector(vec);
    cout << "Reversed vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
    vector<char> vect = {'a', 'd', 'w', 'o'};
    reverseVector(vect);
    cout << "Reversed vector: ";
    for (char c : vect) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
