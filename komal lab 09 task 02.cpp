#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
class Queue {
    Node *front,*rear;
public:
    Queue() {
        front=rear=NULL;
    }
    void insert(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = NULL;
        if (rear == NULL) {
            front=rear=temp;
        } else {
            rear->next=temp;
            rear=temp;
        }
        cout<<value<<" inserted\n";
    }
    void deleteFront() {
        if(front == NULL) {
            cout<<"Queue Underflow\n";
            return;
        }

        Node*temp=front;
        cout<<front->data<<" deleted\n";
        front =front->next;
        if(front==NULL)
            rear=NULL;
        delete temp;
    }
    void display() {
        if(front == NULL) {
            cout<<"Queue is empty\n";
            return;
        }
       Node*temp=front;
        while(temp != NULL) {
            cout<<temp->data <<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main() {
    Queue q;
    q.insert(200);
    q.insert(34);
    q.insert(62);
    q.display();
    q.deleteFront();
    q.display();
    return 0;
}