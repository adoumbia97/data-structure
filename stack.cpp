/* C++ program to implement basic stack
   operations */
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 2
 
class Stack {
    int top;
 
public:
    int *a; // Maximum size of Stack
 
    Stack(int max);
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    void printall();
};
 Stack::Stack(int max)
 { 
    top = -1; 
    a=new int(max);
 }
 
bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Warning!!!!! Stack Overflow \n";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}
 
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        top=top-1;
        return top;
    }
}
int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}
 
bool Stack::isEmpty()
{
    return (top < 0);
}
void Stack::printall()
{
    cout << "Voici les items de la liste \n";
    for (int i = 0; i <= top; ++i)
    {
        /* code */

        cout << a[i] << "\n";
    }
}
 
// Driver program to test above functions
int stackManager()
{
    int sizeOfStack;
    cout <<"Enter the size of the stack\n";
    cin >>sizeOfStack;

    class Stack s(sizeOfStack);
    int choice;
    bool insideStack;
    insideStack=true;
    cout << "--------------------Welcome to the new program of stack -------------------------\n" ;
    cout << "1- Insert in the stack \n";
    cout << "2- Remove from the stack \n";
    cout << "3- Afficher le stack \n";
    cout << "5- Check if the stack is full \n";
    do
    {
        cout<< "Enter your choice\n";
        cin >> choice;

        switch(choice)
        {
            default:
                insideStack=false;
                break;
            
            case 4:
                cout <<" Is the stack empty ?" << s.isEmpty();
                break;
            case 3 :
                s.printall();
                break;
            case 2 :
                s.pop();
                break;
            case 1 :
                cout <<" Enter the item you want to add \n";
                int eltToAdd;
                cin >> eltToAdd;
                s.push(eltToAdd);
                break;
            
            
        }
        /* code */
    } while (insideStack==true);

    return 0;
}

            
    
/*
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
    s.printall();
 
    return 0;

    */
