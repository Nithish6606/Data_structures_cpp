#include <iostream>
#define SIZE 100

class Stack {
  // This class implements the stack Data structure with all basic operations.
  // The stack is implemneted in Array.
private:
  char items[SIZE];
  int top;

public:
  Stack() { top = -1; }
  bool isEmpty() { return top == -1; }
  bool isFull() { return top == SIZE - 1; }
  void push(char x) {
    if (isFull()) {
      std::cout << "Stack is full" << std::endl;
    }
    items[++top] = x;
    std::cout << x << " is pushed into the stack" << std::endl;
  }

  char pop() {
    if (isEmpty()) {
      std::cout << "Stack is empty" << std::endl;
    }
    char popped = items[top--];
    std::cout << "Popped element: " << popped << std::endl;
    return popped;
  }

  // peek function
  char peek() {
    if (isEmpty()) {
      std::cout << "Stack is empty" << std::endl;
    }
    return items[top];
  }

  void displayStack() {
    std::cout << "Stack Representation:" << std::endl;
    int temp = top;
    while (temp != -1) {
      std::cout << "|_" << items[temp] << "_|" << std::endl;
      temp--;
    }
  }
};

class InfixToPostfix {
private:
  Stack stack;
  // Check for the operator precedence
  int precedence(char op) const {
    switch (op) {
    case '^':
      return 3;
    case '*':
    case '/':
      return 2;
    case '+':
    case '-':
      return 1;
    default:
      return 0;
    }
  }
  // Function to check for spaces
  bool isSpace(char c) const { return (c == ' ' || c == '\t'); }

public:
  // infix to postfix conversion
  std::string convert(const std::string &infix) {
    std::string postfix;
    for (char symbol : infix) {
      if (!isSpace(symbol)) {
        switch (symbol) {
        case '(':
          stack.push(symbol);
          stack.displayStack();
          break;
        case ')':
          while (!stack.isEmpty() && stack.peek() != '(') {
            postfix += stack.pop();
          }
          stack.pop();
          break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
          while (!stack.isEmpty() &&
                 precedence(stack.peek()) >= precedence(symbol)) {
            std::cout << "Popped " << stack.peek()
                      << " have higher or equal precedence than " << symbol
                      << "." << std::endl
                      << "Note:Always top of Stack is higher precedence than "
                         "the lower symbol."
                      << std::endl;
            postfix += stack.pop();
          }
          stack.push(symbol);
          stack.displayStack();
          break;
        default:
          postfix += symbol;
        }
      }
    }
    // Pop all remaining operators from the stack
    std::cout << "Popping remaining operators from the stack." << std::endl;
    while (!stack.isEmpty()) {
      postfix += stack.pop();
    }
    return postfix;
  }
};

int main() {
  std::string infix;
  std::cout << "Enter the infix expression[eg. a + b * c - d]:";
  std::getline(std::cin, infix);
  InfixToPostfix infix2postfix;
  std::string postfix = infix2postfix.convert(infix);
  std::cout << "Postfix expression: " << postfix << std::endl;
  return 0;
}