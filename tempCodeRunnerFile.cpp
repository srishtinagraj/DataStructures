#include <iostream>
using namespace std;
void push(char z[3], int i, char c)
{
    z[i] = c;
    i++;
}

void pop(char z[3], int i){
    if (i > 0) { 
        i--;
        z[i]=0;
    }
    else{
        cout<<"Stack is empty"<<endl;
    }
}

void peek(char z[3], int i){
    if (i > 0) { 
        cout << z[i-1] << endl;
    }
    else{
        cout<<"Stack is empty"<<endl;
    }
}

int main(){
    char array[3];
    int i = 0;
    push(array, i, 'a'); 
    push(array, i, 'b'); 
    push(array, i, 'c'); 
    peek(array, i);      
    pop(array, i);       
    peek(array, i);
    pop(array, i);
    pop(array, i);
    pop(array, i);      
}
