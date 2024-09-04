// ���Ա� - ˳��ʵ�� - ��̬�����С
#include <stdio.h>
#include <stdlib.h>
#include "List.h"



// 1. ��ʼ��
void InitList(List* list) {
	list->data = (int *)malloc(InitSize * sizeof(int));

	if (list->data == NULL) {  // ����ڴ��Ƿ����ɹ�
		fprintf(stderr, "�ڴ����ʧ��\n");
		exit(1);
	}

	list->currentLength = 0;
	list->maxSize = InitSize;

	for (int i = 0; i < list -> maxSize; i++) {
		list->data[i] = 0;
	}
}


// 2. ˳�����չ ������ʼ�����Ŀռ䲻���õ�ʱ����Ҫ��˳��������������չ��
void ExpendList(List* list, int size) {
	// 1. ����һ���µ�ָ�룬ָ��ǰ��˳���
	int* p = list -> data;

	if (p == NULL) {
		fprintf(stderr, "����չ˳����ʱ��������һ������˳����ַΪ�գ�\n");
		exit(1);
	}

	// 2. �����µĿռ�
	list->data = (int*)malloc(sizeof(int) * (InitSize + size));
	if (list -> data == NULL) {
		fprintf(stderr, "����չ˳����ʱ��������һ������������չ�ڴ�ʧ�ܣ�\n");
		exit(1);
	}

	// 3. ��ԭ����ֵ�ƶ����µĿռ���
	list->maxSize = list->maxSize + size;
	for (int i = 0; i < list->currentLength; i++) {
		list->data[i] = p[i];
	}
}

// 2.5 ������ǰ˳���
void PrintList(List* list) {
	for (int i = 0; i < list->currentLength; i++) {
		printf("List[%d] = %d\n", i, list->data[i]);
	}
}

// 3. ��ֵ �������Ա������ֵ��Ĭ���������ӡ�
void AppendList(List* list, int value) {
	// �ж��Ƿ����
	if (list->currentLength >= list->maxSize) {
		fprintf(stderr, "�޷���˳���������µ�ֵ��˳���������\n");
		exit(1);
	}

	list->data[list->currentLength] = value;
	list->currentLength++;
}


// 4. ȡֵ ������λ�û�ȡ��Ӧ��ֵ��
int GetList(List* list, int index) {
	if (index >= list->currentLength) {
		fprintf(stderr, "�޷���ȡָ��λ�õ�Ԫ�أ�λ�ù���\n");
		exit(1);
	}
	else if (index < 0) {
		fprintf(stderr, "�޷���ȡָ��λ�õ�Ԫ�أ�λ�ù�С\n");
		exit(1);
	}

	int value = list->data[index];
	return value;
}


// 5. ��ֵ ����λ�ã���ֵ�����Ӧ��λ���С�
void InsertList(List* list, int index, int value) {
	// �ж�λ�õĺϷ���
	if (index > list->currentLength || index >= list->maxSize) {
		fprintf(stderr, "����λ�ù���\n");
		exit(1);
	}
	else if (index < 0) {
		fprintf(stderr, "����λ�ù�С\n");
		exit(1);
	}

	// ��������λ�ú����Ԫ�غ���
	for (int i = list->currentLength - 1; i >= index; i--) {
		list->data[i+1] = list->data[i];
	}

	list->data[index] = value;
	list->currentLength++;
}


// 6. ɾ��Ԫ�� ��ɾ��ָ��λ�õ�Ԫ�أ��������ǰ�ƶ���
void DeleteList(List* list, int index) {
	// �ж�λ�úϷ���
	if (index >= list->currentLength) {
		fprintf(stderr, "λ�ù���\n");
		exit(1);
	}
	else if (index < 0) {
		fprintf(stderr, "λ�ù�С\n");
		exit(1);
	}

	for (int i = index; i < list->currentLength; i++) {
		list->data[i] = list->data[i + 1];
	}

	list->currentLength--;

}


