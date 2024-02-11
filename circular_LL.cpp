// circural queue using linked list
// front - dequeue r- enqueue
// takes O(1) time for enqueue and dequeue
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node *front = nullptr;
struct node *rear = nullptr;

void enqueue(int x){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = 0;
    if(rear == 0 && front == 0){
        front = rear = newNode;
        rear->next = front;
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

}
void display(){
    struct node *temp;
    if(front == 0 && rear == 0){
        cout<<"Empty queue"<<endl;
    }
    else{
        temp = front;
        while(temp->next != front){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
        }
    }
void dequeue(){
    struct node *temp;
    temp = front;
    if(front == 0 && rear == 0){
        cout<<"Empty queue"<<endl;
    }
    else if(front == rear){
        front = rear = 0;
        free(temp);
    }
    else {
        front = front -> next;
        rear -> next = front;
        free(temp);
    }
}

void peek(){
    if(front == nullptr && rear == nullptr){
        cout<<"Empty queue"<<endl;
    }
    else{
        cout<<"Peek: "<<front->data<<endl;
    }
}

int main(){
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    display();
    dequeue();
    peek();
}