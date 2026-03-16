#include<iostream>
using namespace std;

class Node {
public:
string title;
float price;
int edition;
int pages;
Node* next;

Node(string t, float p, int e, int pg) {  
    title = t;  
    price = p;  
    edition = e;  
    pages = pg;  
    next = NULL;  
}

};

class Stack {
Node* top;

public:
Stack() {
top = NULL;
}

//push function  
void push(string t, float p, int e, int pg) {  
    Node* newNode = new Node(t,p,e,pg);  

    newNode->next = top;  
    top = newNode;  
}  

//pop function  
void pop() {  
    if(top == NULL) {  
        cout<<"Stack Underflow\n";  
        return;  
    }  

    Node* temp = top;  
    top = top->next;  
    delete temp;  
}  

//peek function  
void peek() {  
    if(top == NULL) {  
        cout<<"Stack Empty\n";  
        return;  
    }  

    cout<<"\n---Top Book:\n";  
    cout<<"Title: "<<top->title<<endl;  
    cout<<"Price: "<<top->price<<endl;  
    cout<<"Edition: "<<top->edition<<endl;  
    cout<<"Pages: "<<top->pages<<endl;  
}  

//display function  
void display() {  
    Node* temp = top;  

    while(temp != NULL) {  
        cout<<"Title: "<<temp->title<<endl;  
        cout<<"Price: "<<temp->price<<endl;  
        cout<<"Edition: "<<temp->edition<<endl;  
        cout<<"Pages: "<<temp->pages<<endl;  
        cout<<"\n";  

        temp = temp->next;  
    }  
}

};

int main() {

Stack s;  

//push 5 books  
s.push("C++ Programming", 500, 3, 400);  
s.push("Data Structures", 650, 2, 350);  
s.push("Programming Fundamentals", 700, 1, 450);  
s.push("Discrete Structures", 600, 4, 500);  
s.push("Calculus", 550, 2, 300);  
  
//display the books in stack after pushing 5 books  
cout<<"---The original stack after pushing 5 books in stack:\n";  
s.display();  
//top element  
s.peek();  
//pop 2 books  
s.pop();  
s.pop();  
//display the books in stack after popping 2 books     
cout<<"\n---Remaining Books after popping 2 books from stack:\n";  
s.display();  

return 0;

}