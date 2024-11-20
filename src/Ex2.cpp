#include <iostream>
#include "Ex.h"

Node* findMax(Node* head)
{
	if (head == nullptr)
	{
		cout << "The list is empty";
	}

	Node* temp = head->next;
	Node* max = head;
	while (temp != nullptr)
	{
		if (temp->data > max->data)
		{
			max = temp;
		}
		temp = temp->next;
	}

	return max;
}

Node* findMin(Node* head)
{
	if (head == nullptr)
	{
		cout << "The list is empty";
	}

	Node* temp = head->next;
	Node* min = head;
	while (temp != nullptr)
	{
		if (temp->data < min->data)
		{
			min = temp;
		}
		temp = temp->next;
	}

	return min;
}

void Ex_2()
{
	Node* head = new Node(94);
	head = _addNodeToTail(head, 32);
	head = _addNodeToHead(head, 642);
	head = _addNodeToTail(head, 17);
	head = _addNodeToHead(head, 63);
	head = _addNodeToTail(head, 47);
	head = _addNodeToHead(head, 13);
	head = _addNodeToTail(head, 74);
	head = _addNodeToHead(head, 25);
	head = _addNodeToTail(head, 162);
	_printList(head);

	Node* max = findMax(head);
	cout << "Node have biggest data value is " << max->data << endl;

	Node* min = findMin(head);
	cout << "Node have smallest data value is " << min->data << endl;


	getchar();
}
