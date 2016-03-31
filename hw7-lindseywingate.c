#include <stdio.h>
#include <stdlib.h>

struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it. 
struct Node* get_new_node(int x) 
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at tail of Doubly linked list
void add(int x) {
	//head is head node  
	struct Node* temp = head;
	//pointer to new nodea
	struct Node* newNode = get_new_node(x);
	if(head == NULL) {
		//point to node
		head = newNode;
		return;
	}
	//temp is the pointer that moves around
	while(temp->next != NULL) 
		temp = temp->next; // go to last Node
	temp->next = newNode; //adds new node to end of list
	newNode->prev = temp; //links node back to list
}

void delete_node_perm(int num) {
	struct Node* temp = head;
	struct Node* temp2 = head;//use for reference for deleting nodes 
	if(temp==NULL)
		return;	
	if(temp->data==num) {
		head = temp->next;
		head->prev=NULL;
		free(temp);
		return;
	}
	while(temp->next!=NULL)	{
		if(temp->data==num) {
			temp2 = temp->prev;//node before temp
			temp2->next = temp->next;//node before temp points to node after temp
			temp->next = NULL;//temp is disconnected from next node
			temp->prev = NULL;//temp is disconnected from prev node
			free(temp);
			temp=temp2->next;//temp is reassigned to node after temp2
			temp->prev = temp2;//list is reconnected, goes full circle
			return;
		}
		if(temp->data!=num) {
			temp=temp->next;
		}
	}
	if(temp->next==NULL) {
		temp2 = temp->prev;
		temp2->next = NULL;
		temp->prev = NULL;
		free(temp);	
		return;	
	}
}

void delete_node_temp(int num) {
	struct Node* temp = head;
	struct Node* temp2 = head;//use for reference for deleting nodes 
	if(temp==NULL)
		return;	
	if(temp->data==num) {
		head = temp->next;
		head->prev=NULL;
		free(temp);
		return;
	}
	while(temp->next!=NULL)	{
		if(temp->data==num) {
			temp2 = temp->prev;//node before temp
			temp2->next = temp->next;//node before temp points to node after temp
			temp->next = NULL;//temp is disconnected from next node
			temp->prev = NULL;//temp is disconnected from prev node
			free(temp);
			temp=temp2->next;//temp is reassigned to node after temp2
			temp->prev = temp2;//list is reconnected, goes full circle
			return;
		}
		if(temp->data!=num) {
			temp=temp->next;
		}
	}
	if(temp->next==NULL) {
		temp2 = temp->prev;
		temp2->next = NULL;
		temp->prev = NULL;
		free(temp);	
		return;	
	}
}
//Prints all the elements in linked list in forward traversal order
void DISPLAY_INORDER() {
	struct Node* temp = head;
	if(temp==NULL) {
		return;
	}
	while(temp != NULL) {
		printf("Left to right output:	%d\n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order. 
void DISPLAY_POSTORDER() {
	struct Node* temp = head;
	if(temp == NULL)
		printf("None in list."); 
		return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	while(temp != NULL) {
		printf("Right to left output:	%d\n",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void FREE_INORDER() {	
	struct Node* temp = head;
	while(temp->next != NULL) {
		head = temp->next;
		temp->next=NULL;
		free(temp);		
		temp = head;
	}
	if(temp->next==NULL) {
		head=NULL;
		free(temp);	
	}
}

int length() {
	struct Node* temp = head;
	int count=0;
	if(temp==NULL)
		return 0;
	while(temp->next != NULL) {
		temp=temp->next;
		count++;
	}
	return count;
}


//*****************************************main********************************************//
int main(int num, char*arg[]) {
	if(num==2)
		printf("\nCommand line argument:	%s\n\n", arg[1]);
	else if(num>2)
		printf("Too many arguments supplied.\n");
	else
		printf("One argument expected.\n");

	head = NULL; // empty list. set head as NULL. 

	int n,i;
	int n2 = atoi(arg[1]);
	//add to list up until number n2, which is the command line input
	for(n=0; n<n2+1; n++)
	{
		add(n); 
		printf("Input Data:		%d\n",n);
	}
	DISPLAY_INORDER();	
	DISPLAY_POSTORDER();

	int del_node_num = rand() % n2 + 3;
	for(i=0; i<delete_me; i++) {
		int delete_node = (rand() % n2);
	}

	FREE_INORDER();
	DISPLAY_INORDER();
	printf("%d\n", length());
}
/* This code was written by Lindsey Wingate*/