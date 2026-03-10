#include <iostream>
using namespace std;
struct Node
{
    float rain;
    Node*prev;
    Node*next;
};
Node*head=NULL;
void insert(float val)
{
    if(val<0)
	{
        cout<<"Negative values not allowed\n";
        return;
    }

    Node*newNode=new Node();
    newNode->rain=val;
    newNode->next=NULL;

    if(head==NULL)
	{
        newNode->prev=NULL;
        head=newNode;
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}
void display()
{
    Node*temp=head;
    float total=0;
    int count=0;
    float max=head->rain;
    float min=head->rain;
    while(temp!=NULL)
	{
        total+=temp->rain;
        if(temp->rain > max)max=temp->rain;
        if(temp->rain < min)min=temp->rain;

        count++;
        temp=temp->next;
    }
    cout<<"Total Rainfall: "<<total<<endl;
    cout<<"Average Rainfall: "<<total/count<<endl;
    cout<<"Highest: "<<max<<endl;
    cout<<"Lowest: "<<min<<endl;

    temp = head;
    for(int i=1;i<=5;i++)
        temp = temp->next;
    if(temp !=NULL)
        cout<<"Rainfall after 5th day: "<<temp->rain<<endl;
}
int main(){
    float x;
    cout<<"Enter rainfall for 7 days\n";
    for(int i=0;i<7;i++){
        cin>>x;
        insert(x);
    }
    display();
}