#include "List.h"
#include <stdio.h>


int main() {
	List L;
	InitList(&L);
	AppendList(&L, 10);
	AppendList(&L, 11);
	AppendList(&L, 12);
	AppendList(&L, 13);
	AppendList(&L, 14);

	printf("��չǰ�Ĳ�����\n");
	printf("˳������󳤶�Ϊ��%d\n", L.maxSize);
	printf("˳���ĵ�ǰ�̶�Ϊ��%d\n", L.currentLength);
	
	PrintList(&L);

	ExpendList(&L, 10);


	printf("��չ��Ĳ�����\n");
	printf("˳������󳤶�Ϊ��%d\n", L.maxSize);
	printf("˳���ĵ�ǰ�̶�Ϊ��%d\n", L.currentLength);

	int index = 0;
	// int value = 999;
	// InsertList(&L, index, value);

	PrintList(&L);

	printf("\n\n");
	DeleteList(&L, index);
	DeleteList(&L, index);
	PrintList(&L);

	return 0;
}