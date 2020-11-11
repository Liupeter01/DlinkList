#include"DList.h"

LinkNode* CreateNode(ElemType x)		//�ڵ㴴������
{
		  LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
		  assert(s != NULL);
		  s->data = x;
		  s->next = s->prior = NULL;
		  return s;
}

void DisplayLinkList(LinkNode* s)			  //˫�����Ԫ�����
{
		  LinkNode* pnext = s->next;			  //����ͷ��������Ԫ�ڵ�
		  while (pnext != NULL)
		  {
					printf("%d<--->", pnext->data);
					pnext = pnext->next;
		  }
		  printf("END\n");
}

LinkNode* LocateElemByNum(DList* SL,ElemType key)//����Ԫ��
{
		  LinkNode* p = SL->first->next;		//����ͷ������Ԫ�ڵ㿪ʼ
		  while (p != NULL && p->data != key)
		  {
					p = p->next;
		  }
		  return p;
}

void InitDlist(DList* SL)			//��ʼ��
{
		  SL->first = SL->last = (LinkNode*)malloc(sizeof(LinkNode));
		  assert(SL->first != NULL);
		  SL->last->next = SL->first->prior = NULL;//ָ���ʼ��
		  SL->amount = 0;
}

void DListPushBack(DList* SL)	//˫�����β�巨
{
		  if (SL == NULL)					//������û�б���ʼ��
		  {
					InitDlist(SL);
		  }
		  LinkNode * ptr = SL->first->next;	//ָ����Ԫ���
		  //������������ֻ����һ��ͷ���ʱ(����������Ԫ���)
		  ElemType item = 0;
		  printf("��������Ҫͨ��β�巨���������(-1��������):>");
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = CreateNode(item);
					s->prior = SL->last;
					SL->last->next = s;				//��һ�����ĺ�̽��Ϊs
					SL->last = s;
					SL->amount++;					//�����������
		  }
}

void DListPushFront(DList* SL)//˫�����ͷ�巨
{
		  if (SL == NULL)					//������û�б���ʼ��
		  {
					InitDlist(SL);
		  }
		  printf("��������Ҫͨ��ͷ�巨���������(-1��������):>");
		  ElemType item = 0;
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = CreateNode(item);
					if (SL->first->next == NULL && SL->amount == 0)			  //û����Ԫ�ڵ�
					{
							  SL->last = SL->first->next;	//���ֻ��һ����Ԫ��㣬��ǰ��Ԫ�ڵ�Ϊβ���
							  s->prior = SL->first;			//s����ǰ�����Ϊͷ���
					}
					else									//����Ԫ�ڵ�
					{
							  s->next = SL->first->next;	//ԭ�ȵ���Ԫ���Ϊs�ĺ�̽��
							  SL->first->next->prior = s;			//��Ԫ�ڵ��ǰ�����Ϊs
					}
					SL->first->next = s;					  //sΪ�µ���Ԫ�ڵ�
					SL->amount++;					//��������
		  }
}

void DListInsertBackByPos(DList* SL, int pos, ElemType e)	  //˫������λ��β��
{
		  if (SL == NULL)
		  {
					printf("˫����û�б�����������ʧ��\n");
					return;
		  }
		  if (pos < 1 && pos>SL->amount)
		  {
					printf("˫����Ĳ���λ�÷Ƿ�������ʧ��\n");
					return;
		  }
		  LinkNode* p = SL->first->next;		//����ͷ������Ԫ�ڵ㿪ʼ
		  int counter = 0;
		  while (p != NULL && counter++ < pos - 1)
		  {
					p = p->next;
		  }
		  if (p != NULL)				//�ж������ҵ��ڵ�
		  {
					LinkNode* s = CreateNode(e);
					if (p->next == NULL)		  //�ýڵ������һ���ڵ�û�к��
					{
							  p->next = s;		  //p�ĺ��Ϊs
							  s->prior = p;		  //s��ǰ��Ϊp
							  SL->last = s;		  //�²���Ľ��Ϊ���һ�����
					}
					else
					{
							  p->next->prior = s; //p�ĺ�̵�ǰ����Ϊs
							  s->prior = p;
							  s->next = p->next;  //ԭ��p�ĺ������Ϊs�ĺ��
							  p->next = s;					//p��ǰ�ĺ��Ϊs						  
					}
					SL->amount++;
					return;
		  }
		  else
		  {
					return;				  //û���ҵ��ڵ�
		  }
}

void DListPopFront(DList* SL)			//˫�����ͷ��ɾ��
{
		  if (SL->amount == 0)					  //�����ڽڵ�
		  {
					printf("����ĳ���Ϊ�գ��޷�����ɾ������\n");
					return;
		  }
		  else
		  {
					LinkNode *p = SL->first->next;	//������Ԫ�ڵ�
					if (p->next == NULL)					//��Ԫ�ڵ㼴Ϊ���һ�����
					{
							  free(p);
							  SL->last = SL->first;			//β���ָ��ͷ���
							  SL->first->next = SL->last->next = NULL;
					}
					else
					{
							  SL->first->next = p->next;	//������ǰ��Ԫ�ڵ�
							  p->next->prior = SL->first;			  //��Ԫ�ڵ��̵�ǰ��ָ��ͷ���
							  free(p);
					}
					SL->amount--;
		  }
}

void DListPopBack(DList* SL)		//˫�����β��ɾ��
{
		  if (SL->amount == 0)					  //�����ڽڵ�
		  {
					printf("����ĳ���Ϊ�գ��޷�����ɾ������\n");
					return;
		  }
		  else
		  {
					LinkNode* pre = SL->last->prior;		//����������ǰ��
					if (SL->first->next == SL->last)					//ֻʣ��һ��ͷ�����
					{
							  free(SL->last);
							  SL->last = SL->first;
							  SL->last->next = SL->first->next = NULL;
					}
					else
					{
							  free(SL->last);
							  SL->last = pre;
							  SL->last->next = NULL;
					}
					SL->amount--;
		  }
}

BOOL DListDeleteByPos(DList* SL, int pos, ElemType* e)			//˫�����ͨ��λ��ɾ��
{
		  if (SL == NULL || SL->amount == 0)
		  {
					printf("����ĳ���Ϊ�գ��޷�����ɾ������\n");
					return FALSE;
		  }
		  if (pos <0 || pos>SL->amount)
		  {
					printf("�������Ҫɾ����λ�÷Ƿ����޷�����ɾ������\n");
					return FALSE;
		  }
		  LinkNode* pre = SL->first->next;		//����ͷ������Ԫ�ڵ㿪ʼ
		  int counter = 1;
		  while (pre != NULL && counter++ < pos - 1)
		  {
					pre = pre->next;
		  }
		  if (pre != NULL)				//�ж������ҵ��ڵ�
		  {
					LinkNode* p = pre->next;			  //��ǰɾ���Ľ��
					if (p != NULL)
					{
							  *e = p->data;				  //ȡ������
							  if (p->next == NULL)		  //�ýڵ������һ���ڵ�û�к��
							  {
										SL->last = pre;		//pΪpnext��ǰ��
										SL->last->next = NULL;
							  }
							  else
							  {
										LinkNode* pnext = p->next;	  //�ýڵ�ĺ�̽��
										pre->next = pnext;
										pnext->prior = pre;
							  }
							  free(p);
					}
					SL->amount--;
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //û���ҵ��ڵ�
		  }
}

BOOL DListDeleteByNum(DList* SL, ElemType key, ElemType* e)			//˫�����ͨ����ֵɾ��
{
		  if (SL == NULL || SL->amount == 0)
		  {
					printf("����ĳ���Ϊ�գ��޷�����ɾ������\n");
					return FALSE;
		  }
		  LinkNode* p = LocateElemByNum(SL, key);
		  if (p != NULL)				//�ж������ҵ��ڵ�
		  {
					*e = p->data;
					LinkNode* pre = p->prior;			  //ɾ���Ľ��ǰ��
					LinkNode* pnext = p->next;			  //��ǰɾ���ĺ��
					if (pnext == NULL)		  //�ýڵ������һ���ڵ�û�к��
					{
							  SL->last = pre;		//pΪpnext��ǰ��
							  SL->last->next = NULL;
					}
					else
					{
							  pre->next = pnext;
							  pnext->prior = pre;
					}
					free(p);
					SL->amount--;
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //û���ҵ��ڵ�
		  }
}

void Swap(ElemType* a1, ElemType* a2)
{
		  ElemType temp = *a1;
		  *a1 = *a2;
		   *a2 = temp;
}

void  DListSort(LinkNode* left, LinkNode* right)			//����
{
		  if (left!=NULL && right!=NULL)
		  {
					LinkNode* i = left;				//����ͷ���
					LinkNode* j = right;
					if(left != NULL && right != NULL)
					{
							  while (left->data > i->data && i!=NULL)
							  {
										i = i->next;
							  }
							  while (left->data < j->data && j!=left)
							  {
										j = j->prior;
							  }
							  if (i != j)
							  {
										Swap(&i->data, &j->data);
							  }
					}
					Swap(&left->data, &j->data);
					DListSort(left, j);
					DListSort(j->next, right);
		  }
}

void DListDistroy(DList* SL)					  //����Ĵݻ�
{

}

void DListClear(DList* SL)			//��������
{

}

void DListReverse(DList* SL)		//����ķ�ת
{

}