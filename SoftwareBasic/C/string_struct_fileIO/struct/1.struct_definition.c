#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NAME_LEN 10
#define GENDER_LEN 5

//����ü ���� (�����ִ� �������� �������� ����)
struct student
{
	char name[NAME_LEN];
	int age;
	char gender[GENDER_LEN];
};

int main()
{
	// ����ü ���� ����(19����Ʈ)
	struct student st, st2;

	// ����ü ���� �ʱ�ȭ (����ü����.���)
	st.age = 24;
	//st.name = "�̼���";	//�ּҸ� �����϶�� �ǹ� 

	strcpy(st.name, "�̼���");		//���ڿ� ���� (���ڿ� ���ͷ� ������ �迭�� ����)
	strcpy(st.gender, "����");

	st2.age = 22;
	strcpy(st2.name, "������");
	strcpy(st2.gender, "����");

	printf("\n����� �̸��� %s�̸�, ������ %s�Դϴ�.\n", st.name, st.gender);
	printf("����� ���̴� %d�Դϴ�.\n", st.age);

	printf("\n����� �̸��� %s�̸�, ������ %s�Դϴ�.\n", st2.name, st2.gender);
	printf("����� ���̴� %d�Դϴ�.\n", st2.age);
	return 0;
}