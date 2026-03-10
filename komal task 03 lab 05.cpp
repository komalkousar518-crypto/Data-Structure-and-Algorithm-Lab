#include <iostream>
using namespace std;

struct Player {
    string name;
    int score;
    Player* next;
    Player* prev;
};

Player* head = NULL;

// Add player in sorted order (ascending score)
void addPlayer(string name, int score) {

    Player* newNode = new Player();
    newNode->name = name;
    newNode->score = score;
    newNode->next = NULL;
    newNode->prev = NULL;

    // Insert at beginning
    if(head == NULL || score < head->score) {
        newNode->next = head;
        if(head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }

    Player* temp = head;

    while(temp->next != NULL && temp->next->score <= score)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete player by name
void deletePlayer(string name) {

    Player* temp = head;

    while(temp != NULL && temp->name != name)
        temp = temp->next;

    if(temp == NULL) {
        cout<<"Player not found\n";
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

// Display whole list
void display() {

    Player* temp = head;

    cout<<"\nPlayers List:\n";
    while(temp != NULL) {
        cout<<temp->name<<" - "<<temp->score<<endl;
        temp = temp->next;
    }
}

// Display lowest score player
void lowestScore() {

    if(head == NULL) {
        cout<<"List empty\n";
        return;
    }

    cout<<"\nPlayer with Lowest Score:\n";
    cout<<head->name<<" - "<<head->score<<endl;
}

// Display players with same score
void sameScore(int score) {

    Player* temp = head;

    cout<<"\nPlayers with score "<<score<<":\n";

    while(temp != NULL) {

        if(temp->score == score)
            cout<<temp->name<<" - "<<temp->score<<endl;

        temp = temp->next;
    }
}

// Display backward from given player
void backwardFrom(string name) {

    Player* temp = head;

    while(temp != NULL && temp->name != name)
        temp = temp->next;

    if(temp == NULL) {
        cout<<"Player not found\n";
        return;
    }

    cout<<"\nPlayers behind "<<name<<":\n";

    temp = temp->prev;

    while(temp != NULL) {
        cout<<temp->name<<" - "<<temp->score<<endl;
        temp = temp->prev;
    }
}

int main() {

    int choice, score;
    string name;

    do {

        cout<<"\n1 Add Player";
        cout<<"\n2 Delete Player";
        cout<<"\n3 Display All Players";
        cout<<"\n4 Show Lowest Score Player";
        cout<<"\n5 Show Players with Same Score";
        cout<<"\n6 Display Backward From Player";
        cout<<"\n7 Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice) {

        case 1:
            cout<<"Enter player name: ";
            cin>>name;
            cout<<"Enter score: ";
            cin>>score;
            addPlayer(name,score);
            break;

        case 2:
            cout<<"Enter player name to delete: ";
            cin>>name;
            deletePlayer(name);
            break;

        case 3:
            display();
            break;

        case 4:
            lowestScore();
            break;

        case 5:
            cout<<"Enter score: ";
            cin>>score;
            sameScore(score);
            break;

        case 6:
            cout<<"Enter player name: ";
            cin>>name;
            backwardFrom(name);
            break;

        }

    } while(choice != 7);
}