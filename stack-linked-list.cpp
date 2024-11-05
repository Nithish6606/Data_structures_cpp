#include <iostream>

// class for Linked List node
class Node {
public:
  int data;                               // data of the node
  Node *next;                             // ptr to the next node
  Node(int x) : data(x), next(nullptr) {} // constructor Node(data).Eg. Node(5)
};

// class for stack implementation with basic operations.
class Stack {
private:
  Node *top; // ptr to the top of the stack
public:
  Stack() : top(nullptr) {} // init value of top is NULL

  void push(int data) {
    Node *newNode = new Node(data); // create a new node
    newNode->next = top;            // point the new node to the top
    top = newNode;                  // update the top to the new node
    std::cout << "Pushed :" << data << std::endl;
  }

  int pop() {
    if (top == nullptr) {
      std::cout << "Stack is Underflow" << std::endl;
      return -1;
    }
    int x = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return x;
  }

  void display() {
    std::cout << "List Representation of Stack:" << std::endl;
    Node *temp = top;
    while (temp != nullptr) {
      std::cout << "| " << temp->data << " |->";
      temp = temp->next;
    }
    std::cout << "| NULL |" << std::endl;
  }

  void displayStack() {
    std::cout << "Stack Representation:" << std::endl;
    Node *temp = top;
    while (temp != nullptr) {
      std::cout << "|_" << temp->data << "_|" << std::endl;
      temp = temp->next;
    }
  }

  ~Stack() {
    while (top != nullptr) {
      pop();
    }
  }
};

int main() {
  Stack stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(40);
  stack.push(50);
  stack.displayStack();
  std::cout << "Poped Element:" << stack.pop() << std::endl;
  stack.displayStack();
  stack.display();
  return 0;
}