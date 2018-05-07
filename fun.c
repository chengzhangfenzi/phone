#include"my.h"

/**************
 *函数：PrintAddressNode()
 *参数：当前工作指针p
 *返回值：无
 *功能：打印当前工作指针指向的节点的数据
 *注意：不要直接调用该函数，而是调用PrintList()
 **************/
void PrintAddressNode(AddressList p)
{
	printf("姓名：%s\n",p->name);
	printf("性别：%s\n",p->sex=='m'?"男":"女");
	printf("电话号码：%d\n",p->number);
	printf("备注：%s\n",p->note);
}

/**************
 *函数：PrintList()
 *参数：链表头结点L
 *返回值：无
 *功能：打印当前链表内所有节点的数据
 **************/
void PrintList(AddressList L)//遍历打印整个链表
{
    AddressList p = L->next;
	if(!p)
		printf("通讯录为空！\n");
	else
	{
		printf("共%d个人\n",L->number);
		while(p)
		{
			printf("****************************\n");
			PrintAddressNode(p);
			p=p->next;
		}
		printf("****************************\n");
	}
}

/**************
 *函数：GetElemByNum()
 *参数：链表头结点L，待查找的号码number
 *返回值：成功OK/失败ERROR
 *功能：按号码查找节点
 **************/
int GetElemByNum(AddressList L,int number)
{
	AddressList p;
	p = L->next;
	while(p && p->number!=number)
	{
		p = p->next;//让p指向下一个节点
	}
	if(!p)
	{
		printf("没有%d号码的记录，请核对后查阅\n",number);
		return ERROR;
	}
	else
	{
		printf("找到记录：\n");
		PrintAddressNode(p);
		return OK;
	}
}

/**************
 *函数：GetElemByName()
 *参数：链表头结点L，待查找的姓名name
 *返回值：成功OK/失败ERROR
 *功能：按姓名查找节点
 **************/
int GetElemByName(AddressList L,const char *name)
{
	AddressList p;
	p = L->next;
	while(p && strcmp(p->name,name))
	{
		p = p->next;//让p指向下一个节点
	}
	if(!p)
	{
		printf("没有%s的记录，请核对后查阅\n",name);
		return ERROR;
	}
	else
	{
		printf("找到记录：\n");
		PrintAddressNode(p);
		return OK;
	}
}

/**************
 *函数：CreateEmptyList()
 *参数：无
 *返回值：链表头结点
 *功能：创建一个空链表
 **************/
AddressList CreateEmptyList()//创建一个空表
{
    AddressList p;
    p = (AddressList)malloc(sizeof(AddressNode));
    if(p==NULL)
    {
        perror("CreateEmptyAddressList error");
        exit(0);
    }
	p->number=0;//在头结点中的num存储的是链表的整个长度
    p->next=NULL;
    return p;
}

/**************
 *函数：AddNode()
 *参数：链表头结点L，保存新节点数据的结构体n
 *返回值：无
 *功能：插入一个节点，插入位置为头结点之后
 *注意：不要直接调用该函数，而是调用InputNode()
 **************/
void AddNode(AddressList L,AddressNode n)//插入新节点
{
	AddressList p;
	if((p = (AddressList)malloc(sizeof(AddressNode)))==NULL)
	{
		printf("插入新节点失败！\n");
	}
	strcpy(p->name,n.name);
	p->sex = n.sex;
	p->number = n.number;
	strcpy(p->note,n.note);
	p->next = L->next;
	L->next = p;
	L->number++;
}
/**************
 *函数：InputNode()
 *参数：链表头结点L
 *返回值：无
 *功能：用户输入数据，然后插入链表内
 **************/
void InputNode(AddressList L)
{
	AddressNode n;
	printf("请输入姓名：");
	scanf("%[^\n]",n.name);
	do
	{
		getchar();
		printf("请输入性别（m为男，f为女）：");
		scanf("%c",&n.sex);
		if(n.sex!='m'&&n.sex!='f')
			printf("输入错误，请重新输入！\n");
	}while(n.sex!='m'&&n.sex!='f');
	printf("请输入电话号码：");
	scanf("%d",&n.number);
	getchar();
	printf("请输入备注信息：");
	scanf("%[^\n]",n.note);
	getchar();
	AddNode(L,n);
}

/**************
 *函数：DeleteElemByNum()
 *参数：链表头结点L，待删除的号码number
 *返回值：成功OK/失败ERROR
 *功能：删除号码为number的节点
 **************/
int DeleteElemByNum(AddressList L,int number)
{
	AddressList p,q;
	p = L;
	while(p->next && p->next->number!=number)
	{
		p = p->next;//让p指向下一个节点
	}
	if(!p->next)
	{
		printf("没有%d号码的记录，请核对后删除\n",number);
		return ERROR;
	}
	else
	{
		printf("找到记录：\n");
		q = p->next;
		PrintAddressNode(q);
		p->next = q->next;
		free(q);
		L->number--;
		printf("该记录已被删除\n");
		return OK;
	}
}

/**************
 *函数：DeleteElemByName()
 *参数：链表头结点L，待删除的姓名name
 *返回值：成功OK/失败ERROR
 *功能：删除姓名为name的节点
 **************/
int DeleteElemByName(AddressList L,const char *name)
{
	AddressList p,q;
	p = L;
	while(p->next && strcmp(p->next->name,name))
	{
		p = p->next;//让p指向下一个节点
	}
	if(!p->next)
	{
		printf("没有%s的记录，请核对后查阅\n",name);
		return ERROR;
	}
	else
	{
		printf("找到记录：\n");
		q = p->next;
		PrintAddressNode(q);
		p->next = q->next;
		free(q);
		L->number--;
		printf("该记录已被删除\n");
		return OK;
	}
}

/**************
 *函数：ClearList()
 *参数：链表头结点L
 *返回值：无
 *功能：清空链表
 **************/
void ClearList(AddressList L)//清空链表
{
	AddressList p,q;
	p=L->next;
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL;
	L->number=0;
	printf("清空通讯录成功\n");
}

/**************
 *函数：SelectBySex()
 *参数：链表头结点L，性别sex('m'/'f')
 *返回值：无
 *功能：筛选链表内所有男/女的数据
 **************/
void SelectBySex(AddressList L,char sex)
{
	AddressList p = L->next;
	if(!p)
		printf("通讯录为空！\n");
	else
	{
		while(p)
		{
			if(p->sex==sex)
			{
				printf("****************************\n");
				PrintAddressNode(p);
			}
			p=p->next;
		}
		printf("****************************\n");
	}
}