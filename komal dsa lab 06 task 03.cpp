#include <iostream>
using namespace std;

class Book{
private:
    string bookId;
    string bookName;
    double bookPrice;
    string bookAuthor;
    string bookISBN;

public:
    Book(){}

    Book(string id,string name,double price,string author,string isbn){
        bookId=id;
        bookName=name;
        bookPrice=price;
        bookAuthor=author;
        bookISBN=isbn;
    }

    string getId(){ return bookId; }
    string getName(){ return bookName; }
    double getPrice(){ return bookPrice; }
    string getAuthor(){ return bookAuthor; }
    string getISBN(){ return bookISBN; }

    void setBook(string id,string name,double price,string author,string isbn){
        bookId=id;
        bookName=name;
        bookPrice=price;
        bookAuthor=author;
        bookISBN=isbn;
    }
};

class Node{
public:
    Book book;
    Node* next;
    Node* prev;

    Node(Book b){
        book=b;
        next=NULL;
        prev=NULL;
    }
};

class BookList{

    Node* head=NULL;

public:

    void addBook(string id,string name,double price,string author,string isbn){

        Book b(id,name,price,author,isbn);
        Node* newNode=new Node(b);

        if(head==NULL){
            head=newNode;
            head->next=head;
            head->prev=head;
        }
        else{
            Node* last=head->prev;

            last->next=newNode;
            newNode->prev=last;

            newNode->next=head;
            head->prev=newNode;
        }
    }

    void removeBook(string id){

        if(head==NULL){
            cout<<"List empty\n";
            return;
        }

        Node* temp=head;

        do{

            if(temp->book.getId()==id){

                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;

                if(temp==head)
                    head=temp->next;

                delete temp;

                cout<<"Book deleted\n";
                return;
            }

            temp=temp->next;

        }while(temp!=head);

        cout<<"Book ID not found\n";
    }

    void updateBook(string id,string name,double price,string author,string isbn){

        Node* temp=head;

        if(head==NULL)
            return;

        do{

            if(temp->book.getId()==id){

                temp->book.setBook(id,name,price,author,isbn);

                cout<<"Book updated\n";
                return;
            }

            temp=temp->next;

        }while(temp!=head);

        cout<<"Book not found\n";
    }

    void printBooks(){

        if(head==NULL){
            cout<<"Empty\n";
            return;
        }

        Node* temp=head;

        do{

            cout<<temp->book.getId()<<" "
                <<temp->book.getName()<<" "
                <<temp->book.getPrice()<<" "
                <<temp->book.getAuthor()<<" "
                <<temp->book.getISBN()<<endl;

            temp=temp->next;

        }while(temp!=head);
    }

    void printBook(string id){

        Node* temp=head;

        if(head==NULL)
            return;

        do{

            if(temp->book.getId()==id){

                cout<<temp->book.getName()<<" "
                    <<temp->book.getPrice()<<" "
                    <<temp->book.getAuthor()<<endl;

                return;
            }

            temp=temp->next;

        }while(temp!=head);

        cout<<"Book not found\n";
    }
};

int main(){

    BookList list;
    
    cout<<"---Add 10 books data\n";
    list.addBook("B1","DS",500,"Ali","111");
    list.addBook("B2","OOP",600,"Ahmed","222");
    list.addBook("B3","DB",700,"zara","333");
    list.addBook("B4","OS",800,"Zain","444");
    list.addBook("B5","AI",900,"Ayesha","555");
    list.addBook("B6","ML",650,"duaa","666");
    list.addBook("B7","CN",550,"Usman","777");
    list.addBook("B8","SE",750,"bisma","888");
    list.addBook("B9","Algo",850,"adan","999");
    list.addBook("B10","Math",400,"Noor","101");

    cout<<"\n";
    cout<<"---All Books Data---\n";
    list.printBooks();
    cout<<"\n";

    cout<<"---Remove books data by ID (removed ID:B2 AND X1)\n";
    list.removeBook("B2");
    list.removeBook("X1");
    cout<<"For X1 it shows error message!\n";

    cout<<"\n";
    cout<<"---After removing Book ID:B2 linked list is:\n";
    list.printBooks();
    cout<<"\n";

    cout<<"---Update Book B3 data:\n";
    list.updateBook("B3","Database",987,"zara","333");
    list.printBook("B3");

}