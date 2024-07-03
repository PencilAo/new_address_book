#define _CRT_SECURE_NO_WARNINGS
#include "address_book.h"


//��ʼ��ͨѶ¼
//��̬�汾
//void Init_Address_book(struct Address_book* pc)
//{
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
//
//
void Load_Address_book(struct Address_book* pc)
{
	FILE* pf = fopen("E:\\code\\test\\address_book\\address_book.txt", "rb");
	if (pf == NULL)
	{
		perror("Load_Address_book");
		return 1;
	}
	struct Peo tmp = { 0 };
	while ((fread(&tmp, sizeof(struct Peo), 1, pf)) == 1)
	{
		//�ж��Ƿ�Ҫ����
		if (pc->count == pc->capacity)
		{
			struct Peo* ptr = (struct Peo*)realloc(pc->data, (pc->capacity + ADD) * sizeof(struct Peo));
			if (ptr == NULL)
			{
				printf("%s", strerror(errno));
				return;
			}
			else
			{
				pc->data = ptr;
				pc->capacity += ADD;
			}
		}
		pc->data[pc->count] = tmp;
		pc->count++;
	}
	fclose(pf);
	pf = NULL;
}
//��̬�汾
void Init_Address_book(struct Address_book* pc)
{
	assert(pc);
	pc->count = 0;
	pc->data = (struct Peo*)calloc(DEFAULT_SZ, sizeof(struct Peo));
	if (pc->data == NULL)
	{
		printf("%s", strerror(errno));
	}
	pc->capacity = DEFAULT_SZ;

	//�����ļ���Ϣ��ͨѶ¼��
	Load_Address_book(pc);
}

//��̬�汾
//void Add_book(struct Address_book* pc)
//{
//	assert(pc);
//	if (pc->count == MAX)
//	{
//		printf("ͨѶ¼����\n");
//	}
//	else
//	{
//		printf("����������-> ");
//		scanf("%s",pc->data[pc->count].name);     //������char ���ͣ�����Ҫȡ��ַ
//		printf("����������-> ");
//		scanf("%d", &(pc->data[pc->count].age));  //��������Ҫȡ��ַ��
//		printf("�������Ա�-> ");
//		scanf("%s", pc->data[pc->count].sex);
//		printf("������绰-> ");
//		scanf("%s", pc->data[pc->count].tele);
//		printf("�������ַ-> ");
//		scanf("%s", pc->data[pc->count].address);
//
//		pc->count++;
//		printf("���ӳɹ�\n");
//	}
//}

//��̬�汾
void Add_book(struct Address_book* pc)
{
	assert(pc);
	//����
	if (pc->count == pc->capacity)
	{
		struct Peo* ptr = (struct Peo*)realloc(pc->data, (pc->capacity + ADD) * sizeof(struct Peo));
		if (ptr == NULL)
		{
			printf("%s", strerror(errno));
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += ADD;
			printf("���ݳɹ�\n");
		}
	}
		printf("����������-> ");
		scanf("%s", pc->data[pc->count].name);     //������char ���ͣ�����Ҫȡ��ַ
		printf("����������-> ");
		scanf("%d", &(pc->data[pc->count].age));  //��������Ҫȡ��ַ��
		printf("�������Ա�-> ");
		scanf("%s", pc->data[pc->count].sex);
		printf("������绰-> ");
		scanf("%s", pc->data[pc->count].tele);
		printf("�������ַ-> ");
		scanf("%s", pc->data[pc->count].address);

		pc->count++;
		printf("���ӳɹ�\n");
}
void Destroy_Address_book(struct Address_book* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;

}

static int Findbyname(struct Address_book* pc, char name[])  // ����static�󣬴˺���ֻ��������ļ���ʹ��
{
	assert(pc);
	int i;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Del_book(struct Address_book* pc)
{
	assert(pc);
	char name[MAX_NAME];
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û����Ϣ����ɾ\n");
		return;
	}
	printf("������Ҫɾ���˵�����-> ");
	scanf("%s", name);
	  //ɾ��
	//1. ����
	int i;
	int ret = Findbyname(pc, name);
	if (ret == -1)
	{
		printf("Ҫɾ���Ĳ���ͨѶ¼����\n");
		return;
	}

	//2. ɾ��
	for (i = ret; i < pc->count-1; i++)   // ����-1���Է�ֹԽ�����
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�\n");
}
void Show_book(struct Address_book* pc)
{
	assert(pc);
	int i;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n",     pc->data[i].name,
														pc->data[i].age, 
														pc->data[i].sex, 
														pc->data[i].tele,
														pc->data[i].address);
	}
}
void Search_book(struct Address_book* pc)
{
	assert(pc);
	printf("��������Ҫ���ҵ���-> ");
	char name[MAX_NAME];
	scanf("%s", name);
	int ret = Findbyname(pc, name);
	if (ret == -1)
	{
		printf("Ҫ���ҵ��˲���ͨѶ¼��\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[ret].name,
												pc->data[ret].age,
												pc->data[ret].sex,
												pc->data[ret].tele,
												pc->data[ret].address);
}
void Modify_book(struct Address_book* pc)
{
	assert(pc);
	printf("��������Ҫ�޸ĵ���-> ");
	char name[MAX_NAME];
	scanf("%s", name);
	//����
	int ret = Findbyname(pc, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ��˲���ͨѶ¼��\n");
		return;
	}
	//�޸�
	printf("�������޸ĺ������-> ");
	scanf("%s", pc->data[ret].name);       //������char ���ͣ�����Ҫȡ��ַ
	printf("�������޸ĺ������-> ");
	scanf("%d", &(pc->data[ret].age));     //��������Ҫȡ��ַ��
	printf("�������޸ĺ���Ա�-> ");
	scanf("%s", pc->data[ret].sex);
	printf("�������޸ĺ�ĵ绰-> ");
	scanf("%s", pc->data[ret].tele);
	printf("�������޸ĺ�ĵ�ַ-> ");
	scanf("%s", pc->data[ret].address);

	printf("�޸ĳɹ�\n");
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[ret].name,
												pc->data[ret].age,
												pc->data[ret].sex,
												pc->data[ret].tele,
												pc->data[ret].address);
}

//����������
int cmp_by_name(void* e1, void* e2)
{
	return strcmp(((struct Peo*)e1)->name,((struct Peo*)e2)->name);
}
int cmp_by_age(void* e1, void* e2)
{
	return strcmp(((struct Peo*)e1)->age, ((struct Peo*)e2)->age);
}
void Sort_book(struct Address_book* pc)
{
	assert(pc);
	printf("ѡ��������򷽷�-> (1Ϊ����������2Ϊ����������) \n");
	int i;
	scanf("%d", &i);
	if (i == 1)
	{
		qsort(pc->data, pc->count, sizeof(struct Peo), cmp_by_name);
		printf("����ɹ�\n");
	}
	else
	{
		qsort(pc->data, pc->count, sizeof(struct Peo), cmp_by_age);
		printf("����ɹ�\n");
	}

}
void Save_Address_book(const struct Address_book* pc)
{
	assert(pc);
	FILE* pf = fopen("E:\\code\\test\\address_book\\address_book.txt", "wb");
	if (pf == NULL)
	{
		perror("Save_Address_book");
		return;
	}
	int i;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(struct Peo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}