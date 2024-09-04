// 线性表 - 顺序实现 - 动态分配大小
#include <stdio.h>
#include <stdlib.h>
#include "List.h"



// 1. 初始化
void InitList(List* list) {
	list->data = (int *)malloc(InitSize * sizeof(int));

	if (list->data == NULL) {  // 检查内存是否分配成功
		fprintf(stderr, "内存分配失败\n");
		exit(1);
	}

	list->currentLength = 0;
	list->maxSize = InitSize;

	for (int i = 0; i < list -> maxSize; i++) {
		list->data[i] = 0;
	}
}


// 2. 顺序表扩展 【当初始化给的空间不够用的时候，需要对顺序表的容量进行扩展】
void ExpendList(List* list, int size) {
	// 1. 定义一个新的指针，指向当前的顺序表
	int* p = list -> data;

	if (p == NULL) {
		fprintf(stderr, "在扩展顺序表的时候遇到了一个错误：顺序表地址为空！\n");
		exit(1);
	}

	// 2. 申请新的空间
	list->data = (int*)malloc(sizeof(int) * (InitSize + size));
	if (list -> data == NULL) {
		fprintf(stderr, "在扩展顺序表的时候遇到了一个错误：申请扩展内存失败！\n");
		exit(1);
	}

	// 3. 将原来的值移动到新的空间中
	list->maxSize = list->maxSize + size;
	for (int i = 0; i < list->currentLength; i++) {
		list->data[i] = p[i];
	}
}

// 2.5 遍历当前顺序表
void PrintList(List* list) {
	for (int i = 0; i < list->currentLength; i++) {
		printf("List[%d] = %d\n", i, list->data[i]);
	}
}

// 3. 赋值 【往线性表里添加值，默认往最后面加】
void AppendList(List* list, int value) {
	// 判断是否溢出
	if (list->currentLength >= list->maxSize) {
		fprintf(stderr, "无法向顺序表中添加新的值，顺序表已满！\n");
		exit(1);
	}

	list->data[list->currentLength] = value;
	list->currentLength++;
}


// 4. 取值 【根据位置获取对应的值】
int GetList(List* list, int index) {
	if (index >= list->currentLength) {
		fprintf(stderr, "无法获取指定位置的元素，位置过大\n");
		exit(1);
	}
	else if (index < 0) {
		fprintf(stderr, "无法获取指定位置的元素，位置过小\n");
		exit(1);
	}

	int value = list->data[index];
	return value;
}


// 5. 插值 【给位置，把值插入对应的位置中】
void InsertList(List* list, int index, int value) {
	// 判断位置的合法性
	if (index > list->currentLength || index >= list->maxSize) {
		fprintf(stderr, "插入位置过大\n");
		exit(1);
	}
	else if (index < 0) {
		fprintf(stderr, "插入位置过小\n");
		exit(1);
	}

	// 将待插入位置后面的元素后推
	for (int i = list->currentLength - 1; i >= index; i--) {
		list->data[i+1] = list->data[i];
	}

	list->data[index] = value;
	list->currentLength++;
}


// 6. 删除元素 【删除指定位置的元素，后面的向前移动】
void DeleteList(List* list, int index) {
	// 判断位置合法性
	if (index >= list->currentLength) {
		fprintf(stderr, "位置过大\n");
		exit(1);
	}
	else if (index < 0) {
		fprintf(stderr, "位置过小\n");
		exit(1);
	}

	for (int i = index; i < list->currentLength; i++) {
		list->data[i] = list->data[i + 1];
	}

	list->currentLength--;

}


