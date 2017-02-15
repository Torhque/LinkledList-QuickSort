#pragma once
#include <iostream>
#include <cstdio>
#include <time.h>
using namespace std;

// A node of the singly linked list
struct node
{
	int data;
	struct node *next;
};

// A utility function for inserting a node at the beginning of linked list
void push(struct node** head_ref, int new_data)
{
	// Allocate a node
	struct node* new_node = new node;

	// Put in the data
	new_node -> data = new_data;

	// Link the old list off the new node
	new_node->next = (*head_ref);

	// Move the head to point to the new node
	(*head_ref) = new_node;
}

// A utility function for printing linked list
void printList(struct node *node)
{
	while (node != NULL)
	{
		printf("%d  ", node->data);
		node = node->next;
	}
	printf("\n");
}

// Returns the last node of the list
struct node *getTail(struct node *cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}