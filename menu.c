#include"my.h"
/**************
 *函数：menu_start()
 *参数：无
 *返回值：无
 *功能：起始界面
 **************/
void menu_start()
{
	printf("****************************\n");
	printf("欢迎使用简易通讯录！\n");
	printf("****************************\n");
	printf("1:输出全部联系人信息\n");
	printf("2:插入新的联系人\n");
	printf("3:删除一个联系人\n");
	printf("4:查找某个联系人\n");
	printf("5:清空联系人信息\n");
	printf("6:筛选所有男性联系人\n");
	printf("7:筛选所有女性联系人\n");
	printf("0:退出\n");
	printf("****************************\n");
	printf("请选择要执行的操作：");
}

/**************
 *函数：menu_delete()
 *参数：链表头结点L
 *返回值：无
 *功能：选择删除联系人后的次级界面
 **************/
void menu_delete(AddressList L)
{
	int select,number;
	char name[MAXLEN];
	printf("****************************\n");
	printf("请输入删除数据的方式：\n");
	printf("1:按姓名\n");
	printf("2:按号码\n");
	printf("0:返回\n");
	printf("****************************\n");
	do
	{
		printf("请选择：");
		scanf("%d",&select);
		getchar();
		if(select!=1 && select!=2 && select!=0)
			printf("输入非法数据，请重新输入！\n");
	}while(select!=1 && select!=2 && select!=0);
	switch(select)
	{
		case 1:
		printf("请输入姓名：");
		scanf("%[^\n]",name);
		getchar();
		DeleteElemByName(L,name);
		break;
		case 2:
		printf("请输入号码：");
		scanf("%d",&number);
		getchar();
		DeleteElemByNum(L,number);
		break;
		case 0:
		printf("即将返回上级目录，");
		break;
	}
}

/**************
 *函数：menu_getelem()
 *参数：链表头结点L
 *返回值：无
 *功能：选择查找联系人后的次级界面
 **************/
void menu_getelem(AddressList L)
{
	int select,number;
	char name[MAXLEN];
	printf("****************************\n");
	printf("请输入查找联系人的方式：\n");
	printf("1:按姓名\n");
	printf("2:按号码\n");
	printf("0:返回\n");
	printf("****************************\n");
	do
	{
		printf("请选择：");
		scanf("%d",&select);
		getchar();
		if(select!=1 && select!=2 && select!=0)
			printf("输入非法数据，请重新输入！\n");
	}while(select!=1 && select!=2 && select!=0);
	switch(select)
	{
		case 1:
		printf("请输入姓名：");
		scanf("%[^\n]",name);
		getchar();
		GetElemByName(L,name);
		break;
		case 2:
		printf("请输入号码：");
		scanf("%d",&number);
		getchar();
		GetElemByNum(L,number);
		break;
		case 0:
		printf("即将返回上级目录，");
		break;
	}
}
