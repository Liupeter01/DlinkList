#include"DList.h"

LinkNode* CreateNode(ElemType x)		//节点创建方法
{
		  LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
		  assert(s != NULL);
		  s->data = x;
		  s->next = s->prior = NULL;
		  return s;
}

void DisplayLinkList(LinkNode* s)			  //双链表的元素输出
{
		  LinkNode* pnext = s->next;			  //跳过头结点访问首元节点
		  while (pnext != NULL)
		  {
					printf("%d<--->", pnext->data);
					pnext = pnext->next;
		  }
		  printf("END\n");
}

LinkNode* LocateElemByNum(DList* SL,ElemType key)//查找元素
{
		  LinkNode* p = SL->first->next;		//跳过头结点从首元节点开始
		  while (p != NULL && p->data != key)
		  {
					p = p->next;
		  }
		  return p;
}

void InitDlist(DList* SL)			//初始化
{
		  SL->first = SL->last = (LinkNode*)malloc(sizeof(LinkNode));
		  assert(SL->first != NULL);
		  SL->last->next = SL->first->prior = NULL;//指针初始化
		  SL->amount = 0;
}

void DListPushBack(DList* SL)	//双链表的尾插法
{
		  if (SL == NULL)					//该链表没有被初始化
		  {
					InitDlist(SL);
		  }
		  LinkNode * ptr = SL->first->next;	//指向首元结点
		  //当整个链表中只存在一个头结点时(即不存在首元结点)
		  ElemType item = 0;
		  printf("请输入需要通过尾插法插入的数据(-1结束输入):>");
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = CreateNode(item);
					s->prior = SL->last;
					SL->last->next = s;				//上一个结点的后继结点为s
					SL->last = s;
					SL->amount++;					//结点数增加了
		  }
}

void DListPushFront(DList* SL)//双链表的头插法
{
		  if (SL == NULL)					//该链表没有被初始化
		  {
					InitDlist(SL);
		  }
		  printf("请输入需要通过头插法插入的数据(-1结束输入):>");
		  ElemType item = 0;
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = CreateNode(item);
					if (SL->first->next == NULL && SL->amount == 0)			  //没有首元节点
					{
							  SL->last = SL->first->next;	//如果只有一个首元结点，则当前首元节点为尾结点
							  s->prior = SL->first;			//s结点的前驱结点为头结点
					}
					else									//有首元节点
					{
							  s->next = SL->first->next;	//原先的首元结点为s的后继结点
							  SL->first->next->prior = s;			//首元节点的前驱结点为s
					}
					SL->first->next = s;					  //s为新的首元节点
					SL->amount++;					//数量自增
		  }
}

void DListInsertBackByPos(DList* SL, int pos, ElemType e)	  //双链表按照位序尾插
{
		  if (SL == NULL)
		  {
					printf("双链表没有被创建，插入失败\n");
					return;
		  }
		  if (pos < 1 && pos>SL->amount)
		  {
					printf("双链表的插入位置非法，插入失败\n");
					return;
		  }
		  LinkNode* p = SL->first->next;		//跳过头结点从首元节点开始
		  int counter = 0;
		  while (p != NULL && counter++ < pos - 1)
		  {
					p = p->next;
		  }
		  if (p != NULL)				//判断有无找到节点
		  {
					LinkNode* s = CreateNode(e);
					if (p->next == NULL)		  //该节点是最后一个节点没有后继
					{
							  p->next = s;		  //p的后继为s
							  s->prior = p;		  //s的前驱为p
							  SL->last = s;		  //新插入的结点为最后一个结点
					}
					else
					{
							  p->next->prior = s; //p的后继的前驱改为s
							  s->prior = p;
							  s->next = p->next;  //原先p的后继现在为s的后继
							  p->next = s;					//p当前的后继为s						  
					}
					SL->amount++;
					return;
		  }
		  else
		  {
					return;				  //没有找到节点
		  }
}

void DListPopFront(DList* SL)			//双链表的头部删除
{
		  if (SL->amount == 0)					  //不存在节点
		  {
					printf("链表的长度为空，无法进行删除操作\n");
					return;
		  }
		  else
		  {
					LinkNode *p = SL->first->next;	//保存首元节点
					if (p->next == NULL)					//首元节点即为最后一个结点
					{
							  free(p);
							  SL->last = SL->first;			//尾结点指向头结点
							  SL->first->next = SL->last->next = NULL;
					}
					else
					{
							  SL->first->next = p->next;	//跳过当前首元节点
							  p->next->prior = SL->first;			  //首元节点后继的前键指向头结点
							  free(p);
					}
					SL->amount--;
		  }
}

void DListPopBack(DList* SL)		//双链表的尾部删除
{
		  if (SL->amount == 0)					  //不存在节点
		  {
					printf("链表的长度为空，无法进行删除操作\n");
					return;
		  }
		  else
		  {
					LinkNode* pre = SL->last->prior;		//保存最后结点的前驱
					if (SL->first->next == SL->last)					//只剩下一个头结点了
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

BOOL DListDeleteByPos(DList* SL, int pos, ElemType* e)			//双链表的通过位序删除
{
		  if (SL == NULL || SL->amount == 0)
		  {
					printf("链表的长度为空，无法进行删除操作\n");
					return FALSE;
		  }
		  if (pos <0 || pos>SL->amount)
		  {
					printf("输入的需要删除的位置非法，无法进行删除操作\n");
					return FALSE;
		  }
		  LinkNode* pre = SL->first->next;		//跳过头结点从首元节点开始
		  int counter = 1;
		  while (pre != NULL && counter++ < pos - 1)
		  {
					pre = pre->next;
		  }
		  if (pre != NULL)				//判断有无找到节点
		  {
					LinkNode* p = pre->next;			  //当前删除的结点
					if (p != NULL)
					{
							  *e = p->data;				  //取出数据
							  if (p->next == NULL)		  //该节点是最后一个节点没有后继
							  {
										SL->last = pre;		//p为pnext的前驱
										SL->last->next = NULL;
							  }
							  else
							  {
										LinkNode* pnext = p->next;	  //该节点的后继结点
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
					return FALSE;				  //没有找到节点
		  }
}

BOOL DListDeleteByNum(DList* SL, ElemType key, ElemType* e)			//双链表的通过数值删除
{
		  if (SL == NULL || SL->amount == 0)
		  {
					printf("链表的长度为空，无法进行删除操作\n");
					return FALSE;
		  }
		  LinkNode* p = LocateElemByNum(SL, key);
		  if (p != NULL)				//判断有无找到节点
		  {
					*e = p->data;
					LinkNode* pre = p->prior;			  //删除的结点前驱
					LinkNode* pnext = p->next;			  //当前删除的后继
					if (pnext == NULL)		  //该节点是最后一个节点没有后继
					{
							  SL->last = pre;		//p为pnext的前驱
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
					return FALSE;				  //没有找到节点
		  }
}

void Swap(ElemType* a1, ElemType* a2)
{
		  ElemType temp = *a1;
		  *a1 = *a2;
		   *a2 = temp;
}

void  DListSort(LinkNode* left, LinkNode* right)			//排序
{
		  if (left!=NULL && right!=NULL)
		  {
					LinkNode* i = left;				//跳过头结点
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

void DListDistroy(DList* SL)					  //链表的摧毁
{

}

void DListClear(DList* SL)			//链表的清空
{

}

void DListReverse(DList* SL)		//链表的反转
{

}