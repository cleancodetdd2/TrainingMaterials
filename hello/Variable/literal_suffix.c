#include <stdio.h>

int main_t4()
{
	printf("0%lo\n", 017L);		// long ũ���� 8�� ���� ���ͷ� 
	printf("0%lo\n", 017UL);		// unsigned long ũ���� 8�� ���� ���ͷ�
	printf("0x%lX\n", 0x7FFFFFL);	// long ũ���� 16�� ���� ���ͷ� 
	printf("0x%lX\n", 0xFFFFFFUL);	// unsigned long ũ���� 16�� ���� ���ͷ� 
	return 0;
}