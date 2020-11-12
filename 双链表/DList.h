#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>
#include<memory.h>

#pragma warning(disable:6011)

#define ElemType int

typedef struct LinkNode
{
		  ElemType data;
		  struct	LinkNode* prior;	//前驱结点
		  struct LinkNode* next;		//后继节点
}LinkNode;

typedef struct DList
{
		  LinkNode* first;				//头结点
		  LinkNode* last;					//尾结点
		  int amount;
}DList;

LinkNode* CreateNode(ElemType x);		//节点创建方法
void DisplayLinkList(LinkNode* s);				  //双链表的元素输出
LinkNode* LocateElemByNum(DList* SL, ElemType key);//查找元素

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitDlist(DList* SL);			//初始化
void  DListSort(DList* list, LinkNode* left, LinkNode* right);			//排序
void DListDistroy(DList* SL);					  //链表的摧毁
void DListClear(DList* SL);			//链表的清空
void DListReverse(DList* SL);			//链表的反转

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DListPushBack(DList* SL);	//双链表的尾插法
void DListPushFront(DList* SL);//双链表的头插法
void DListInsertBackByPos(DList* SL, int pos, ElemType e);		  //双链表按照位序尾插

//////////////////////////////////////////////////////////删除系列///////////////////////////////////////////////////
void DListPopFront(DList* SL);			//双链表的头部删除
void DListPopBack(DList* SL);		//双链表的尾部删除
BOOL DListDeleteByPos(DList* SL,int pos,ElemType *e);			//双链表的通过位序删除
BOOL DListDeleteByNum(DList* SL,ElemType key,ElemType *e);			//双链表的通过数值删除