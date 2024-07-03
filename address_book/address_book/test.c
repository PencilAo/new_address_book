#define _CRT_SECURE_NO_WARNINGS
#include "address_book.h"
enum Option
{
	EXIT,
	add,
	del,
	search,
	modify,
	show,
	sort
};
void menu()
{
	printf("*******************************************************\n");
	printf("**********    1.add             2.del        **********\n");
	printf("**********    3.search          4.modify     **********\n");
	printf("**********    5.show            6.sort       **********\n");
	printf("**********    0.exit                         **********\n");
	printf("*******************************************************\n");

}
int main()
{
	int input;
	struct Address_book book;
	Init_Address_book(&book);
	do
	{
		menu();
		printf("请选择你要处理的方式--> ");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			Add_book(&book);
			break;
		case del:
			Del_book(&book);
			break;
		case search:
			Search_book(&book);
			break;
		case modify:
			Modify_book(&book);
			break;
		case show:
			Show_book(&book);
			break;
		case sort:
			Sort_book(&book);
			break;
		case EXIT:
			Save_Address_book(&book);
		    Destroy_Address_book(&book);
			printf("结束\n");
			break;
		default:
			printf("请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}