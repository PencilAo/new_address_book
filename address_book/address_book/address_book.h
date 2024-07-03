#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX  5
#define MAX_TELE 12
#define MAX_ADDRESS 30
#define DEFAULT_SZ 3                 // 默认动态内存为3
#define ADD 2                        // 每次增容的大小
//记录人的信息
struct Peo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
};

//静态版本
//struct Address_book
//{
//	struct Peo data[MAX];    // 存放人的信息
//	int count;               // 记录当前通讯录中实际人的个数
//};


//动态版本
struct Address_book
{
	struct Peo* data;
	int count;                // 记录当前通讯录中实际人的个数
	int capacity;             // 当前通讯录的容量

};
//初始化通讯录
void Init_Address_book(struct Address_book* pc);

//销毁通讯录
void Destroy_Address_book(struct Address_book* pc);

//增加联系人的通讯录
void Add_book(struct Address_book* pc);

//删除联系人的通讯录
void Del_book(struct Address_book* pc);

//打印通讯录
void Show_book(const struct Address_book* pc);

//查找通讯录
void Search_book(const struct Address_book* pc);

//修改通讯录
void Modify_book(struct Address_book* pc);

//排序通讯录
void Sort_book(struct Address_book* pc);

//保存通讯录到文件
void Save_Address_book(const struct Address_book* pc);

//加载文件信息到通讯录
void Load_Address_book(struct Address_book* pc);