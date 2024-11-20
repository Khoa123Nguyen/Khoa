#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node* next = NULL;

    Node();
    Node(int newValue);
};

void _printList(Node* n);

Node* _addNodeToTail(Node* head, int newValue);

Node* _addNodeToHead(Node* head, int newValue);

Node* _addBeforeNode(Node* head, int key, int newValue);

void _deleteHead(Node*& head);

void _deleteTail(Node*& head);

void _deleteAtPosition(Node*& head, int pos);

void Ex_1();
void Ex_2();
void Ex_3();
void Ex_4();
void Ex_5();
