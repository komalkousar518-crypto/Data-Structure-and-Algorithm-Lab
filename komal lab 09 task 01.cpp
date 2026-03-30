#include<iostream>
#define MAX 5
using namespace std;
class Queue {
private:
    int myqueue[MAX],front,rear;
public:
    Queue() {
        front=-1;
        rear=-1;
    }
    bool isFull() {
        if(rear==MAX-1)
            return true;
        return false;
    }
    bool isEmpty() {
        if(front==-1 || front>rear)
            return true;
        return false;
    }
    void enQueue(int value) {
        if(isFull()) {
            cout << "Queue is full!!" << endl;
        }
        else {
            if(front == -1) front = 0;
            rear++;
            myqueue[rear]=value;
            cout<<value<<" inserted"<<endl;
        }
    }
    void deQueue() {
        if (isEmpty()) {
            cout<<"Queue is empty!!"<<endl;
        }
        else {
            cout<<myqueue[front]<<"deleted"<<endl;
            front++;
        }
    }
    void displayQueue() {
        if(isEmpty()){
            cout<<"Queue is empty!!"<<endl;
        }
        else {
            cout<<"Queue: ";
            for(int i=front;i<=rear;i++)
                cout<<myqueue[i] << " ";
            cout<<endl;
        }
    }
};
int main() {
    Queue q;
    int choice, value;
    do {
        cout<<"\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch (choice) {
        case 1:
            cout<<"Enter value: ";
            cin>>value;
            q.enQueue(value);
            q.displayQueue(); 
            break;
        case 2:
            q.deQueue();
            q.displayQueue();   
            break;
        case 3:
            q.displayQueue();
            break;
        case 4:
            cout << "Exit\n";
            break;
        default:
            cout<<"Invalid choice\n";
        }
    } while (choice != 4);
    return 0;
}