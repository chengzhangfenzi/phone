#include"my.h"
/**************
 *函数：InitListWithData()
 *参数：链表头结点L
 *返回值：链表头结点
 *功能：给通讯录设置一些初始数据。该函数为可选功能
 **************/
AddressList InitListWithData(AddressList L)
{
	AddressNode n;
	
	strcpy(n.name,"Li");
	n.sex = 'm';
	n.number = 10010;
	strcpy(n.note,"Li");
	AddNode(L,n);
	
	strcpy(n.name,"Liu");
	n.sex = 'f';
	n.number = 11000;
	strcpy(n.note,"Liu");
	AddNode(L,n);
	
	strcpy(n.name,"Shi");
	n.sex = 'm';
	n.number = 10000;
	strcpy(n.note,"Shi");
	AddNode(L,n);
	
	strcpy(n.name,"NiNa");
	n.sex = 'f';
	n.number = 10001;
	strcpy(n.note,"NiNa");
	AddNode(L,n);
	
	strcpy(n.name,"Lucy");
	n.sex = 'f';
	n.number = 10100;
	strcpy(n.note,"Lucy");
	AddNode(L,n);
	return L;
}
int main()
{
	int select;
	AddressList phone = CreateEmptyList();
	phone = InitListWithData(phone);
	do
	{
		system("clear");//清屏
		menu_start();
		scanf("%d",&select);
		getchar();
		if(select==0)
		{
			printf("欢迎下次使用！\n");
			break;
		}
		switch(select)
		{
			case 1:
			PrintList(phone);
			break;
			case 2:
			InputNode(phone);
			break;
			case 3:
			menu_delete(phone);
			break;
			case 4:
			menu_getelem(phone);
			break;
			case 5:
			ClearList(phone);
			break;
			case 6:
			SelectBySex(phone,'m');
			break;
			case 7:
			SelectBySex(phone,'f');
			break;
			default:
			printf("输入非法数据，请重新输入！\n");
		}
		printf("请按回车继续……\n");
		getchar();
	}while(select!=0);
	return 0;
}