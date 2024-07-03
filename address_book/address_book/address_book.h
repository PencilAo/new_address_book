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
#define DEFAULT_SZ 3                 // Ĭ�϶�̬�ڴ�Ϊ3
#define ADD 2                        // ÿ�����ݵĴ�С
//��¼�˵���Ϣ
struct Peo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
};

//��̬�汾
//struct Address_book
//{
//	struct Peo data[MAX];    // ����˵���Ϣ
//	int count;               // ��¼��ǰͨѶ¼��ʵ���˵ĸ���
//};


//��̬�汾
struct Address_book
{
	struct Peo* data;
	int count;                // ��¼��ǰͨѶ¼��ʵ���˵ĸ���
	int capacity;             // ��ǰͨѶ¼������

};
//��ʼ��ͨѶ¼
void Init_Address_book(struct Address_book* pc);

//����ͨѶ¼
void Destroy_Address_book(struct Address_book* pc);

//������ϵ�˵�ͨѶ¼
void Add_book(struct Address_book* pc);

//ɾ����ϵ�˵�ͨѶ¼
void Del_book(struct Address_book* pc);

//��ӡͨѶ¼
void Show_book(const struct Address_book* pc);

//����ͨѶ¼
void Search_book(const struct Address_book* pc);

//�޸�ͨѶ¼
void Modify_book(struct Address_book* pc);

//����ͨѶ¼
void Sort_book(struct Address_book* pc);

//����ͨѶ¼���ļ�
void Save_Address_book(const struct Address_book* pc);

//�����ļ���Ϣ��ͨѶ¼
void Load_Address_book(struct Address_book* pc);