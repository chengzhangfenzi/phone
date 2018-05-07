#ifndef __MY_H__
#define __MY_H__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 128
#define OK 1
#define ERROR 0
typedef struct node
{
	char name[MAXLEN];
	char sex;
	int number;
	char note[MAXLEN];
	struct node *next;
}AddressNode;
typedef struct node *AddressList;
/*函数声明部分*/
/*fun.c*/
void PrintAddressNode(AddressList L);
void PrintList(AddressList L);
int GetElemByNum(AddressList L,int number);
int GetElemByName(AddressList L,const char *name);
AddressList CreateEmptyList();
void AddNode(AddressList L,AddressNode n);
void InputNode(AddressList L);
int DeleteElemByNum(AddressList L,int number);
int DeleteElemByName(AddressList L,const char *name);
void ClearList(AddressList L);
void SelectBySex(AddressList L,char sex);

/*menu.c*/
void menu_start();
void menu_delete(AddressList L);
void menu_getelem(AddressList L);

/*main.c*/
AddressList InitListWithData(AddressList L);
#endif