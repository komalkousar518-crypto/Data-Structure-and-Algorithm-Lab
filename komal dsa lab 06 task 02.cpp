#include <iostream>
using namespace std;

struct Node{
    string name;
    Node* next;
};

Node* last = NULL;

void addEmployee(string name){

    Node* newNode = new Node();
    newNode->name = name;

    if(last == NULL){
        last = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    cout<<"Added successfully\n";
}

void searchEmployee(string name){

    if(last == NULL){
        cout<<"List empty\n";
        return;
    }

    Node* temp = last->next;

    do{
        if(temp->name == name){
            cout<<"Found successfully\n";
            return;
        }
        temp = temp->next;
    }while(temp != last->next);

    cout<<"Employee not found\n";
}

void deleteEmployee(string name){

    if(last == NULL){
        cout<<"List empty\n";
        return;
    }

    Node *curr = last->next, *prev = last;

    do{
        if(curr->name == name){

            if(curr == last && curr->next == last)
                last = NULL;
            else{
                prev->next = curr->next;

                if(curr == last)
                    last = prev;
            }

            delete curr;

            cout<<"Deleted successfully\n";
            return;
        }

        prev = curr;
        curr = curr->next;

    }while(curr != last->next);

    cout<<"Employee not found\n";
}

void updateEmployee(string oldName, string newName){

    if(last == NULL){
        cout<<"List empty\n";
        return;
    }

    Node* temp = last->next;

    do{
        if(temp->name == oldName){
            temp->name = newName;
            cout<<"Updated successfully\n";
            return;
        }

        temp = temp->next;

    }while(temp != last->next);

    cout<<"Employee not found\n";
}

void display(){

    if(last == NULL){
        cout<<"List empty\n";
        return;
    }

    Node* temp = last->next;

    do{
        cout<<temp->name<<" ";
        temp = temp->next;
    }while(temp != last->next);

    cout<<endl;
}

int main(){
    
    cout<<"---Adding 4 employees!---\n";
    addEmployee("komal");
    addEmployee("duaa");
    addEmployee("Bisma");
    addEmployee("zain");
    cout<<"\n";

    cout<<"---Displaying all employees in circular linked list:\n";
    display();
    cout<<"\n";

    cout<<"---Search employee zain by using search function in circular linked list:\n";
    searchEmployee("zain");
    cout<<"\n";
    
    cout<<"---Update employee Bisma with ayesha in circular linked list:\n";
    updateEmployee("Bisma","ayesha");
    display();
    cout<<"\n";

    cout<<"---Delete employee duaa in circular linked list:\n";
    deleteEmployee("duaa");
    display();
    cout<<"\n";

    return 0;
}