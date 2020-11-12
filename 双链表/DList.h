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
		  struct	LinkNode* prior;	//ǰ�����
		  struct LinkNode* next;		//��̽ڵ�
}LinkNode;

typedef struct DList
{
		  LinkNode* first;				//ͷ���
		  LinkNode* last;					//β���
		  int amount;
}DList;

LinkNode* CreateNode(ElemType x);		//�ڵ㴴������
void DisplayLinkList(LinkNode* s);				  //˫�����Ԫ�����
LinkNode* LocateElemByNum(DList* SL, ElemType key);//����Ԫ��

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitDlist(DList* SL);			//��ʼ��
void  DListSort(DList* list, LinkNode* left, LinkNode* right);			//����
void DListDistroy(DList* SL);					  //����Ĵݻ�
void DListClear(DList* SL);			//��������
void DListReverse(DList* SL);			//����ķ�ת

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DListPushBack(DList* SL);	//˫�����β�巨
void DListPushFront(DList* SL);//˫�����ͷ�巨
void DListInsertBackByPos(DList* SL, int pos, ElemType e);		  //˫������λ��β��

//////////////////////////////////////////////////////////ɾ��ϵ��///////////////////////////////////////////////////
void DListPopFront(DList* SL);			//˫�����ͷ��ɾ��
void DListPopBack(DList* SL);		//˫�����β��ɾ��
BOOL DListDeleteByPos(DList* SL,int pos,ElemType *e);			//˫�����ͨ��λ��ɾ��
BOOL DListDeleteByNum(DList* SL,ElemType key,ElemType *e);			//˫�����ͨ����ֵɾ��