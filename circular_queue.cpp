#include <iostream>
#include <stdlib.h>

using namespace std;

#define N 5
int queue[N];
int front = -1;
int rear = -1;

// if rear is at the end of the queue (N-1), then the queue is full
// this leads to wastage of space in linear queue
// (rear+1)%N == front means queue is full

void enqueue (int x){
    if(front==-1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else if((rear+1)%N == front){
        cout<<"Queue is full"<<endl;
    }
    else{
        rear = (rear+1)%N;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        cout<<"Queue is empty"<<endl;
    }
    else if (front == rear) // only one element in queue
    {
        cout<<"Dequeued element is: "<<queue[front]<<endl;
        front = rear = -1;
    }
    else {
        cout<<"Dequeued element is:"<<queue[front]<<endl;
        front = (front+1)%N;
    }
}

void display(){
    if (front == -1 && rear == -1){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is: "<<endl;
        int i = front;
        while(i!=rear){
            cout<<queue[i];
            i = (i+1)%N;
        }
        cout<<queue[rear]<<endl;
    }
}
int main(){
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
    enqueue(27);
    display();
    enqueue(37);
    enqueue(74);
}
