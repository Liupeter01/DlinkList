#include"menu.h"

/*�˵�*/
void Menu(DList* list)
{
          int select = 1;
          while (select)
          {
                    printf("*****************************************************************\n");
                    printf("*   [1]  push_back       \t[2] push_front           \t*\n");
                    printf("*   [3]  show_list         \t[4] pop_back             \t*\n");
                    printf("*   [5]  pop_front        \t[6] insert_pos            \t*\n");
                    printf("*   [7]  find                 \t[8] length                   \t*\n");
                    printf("*   [9]  delete_pos      \t[10] delete_val           \t*\n");
                    printf("*   [11]  Sort               \t[12] reverse               \t*\n");
                    printf("*   [13]  Clear             \t[14] Destroy(Dangerous!!) \t*\n");
                    printf("*   [15]  Cls                \t[0] Quit                       \t*\n");
                    printf("*****************************************************************\n");
                    printf("��ѡ��>");
                    scanf("%d", &select);
                    if (!select)         //ѡ��ֵΪ0 
                    {
                             // SListDistroy(list);      //z ��ֹ�ڴ�й©��Ȼ����ڴ�
                              break;              //�˳�������
                    }
                    else
                    {
                              switch (select)
                              {
                              case 1:DListPushBack(list);break; //���ݳ�ʼ��β������
                              case 2: DListPushFront(list);break; //���ݳ�ʼ��ͷ������
                              case 3:DisplayLinkList(list->first); break;
                              case 4:DListPopBack(list); break;
                              case 5:DListPopFront(list); break;
                              case 6:    //���ݵ�λ����룬��ǰĬ��ʹ�ú�巨
                              {
                                        printf("��������Ҫ��������ݣ�>");
                                        ElemType item = 0;  //����
                                        scanf("%d", &item);
                                        printf("��������Ҫ�����λ�ã�>");
                                        int pos = 0;   //λ��
                                        scanf("%d", &pos);
                                        DListInsertBackByPos(list, pos, item);
                                        break;
                              }

                              case 7:   //���ݵĲ���
                              {
                                        printf("��������Ҫ���ҵ����ݣ�>");
                                        ElemType item = 0;
                                        scanf("%d", &item);
                                        LinkNode* node = LocateElemByNum(list, item);
                                        if (node == NULL)
                                        {
                                                  printf("���ҵ�����%d�������в�����\n", item);
                                        }
                                        else
                                        {
                                                  printf("���ҵ�����%d�������д���\n", item);
                                        }
                                        break;
                              }

                              case 8:printf("˫����ĳ���Ϊ��%d\n", list->amount); break;
                              case 9: //ɾ����������λ���Ԫ��
                              {
                                        printf("��������Ҫɾ����Ԫ�����ڵ�λ��>");
                                        ElemType item;               //���ɾ��������
                                        int pos = 0;
                                        scanf("%d", &pos);
                                        if (!DListDeleteByPos(list, pos, &item))
                                        {
                                                  printf("����ɾ��ʧ��\n");
                                        }
                                        break;
                              }
                              case 10://ɾ��ָ��������Ԫ��
                              {
                                        printf("��������Ҫɾ����Ԫ�أ�>");
                                        ElemType num;               //ɾ��������
                                        ElemType item;               //���ɾ��������
                                        scanf("%d", &num);
                                        if (!DListDeleteByNum(list, num, &item))
                                        {
                                                  printf("����ɾ��ʧ��\n");
                                        }
                                        break;
                              }
                              case 11: DListSort(list,list->first->next, list->last); break;             //��������(Ҳ����ѡ�������)
                              case 12: DListReverse(list); break;            //��ת
                              case 13: //SListClear(list); break;
                              case 14://SListDistroy(list); printf("\n�����Ѿ����ݻ٣������˳�\n"); return; break;
                              case 15:system("cls"); break ;
                              default:printf("�����������������\n"); break;
                              }
                    }
          }
          return;
}