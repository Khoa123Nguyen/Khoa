#include <iostream>
#include "Ex.h"
using namespace std;

Node::Node(int newValue)
{
    data = newValue;
}

void _printList(Node* n)
{
    while (n != nullptr)
    {
        cout << n->data << " -> ";
        n = n->next;
    }
    cout << endl;
}

Node* _addNodeToTail(Node* head, int newValue)
{
    Node* newNode = new Node(newValue);

    // If the list is empty make new node as the head and return
    if (head == nullptr)
    {
        return newNode;
    }

    // Traverse till the last node
    Node* last = head;
    while (last->next != nullptr)
    {
        last = last->next;
    }

    last->next = newNode;
    return head;
}

Node* _addNodeToHead(Node* head, int newValue)
{
    // Create new node with given data
    Node* newNode = new Node(newValue);

    // Make next of the new node to the current head
    newNode->next = head;

    // Return new node as head of the list
    return newNode;
}

Node* _addBeforeNode(Node* head, int key, int newValue)
{
    // If list is empty
    if (head == nullptr)
    {
        cout << "The list is empty";
        return nullptr;
    }

    // If key is at the head
    if (head->data == key)
    {
        Node* newNode = new Node(newValue);
        newNode->next = head;
        return newNode;
    }

    // Initialize current and previous pointers
    Node* current = head;
    Node* previous = nullptr;

    // Traverse the list to find the key
    while (current != nullptr && current->data != key)
    {
        previous = current;
        current = current->next;
    }

    if (current != nullptr)
    {
        Node* newNode = new Node(newValue);
        previous->next = newNode;
        newNode->next = current;
    }

    return head;
}

void _deleteHead(Node*& head)
{
    if (head == nullptr)
    {
        cout << "The list is empty";
        return;
    }

    // Store current head in a temporary variable
    Node* temp = head;

    // Move head to next node
    head = head->next;

    // Delete the old head node
    delete(temp);
}

void _deleteTail(Node*& head)
{
    // Check if list is empty
    if (head == nullptr)
    {
        cout << "The list is empty";
        return;
    }

    // Chech if list contains only one element
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    // Tranverse to the tail node
    Node* temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void _deleteAtPosition(Node*& head, int pos)
{
    if (head == nullptr || pos < 0)
    {
        cout << "Invalid position or list is empty";
        return;
    }

    // Delete head node
    if (pos == 0)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Traverse to the node before the target position
    Node* current = head;
    for (int i = 0; i < pos - 1 && current != nullptr; i++)
    {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr)
    {
        cout << "Position exceeds list length." << endl;
        return;
    }

    // Delete node
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void Ex_1()
{
    Node* head = new Node(1);
    _printList(head);
    head = _addNodeToHead(head, 6);
    _printList(head);
    head = _addNodeToTail(head, 4);
    _printList(head);
    head = _addBeforeNode(head, 1, 10);
    head = _addBeforeNode(head, 1, 12);
    _printList(head);

    getchar();
}
