#include<stdio.h>
#include "dulinkedList.c"
#include "../head/dulinkedList.h"
#include<stdlib.h>

int main(){  
    int i;     // i����¼���û�����������Ե��ö�Ӧ�������� 
    ElemType n;
    DuLinkedList head=NULL,p1,p2;  // headΪ�����ͷָ�룬p1,p2�ֱ�Ϊ����ָ�� ��ʹheadΪ��ָ���ʾ�������� 
    do{
    	p1 = NULL;p2 = NULL;    //�Ƚ�p1,p2��ʼ�� 
    	printf("�������Ӧ������ִ�ж�Ӧ����\n"); //�˵������� 
		printf("1.�����ʼ��\n"
		       "2.��������\n" 
			   "3.��������\n"
			   "4.����ǰ����������\n"
			   "5.����ǰ����������\n"
			   "6.ɾ�����\n"
			   "7.���ҽ��\n"
			   "8.��������\n"
			   );
		scanf("%d",&i);              //��ȡ�û���Ҫ���õ����� 
    	getchar();
    	switch(i){
    		case 1: if(InitList_DuL(&head)==SUCCESS)printf("�����ɹ��������ѳ�ʼ��\n");  //��ʼ���������� 
			          else printf("����ʧ�ܣ�������\n");break; 
    		case 2: if(CreateList(head)==SUCCESS)printf("�����ɹ��������Ѵ���\n");   //������������ 
    		          else printf("����ʧ�ܣ����������������\n");
			          break;
    		case 3: DestroyList_DuL(&head);printf("����������\n");                       //������������ 
			          break;
			case 4: printf("������Ҫ���ĸ����ݵĽ���ǰ��������:");               //���������� 
			    	  scanf("%d",&n);getchar();										 //�����û����������Ľ������� 
			    	  if(FindList(head,n,&p1)==ERROR){                               //��ִ�в����������Բ��ҽ�㲢��Ŀ���㷵�ظ�p1,���ж������Ƿ񲻴���
					     printf("����ʧ��\n");break;
						 }
			          p2 = Create_a_Node();											 //�����һ���½�� 
			          if(InsertBeforeList_DuL(p1,p2)==SUCCESS)printf("�����ɹ�������ѱ�����\n"); //��������½�㵽Ŀ����ĺ� 
			          else printf("����ʧ��\n");
			    	  break;
			case 5: printf("������Ҫ���ĸ����ݵĽ��ĺ󷽲�����:");               //���������� 
			    	  scanf("%d",&n);getchar();										 //�����û����������Ľ������� 
			    	  if(FindList(head,n,&p1)==ERROR){                               //��ִ�в����������Բ��ҽ�㲢��Ŀ���㷵�ظ�p1,���ж������Ƿ񲻴���
					     printf("����ʧ��\n");break;
						 }
			          p2 = Create_a_Node();											 //�����һ���½�� 
			          if(InsertAfterList_DuL(p1,p2)==SUCCESS)printf("�����ɹ�������ѱ�����\n"); //��������½�㵽Ŀ����ĺ� 
			          else printf("����ʧ��\n");
			    	  break; 
			case 6: printf("�������ɾ���������ݣ�");					//ɾ��ĳ�����ĺ�һ��������� 
					  scanf("%d",&n);getchar();										//����Ҫɾ���Ľ�����Ϣ 
					  if(FindList(head,n,&p1)==ERROR){								//��ִ�в����������Բ��ҽ�㲢����Ŀ���㷵�ظ�p1,���ж������Ƿ񲻴���
					     printf("����ʧ��\n");break;								
						 }
					  if(DeleteList_DuL(p1,&n)==SUCCESS)								//ɾ��Ŀ���ĵ�һ������ 
					  {printf("�����ɹ�������ѱ�ɾ��,��ɾ���Ľ�������Ϊ%d\n",n);}
					  else printf("����ʧ��\n");
					  break;
			case 7: printf("������Ҫ���ҵĽ�������:");							//���ҽ������ 
			 		  scanf("%d",&n);getchar();										//�û���������ҵĽ��
			 		  if(SearchList(head,n)==SUCCESS)printf("�����ɹ����ý�����\n");  //���Ҹý���Ƿ���� 
			 		  else printf("����ʧ��\n"); 
			 		  break;
			case 8: printf("��ʼ��������\n");										//������������ 
			 		  TraverseList_DuL(head,NULL);										//��ʼ�������� 
					  break;
			case '0':break;															//�˳��������� 
    		default : printf("��Ч�Ĳ���!");break;									//���û����벻�淶���򵯳���ʾ 
        }
	}while(i);
	return 0;
}

