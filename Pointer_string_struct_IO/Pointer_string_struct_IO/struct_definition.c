#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		// ���ڿ��� ���õ� �������(strcpy)

#define NAME_LENGTH	10
#define GRADE_LENGTH 6

//����ü ���� => �������� �������� ���� => ����� ���� �ڷ��� ����
struct student
{
	char name[NAME_LENGTH];
	int age;
	char grade[GRADE_LENGTH];
};

int main()
{
	// ����ü ���� ����(20����Ʈ)
	struct student st1, st2;

	// ����ü ���� �ʱ�ȭ 
	// ����ü����.��� 
	st1.age = 25;
	//st1.name = "�̼���";		//�ּҸ� �����ؾ� �� 
	strcpy(st1.name, "�̼���"); //���ڿ� ����. strcpy()�� ���ڿ� ���ͷ��� ������ �迭�� ������. 
	strcpy(st1.grade, "1�г�"); //"1�г�"��� ���ڿ� ���ͷ��� ������ st1.grade �迭 �޸� ������.

	st2.age = 28;
	strcpy(st2.name, "�Ż��Ӵ�");
	strcpy(st2.grade, "2�г�");

	printf("\n����� �̸��� %s�̸�, �г��� %s�Դϴ�.\n", st1.name, st1.grade);
	printf("����� ���̴� %d�Դϴ�.\n", st1.age);

	printf("\n����� �̸��� %s�̸�, �г��� %s�Դϴ�.\n", st2.name, st2.grade);
	printf("����� ���̴� %d�Դϴ�.\n", st2.age);
	
	return 0;
}