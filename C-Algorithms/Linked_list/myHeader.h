#pragma once

#include <stdio.h>
#include <stdlib.h>

// ��� ����ü ����
typedef struct Node {
	int value;			// ����� ��
	struct Node* next;	// ���� ��带 ����Ű�� ������ 
} Node;

// ���� ���� ����
extern Node* head;		// ����Ʈ�� ù��° ��带 ����Ű�� ������ 

// ���� ����Ʈ �Լ� ����
void insertFront(int data);			// �տ� ��� ���� 
void insertRear(int data);			// �ڿ� ��� ����
void insertAt(int data, int pos);	// Ư�� ��ġ�� ��� ����
void traverseList();				// ����Ʈ ��� 

void removeFront();					// ù��° ��� ���� 
void removeRear();					// ������ ��� ���� 
void removeAt(int pos);				// Ư�� ��ġ�� ��� ����
void removeByValue(int value);		// Ư�� ���� ��� ���� 
void getNodeCount();				// ��� ���� ��ȯ 
Node* search(int value);			// Ư�� �� �˻� 
void clearList();					// ��� ��� ���� 

// ��ƿ��Ƽ 
void clearBuffer();					// �Է� ���� ����
void removeNewLine();				// �ٹٲ� ���� ���� 




