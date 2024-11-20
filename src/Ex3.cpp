#include <iostream>
#include "Ex.h"

bool detectLoop(Node* head)
{
	// Check if list is empty
	if (head == nullptr)
	{
		cout << "The list is empty";
		return false;
	}

	Node* fastPtr = head; // Fast pointer: Move 2 steps at a time
	Node* slowPtr = head; // Slow pointer: Move 1 step at a time
	do
	{
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;

		// Check if fast pointer move to end of list
		// If there is a loop in list, this condition will not meet and both pointers will run in a cycle
		// Every time fast pointer moves closer to slow pointer 1 node until they meet each other
		if (fastPtr == nullptr)
		{
			return false;
		}
	} while (fastPtr != slowPtr);

	return true;
}

void Ex_3()
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);

	// Create loop
	head->next->next->next->next = head;

	bool checkLoop = detectLoop(head);
	if (checkLoop)
	{
		cout << "Linked list has a loop";
	}
	else
	{
		cout << "Linked list has no loop";
	}
	getchar();
}
