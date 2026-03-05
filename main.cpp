//COMSC-210 | Lab 12 | Akashdeep Singh

#include <iostream>
using namespace std;

const int SIZE = 7;  
const int RANDOM_RANGE = 100;
const int INSERT_VALUE = 10000;

struct Node {
    float value;
    Node *next;
};

// adding required function prototypes 
void addFront(Node *&, float);
void addTail(Node *&, float);
void deleteNode(Node *&, int);
void insertNode(Node *&, int, float);
void deleteList(Node *&);
void output(Node *);

int main() {
    Node *head = nullptr;
    int entry;

    // create a linked list with random values
    for (int i = 0; i < SIZE; i++) {
        int value = rand() % RANDOM_RANGE;      //uses constant instead of 100
        addFront(head, value);                  //func replaces the old code block
    }
    
    output(head);

    // delete a node
    cout << "Which node would you like to delete?\n"; 
    cout << "Choice --> ";
    cin >> entry;
    
    //deletion logic moved to function
    
    deleteNode(head, entry);
    output(head);

   //insert node 
   cout << "After which node should " << INSERT_VALUE << " be inserted?\n";
   cout << "Choice --> ";
   cin >> entry;

   insertNode(head, entry, INSERT_VALUE);
   output(head);

   //delete entire list 
   deleteList(head);
   output(head);

    return 0;
}

// addFront() which adds a node to the start of the linked list 
//arguments: head pointer reference, value to insert
//returns: nothing 
void addFront(Node *& head, float value)
{
    Node * newNode = new Node;

    newNode->value = value;
    newNode->next = head;

    head = newNode;
}

//addTail() adds node to the end of the linked list
//arguments: head pointer reference, value to insert 
//returns: nothing 

void addTail(Node *& head, float value)
{
    Node * newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        return;
    }

    Node * current = head;

    while (current->next)
        current = current->next;

    current->next = newNode;

} 

//deleteNode() removes a node at a given position
// arguments: head pointer reference, position to delete
//returns: nothing 

void deleteNode(Node *& head, int position)
{
    if (!head)
        return;

    Node * current = head;
    Node * previous = nullptr;

    if (position == 1) {
        head = current->next;
        delete current;
        return;
    }

    for (int i = 1; current && i < position; i++) {
        previous = current;
        current = current->next;
    }

    if (current) {
        previous->next = current->next;
        delete current;
    }
} 

//insterNode() inserts a node after a given position
//arguments: head pointer reference, position, value

void insertNode(Node *& head, int position, float value)
{
    Node * current = head;

    for (int i = 1; current && i < position; i++)
        current = current->next;

    if (!current)
        return;

    Node * newNode = new Node;

    newNode->value = new Node;
    newNode->next = current->next;

    current->next = newNode;
} 

//deleteList() deletes the entire linked list
//arguments: head pointer reference
//returns nothing 

void deleteList(Node *& head)
{
    Node * current = head;

    while (current) {
        Node * temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
}
