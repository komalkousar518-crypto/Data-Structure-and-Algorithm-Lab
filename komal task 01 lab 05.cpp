#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* head = NULL;
// Insert at beginning
void addBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if(head != NULL)
        head->prev = newNode;
    head = newNode;
	}

// Insert after value 45
void addAfter45(int val) {
    Node* temp = head;

    while(temp != NULL && temp->data != 45)
        temp = temp->next;

    if(temp == NULL) {
        cout<<"45 not found\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = val;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete beginning
void deleteBeginning() {
    if(head == NULL) {
        cout<<"List empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete node after 45
void deleteAfter45() {
    Node* temp = head;

    while(temp != NULL && temp->data != 45)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL) {
        cout<<"Deletion not possible\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;

    if(del->next != NULL)
        del->next->prev = temp;

    delete del;
}

// Display list
void display() {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

int main() {

    int n, val;

    cout<<"Enter number of marks: ";
    cin>>n;

    for(int i=0;i<n;i++) {
        cin>>val;
        addBeginning(val);
    }

    cout<<"List: ";
    display();

    cout<<"Enter value to insert after 45: ";
    cin>>val;
    addAfter45(val);

    display();

    deleteBeginning();
    cout<<"After deleting beginning:\n";
    display();

    deleteAfter45();
    cout<<"After deleting node after 45:\n";
    display();

}