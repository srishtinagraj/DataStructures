#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *front = nullptr;
struct node *rear = nullptr;

void enqueue(int x){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = 0;
    if(front == 0 && rear == 0){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}
void display(){
    struct node *temp;
    if(front == 0 && rear == 0){
        cout<<"Empty Queue"<<endl;
    }
    else{
        temp = front;
        while(temp!=0){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
}
void dequeue(){
    struct node *temp;
    if(front == 0 && rear == 0){
        cout<<"Empty Queue"<<endl;
    }
    else{
        cout<<"Dequeued: "<<front->data<<endl;
        front = front->next;
        free(temp);
    }
}
void peek(){
    if(front == 0 && rear == 0){
        cout<<"Empty Queue"<<endl;
    }
    else{
        cout<<"Peek: "<<front->data<<endl;
    }

}
int main(){
    enqueue(5);
    enqueue(0);
    enqueue(-3);
    display();
    dequeue();
    peek();
}