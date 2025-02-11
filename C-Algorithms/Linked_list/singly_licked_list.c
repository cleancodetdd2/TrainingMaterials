#define _CRT_SECURE_NO_WARNINGS
#include "myHeader.h"

int main() {

	int choice, data, pos;

	while (1) {
		//메뉴 출력
		printf("\n--------------------------------\n");
		printf("\n 연결 리스트 메뉴(기능) \n");
		printf("\n--------------------------------\n");
		printf("1. 앞에 삽입\n ");
		printf("2. 뒤에 삽입\n ");
		printf("3. 특정 위치에 삽입\n");
		printf("4. 첫 번째 노드 삭제");
		printf("5. 마지막 노드 삭제");
		printf("6. 특정 위치의 노드 삭제\n");
		printf("7. 특정 값을 가진 노드 삭제\n");
		printf("8. 리스트 출력\n ");

		printf(" 0. 프로그램 종료\n");
		printf("\n--------------------------------\n");

		//사용자 입력 받기
		printf("메뉴 선택 : ");
		if (scanf("%d", &choice) != 1) {
			printf("잘못된 입력입니다. 숫자를 입력하세요.\n");
			clearBuffer();
			continue;
		}

		//clearBuffer();

		switch (choice) {
		case 1:		// 리스트 앞에 삽입
			printf("삽입할 값 입력 : ");
			if (scanf("%d", &data) != 1) {
				printf("잘못된 입력입니다. 숫자를 입력하세요.\n");
				clearBuffer();
				break;
			}
			//clearBuffer();
			insertFront(data);
			printf("노드가 리스트 맨앞에 삽입되었습니다.\n");
			break;

		case 8:		// 리스트 출력
			traverseList();
			break;

		case 0:
			clearList();		// 프로그램 종료 전 메모리 누수 방지
			printf("프로그램을 종료합니다.\n");
			return 0;

		default:
			printf("잘못된 입력입니다. 메뉴에 있는 번호를 입력하세요.\n");
		}

	}

	//return 0;
}