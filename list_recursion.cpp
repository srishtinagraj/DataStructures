#include <iostream>
using namespace std;

// Definition of the node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print linked list recursively
void printListRecursively(Node* head) {
    if (head == nullptr) { // Base case: end of the list
        return;
    }
    cout << head->data << " "; // Print the current node's data
    printListRecursively(head->next); // Recursive call with the next node
}

// Utility function to add a new node at the end of the list
void append(Node** head_ref, int new_data) {
    // Allocate new node
    Node* new_node = new Node(new_data);
    
    // Used in case the list is empty
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    
    // Find the last node
    Node* last = *head_ref;
    while (last->next != nullptr) {
        last = last->next;
    }
    
    // Change the next of last node
    last->next = new_node;
}

int main() {
    Node* head = nullptr;
    
    // Create a simple list 1->2->3->4
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    
    // Print the list
    printListRecursively(head);
    
    return 0;
}