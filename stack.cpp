#include<iostream>
#define MAX 5
using namespace std;

class stack{
    //This class implements the stack Data structure with all basic operations.
    //The stack is implemneted in Array.
    private:
        int items[MAX];
        int top;
    public:
        stack(){
            top=-1;
        }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==MAX-1;
    }
    void push(int x){
        if(isFull()){
            cout<<"Stack is full"<<endl;
        }
        items[++top]=x;
        cout<<x<<" is pushed into the stack"<<endl;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return items[top--];
    }

    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return items[top];
    
    }
};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.pop()<<" is popped from the stack"<<endl;
    cout<<s.peek()<<" is the top element of the stack"<<endl;
    return 0;
}