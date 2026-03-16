#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* last = NULL;
//Insert node at beginning
void insertBefore(int value){
    Node* newNode = new Node();
    newNode->data = value;
    //If list is empty
    if(last == NULL){
        last = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->next = last->next;
        last->next = newNode;
    }
}

//Insert node at end
void insertAfter(int value){

    Node* newNode = new Node();
    newNode->data = value;

    if(last == NULL){
        last = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}
//Delete node
void deleteNode(int key){

    if(last == NULL){
        cout<<"List empty\n";
        return;
    }

    Node *curr = last->next;
    Node *prev = last;

    do{

        if(curr->data == key){

            // If only one node
            if(curr == last && curr->next == last){
                last = NULL;
            }
            else{
                prev->next = curr->next;

                // If deleting last node
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

    cout<<"Value not found\n";
}

// Display list
void display(){

    if(last == NULL){
        cout<<"List empty\n";
        return;
    }

    Node* temp = last->next;

    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != last->next);

    cout<<endl;
}

int main(){

    cout<<"Before adding nodes:\n";
    display();

    insertBefore(10);
    insertBefore(5);
    insertAfter(20);
    insertAfter(30);
    cout<<"\nAfter inserting nodes:\n";
    display();
    cout<<"\nDeleting node with value 20:\n";
    deleteNode(20);
    display();
    return 0;
}