// ��ֹͷ�ļ�����ΰ���
#ifndef LIST_H
#define LIST_H


#define InitSize 5


typedef struct {
	int* data;  // ָ��һ�������ڴ���׵�ַ
	int maxSize;  // ˳�����������
	int currentLength;  // ˳���ĵ�ǰ����
} List;


void InitList(List* list);
void ExpendList(List* list, int size);
void PrintList(List* list);
void AppendList(List* list, int value);
int GetList(List* list, int index);
void InsertList(List* list, int index, int value);
void DeleteList(List* list, int index);

#endif
