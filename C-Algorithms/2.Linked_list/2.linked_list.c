#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node* next;
} Node;

Node* head;

void addFront(Node* root, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = root->next;
	root->next = node;
}

void removeFront(Node* root) {
	Node* front = root->next;
	root->next = front->next;
	free(front);
}

// ���� ����Ʈ ��ü �޸� ����
void freeAll(Node* root) {
	 Node* cur = head->next;
	 while (cur != NULL) {
		 Node* next = cur->next;
		 free(cur);
		 cur = next;
	 }
}

// ���� ����Ʈ ��ü ��� 
void showAll(Node* root) {
	Node* cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main()
{
	//head = (Node*)malloc(sizeof(Node));
	//Node* node1 = (Node*)malloc(sizeof(Node));
	//node1->data = 1;
	//Node* node2 = (Node*)malloc(sizeof(Node));
	//node2->data = 2;

	//head->next = node1;
	//node1->next = node2;
	//node2->next = NULL;		// ������ ����� next�� NULL

	//Node* cur = head->next;	// ù��° ������ ����
	//while (cur != NULL) {
	//	printf("%d ", cur->data);
	//	cur = cur->next;
	//}

	//addFront(head, 7);
	//cur = head->next;
	//printf("\n");
	//while (cur != NULL) {
	//	printf("%d ", cur->data);
	//	cur = cur->next;
	//}

	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	addFront(head, 2);
	addFront(head, 1);
	addFront(head, 7);
	addFront(head, 9);
	addFront(head, 8);
	showAll(head);
	printf("\n");

	removeFront(head);
	showAll(head);
	printf("\n");

	freeAll(head);

	return 0;
}