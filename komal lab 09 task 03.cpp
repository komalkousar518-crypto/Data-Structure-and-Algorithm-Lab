#include<iostream>
#define MAX 5
using namespace std;
class Queue {
private:
    int myqueue[MAX], front, rear;
public:
    Queue() {
        front= -1;
        rear= -1;
    }
    void enQueue(int value) {
        if(rear == MAX - 1) {
            cout<<"Overflow"<<endl;
        }
        else {
            if (front == -1) front=0;
            rear++;
            myqueue[rear]=value;
        }
    }
    int count() {
        if(front==-1)
            return 0;
        return (rear -front + 1);
    }
    void displayQueue() {
        if(front == -1) {
            cout<<"Queue is empty"<<endl;
        }
        else{
            for(int i=front; i <= rear; i++)
                cout<<myqueue[i]<< " ";
            cout<<endl;
        }
    }
};
int main() {
    Queue q;
   q.enQueue(23);
    q.enQueue(24);
    q.enQueue(37);
    q.displayQueue();
    cout<<"Total elements: "<<q.count()<<endl;
    return 0;
}