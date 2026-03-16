#include<iostream>
using namespace std;

class Inventory {
public:
    int serialNum;
    int year;
    int lotNum;

    void input() {
        cout<<"Enter Serial Number: ";
        cin>>serialNum;

        cout<<"Enter Manufacture Year: ";
        cin>>year;

        cout<<"Enter Lot Number: ";
        cin>>lotNum;
    }

    void display() {
        cout<<"Serial Number: "<<serialNum<<endl;
        cout<<"Manufacture Year: "<<year<<endl;
        cout<<"Lot Number: "<<lotNum<<endl;
        cout<<"---------------------"<<endl;
    }
};

class Node {
public:
    Inventory data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(Inventory item) {
        Node* newNode = new Node;

        newNode->data = item;
        newNode->next = top;
        top = newNode;

        cout<<"Part Added Successfully\n";
    }

    void pop() {
        if(top == NULL) {
            cout<<"Stack Empty\n";
            return;
        }

        Node* temp = top;

        cout<<"\nRemoved Part:\n";
        temp->data.display();

        top = top->next;
        delete temp;
    }

    void display() {
        if(top == NULL) {
            cout<<"Inventory Empty\n";
            return;
        }

        Node* temp = top;

        cout<<"\nInventory Parts:\n";

        while(temp != NULL) {
            temp->data.display();
            temp = temp->next;
        }
    }
};

int main() {

    Stack s;
    int choice;

    do {
        cout<<"\n1 Add Part\n";
        cout<<"2 Remove Part\n";
        cout<<"3 Show Inventory\n";
        cout<<"4 Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;

        if(choice == 1) {
            Inventory item;
            item.input();
            s.push(item);
        }

        else if(choice == 2) {
            s.pop();
        }

        else if(choice == 3) {
            s.display();
        }

    } while(choice != 4);

    cout<<"\nProgram Ended\n";
    s.display();

    return 0;
}