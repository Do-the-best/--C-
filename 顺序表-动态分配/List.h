// 防止头文件被多次包含
#ifndef LIST_H
#define LIST_H


#define InitSize 5


typedef struct {
	int* data;  // 指向一块连续内存的首地址
	int maxSize;  // 顺序表的最大容量
	int currentLength;  // 顺序表的当前容量
} List;


void InitList(List* list);
void ExpendList(List* list, int size);
void PrintList(List* list);
void AppendList(List* list, int value);
int GetList(List* list, int index);
void InsertList(List* list, int index, int value);
void DeleteList(List* list, int index);

#endif
