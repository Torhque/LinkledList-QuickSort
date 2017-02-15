#include "QuickSort.h"

// Partition (split) the list and take the last element as the "pivot"
struct node *partition(struct node *head, struct node *end,
	struct node **newHead, struct node **newEnd)
{
	struct node *pivot = end;
	struct node *previous = NULL, *currentNode = head, *tail = pivot;

	// After partitioning (splitting), the head and the end of the list may change
	// so it will be updated with the newHead and newEnd variables
	while (currentNode != pivot)
	{
		if (currentNode -> data < pivot -> data)
		{
			// If the first node is less than the pivot 
			if ((*newHead) == NULL)
				// Then it becomes the new head
				(*newHead) = currentNode;

			previous = currentNode;
			currentNode = currentNode -> next;
		}
		else // If the current node is greater than pivot
		{
			// Move the current node to next of tail
			if (previous)
				previous->next = currentNode->next;
			struct node *tmp = currentNode->next;
			currentNode->next = NULL;
			tail->next = currentNode;
			tail = currentNode; // and change tail
			currentNode = tmp;
		}
	}

	// If the pivot data is the smallest value	
	if ((*newHead) == NULL)		
		(*newHead) = pivot; // then pivot becomes the head

	// Update newEnd to the current last node
	(*newEnd) = tail;

	// Return the pivot node
	return pivot;
}

struct node *quickSortRecur(struct node *head, struct node *end)
{
	// This is the base condition
	if (!head || head == end)
		return head;

	node *newHead = NULL, *newEnd = NULL;

	// Partition (split) the list, newHead and newEnd are updated by the partition function
	struct node *pivot = partition(head, end, &newHead, &newEnd);

	// If the pivot is the lowest value then no need to recur for the left partition
	if (newHead != pivot)
	{
		// Set the node before the pivot node as NULL
		struct node *temp = newHead;
		while (temp -> next != pivot)
			temp = temp -> next;
		temp -> next = NULL;

		// Recur for the list before pivot
		newHead = quickSortRecur(newHead, temp);

		// Change next of last node of the left half to pivot
		temp = getTail(newHead);
		temp -> next = pivot;
	}

	// Recur for the list after the pivot element
	pivot -> next = quickSortRecur(pivot -> next, newEnd);

	return newHead;
}

void QuickSort(struct node **headRef)
{
	(*headRef) = quickSortRecur(*headRef, getTail(*headRef));
	return;
}

int main()
{
	// pick random # within 1 - 100
	int num1 = rand() % 101;
	int num2 = rand() % 101;
	int num3 = rand() % 101;
	int num4 = rand() % 101;
	int num5 = rand() % 101;
	int num6 = rand() % 101;
	int num7 = rand() % 101;
	int num8 = rand() % 101;
	int num9 = rand() % 101;

	int num10 = rand() % 101;
	int num11 = rand() % 101;
	int num12 = rand() % 101;
	int num13 = rand() % 101;
	int num14 = rand() % 101;
	int num15 = rand() % 101;
	int num16 = rand() % 101;
	int num17 = rand() % 101;
	int num18 = rand() % 101;
	int num19 = rand() % 101;

	// Create a list that we'll populate later
	struct node *numList = NULL;

	// Populate the list with twenty integers
	push(&numList, num1);
	push(&numList, num2);
	push(&numList, num3);
	push(&numList, num4);
	push(&numList, num5);
	push(&numList, num6);
	push(&numList, num7);
	push(&numList, num8);
	push(&numList, num9);
	push(&numList, num10);
	push(&numList, num11);
	push(&numList, num12);
	push(&numList, num13);
	push(&numList, num14);
	push(&numList, num15);
	push(&numList, num16);
	push(&numList, num17);
	push(&numList, num18);
	push(&numList, num19);

	// Print the original list
	cout << "\nLinked List before being sorted\n";
	printList(numList);;

	// Call the QuickSort function
	QuickSort(&numList);

	cout << "\n";

	// Print the sorted list
	cout << "Linked List after\n";
	printList(numList);

	cout << "\n";

	system("pause");
	return 0;
}