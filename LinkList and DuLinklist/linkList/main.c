#include<stdio.h>
#include "linkedList.c"
#include "../head/linkedList.h"
#include<stdlib.h>

int main()
{  
    int i;     // i����¼���û�����������Ե��ö�Ӧ�������� 
    ElemType n;
    LinkedList head=NULL,p1,p2;  // headΪ�����ͷָ�룬p1,p2�ֱ�Ϊ����ָ�� ��ʹheadΪ��ָ���ʾ�������� 
    do{
    	p1 = NULL;p2 = NULL;    //�Ƚ�p1,p2��ʼ�� 
    	printf("�������Ӧ������ִ�ж�Ӧ����\n"); //�˵������� 
		printf("1.�����ʼ��\n"
		       "2.��������\n" 
			   "3.��������\n"
			   "4.������\n"
			   "5.ɾ�����\n"
			   "6.���ҽ��\n"
			   "7.��������\n"
			   "8.��ת����\n"
			   "9.�ж������Ƿ�ɻ�\n"
			   "10.���������ż�����������һ�����\n"
			   "0.�˳�����\n"
			   );
		scanf("%d",&i);              //��ȡ�û���Ҫ���õ����� 
    	getchar();
    	switch(i){
    		case 1: if(InitList(&head)==SUCCESS)printf("�����ɹ��������ѳ�ʼ��\n");  //��ʼ���������� 
			          else printf("����ʧ�ܣ�������\n");break; 
    		case 2: if(CreateList(head)==SUCCESS)printf("�����ɹ��������Ѵ���\n");   //������������ 
    		          else printf("����ʧ�ܣ����������������\n");
			          break;
    		case 3: DestroyList(&head);printf("����������\n");                       //������������ 
			          break;
			case 4: printf("������Ҫ���ĸ����ݵĽ��ĺ󷽲�����:");               //���������� 
			    	  scanf("%d",&n);getchar();										 //�����û����������Ľ������� 
			    	  if(FindList(head,n,&p1)==ERROR){                               //��ִ�в����������Բ��ҽ�㲢��Ŀ���㷵�ظ�p1,���ж������Ƿ񲻴���
					     printf("����ʧ��\n");break;
						 }
			          p2 = Create_a_Node();											 //�����һ���½�� 
			          if(InsertList(p1,p2)==SUCCESS)printf("�����ɹ�������ѱ�����\n"); //��������½�㵽Ŀ����ĺ� 
			          else printf("����ʧ��\n");
			    	  break;
			case 5: printf("�������ɾ���������ݣ�");					//ɾ��ĳ�����ĺ�һ��������� 
					  scanf("%d",&n);getchar();										//����Ҫɾ���Ľ�����Ϣ 
					  if(FindList(head,n,&p1)==ERROR){								//��ִ�в����������Բ��ҽ�㲢����Ŀ���㷵�ظ�p1,���ж������Ƿ񲻴���
					     printf("����ʧ��\n");break;								
						 }
					  if(DeleteList(p1,&n)==SUCCESS)								//ɾ��Ŀ���ĵ�һ������ 
					  {printf("�����ɹ�������ѱ�ɾ��,��ɾ���Ľ�������Ϊ%d\n",n);}
					  else printf("����ʧ��\n");
					  break;
			case 6: printf("������Ҫ���ҵĽ�������:");							//���ҽ������ 
			 		  scanf("%d",&n);getchar();										//�û���������ҵĽ��
			 		  if(SearchList(head,n)==SUCCESS)printf("�����ɹ����ý�����\n");  //���Ҹý���Ƿ���� 
			 		  else printf("����ʧ��\n"); 
			 		  break;
			case 7: printf("��ʼ��������\n");										//������������ 
			 		  TraverseList(head,NULL);										//��ʼ�������� 
					  break;
			case 8: printf("��ʼ��ת����...\n");									//��ת�������� 
					  if(ReverseList(&head)==SUCCESS)printf("�����ɹ�,����ת���\n");//��ʼ��ת���� 
					  else printf("����ʧ��\n");
					  break;
			case 9: printf("��ʼ��������Ƿ�ɻ�\n");								//�ж������Ƿ�ɻ����� 
			          if(IsLoopList(head)==SUCCESS)printf("�����ɹ�\n");			//��ʼ��������Ƿ�ɻ� 
			          else printf("����ʧ��\n");
					  break;
			case 10:printf("���������ż�����������һ�����\n");					//���������ż�����������һ��������� 
					  if(ReverseEvenList(&head)!=NULL)printf("�����ɹ�\n");			//��ʼִ�л���
					  else printf("����ʧ��\n"); break;
			case '0':break;															//�˳��������� 
    		default : printf("��Ч�Ĳ���!");break;									//���û����벻�淶���򵯳���ʾ 
        }
	}while(i);
	return 0;
}

