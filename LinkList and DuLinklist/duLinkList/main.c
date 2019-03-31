#include<stdio.h>
#include "dulinkedList.c"
#include "../head/dulinkedList.h"
#include<stdlib.h>

int main(){  
    int i;     // i用于录入用户输入的数据以调用对应的命令行 
    ElemType n;
    DuLinkedList head=NULL,p1,p2;  // head为链表的头指针，p1,p2分别为辅助指针 。使head为空指针表示链表不存在 
    do{
    	p1 = NULL;p2 = NULL;    //先将p1,p2初始化 
    	printf("请输入对应数字以执行对应操作\n"); //菜单的制作 
		printf("1.链表初始化\n"
		       "2.创建链表\n" 
			   "3.销毁链表\n"
			   "4.（在前方）插入结点\n"
			   "5.（在前方）插入结点\n"
			   "6.删除结点\n"
			   "7.查找结点\n"
			   "8.遍历链表\n"
			   );
		scanf("%d",&i);              //读取用户需要调用的命令 
    	getchar();
    	switch(i){
    		case 1: if(InitList_DuL(&head)==SUCCESS)printf("操作成功，链表已初始化\n");  //初始化链表命令 
			          else printf("操作失败，请重试\n");break; 
    		case 2: if(CreateList(head)==SUCCESS)printf("操作成功，链表已创建\n");   //创建链表命令 
    		          else printf("操作失败，请销毁链表后重试\n");
			          break;
    		case 3: DestroyList_DuL(&head);printf("链表已销毁\n");                       //销毁链表命令 
			          break;
			case 4: printf("请输入要在哪个数据的结点的前方插入结点:");               //插入结点命令 
			    	  scanf("%d",&n);getchar();										 //先让用户输入待插入的结点的数据 
			    	  if(FindList(head,n,&p1)==ERROR){                               //先执行查找链表函数以查找结点并将目标结点返回给p1,或判断链表是否不存在
					     printf("操作失败\n");break;
						 }
			          p2 = Create_a_Node();											 //创造出一个新结点 
			          if(InsertBeforeList_DuL(p1,p2)==SUCCESS)printf("操作成功，结点已被插入\n"); //插入这个新结点到目标结点的后方 
			          else printf("操作失败\n");
			    	  break;
			case 5: printf("请输入要在哪个数据的结点的后方插入结点:");               //插入结点命令 
			    	  scanf("%d",&n);getchar();										 //先让用户输入待插入的结点的数据 
			    	  if(FindList(head,n,&p1)==ERROR){                               //先执行查找链表函数以查找结点并将目标结点返回给p1,或判断链表是否不存在
					     printf("操作失败\n");break;
						 }
			          p2 = Create_a_Node();											 //创造出一个新结点 
			          if(InsertAfterList_DuL(p1,p2)==SUCCESS)printf("操作成功，结点已被插入\n"); //插入这个新结点到目标结点的后方 
			          else printf("操作失败\n");
			    	  break; 
			case 6: printf("请输入待删除结点的数据：");					//删除某个结点的后一个结点命令 
					  scanf("%d",&n);getchar();										//输入要删除的结点的信息 
					  if(FindList(head,n,&p1)==ERROR){								//先执行查找链表函数以查找结点并将待目标结点返回给p1,或判断链表是否不存在
					     printf("操作失败\n");break;								
						 }
					  if(DeleteList_DuL(p1,&n)==SUCCESS)								//删除目标后的第一个链表 
					  {printf("操作成功，结点已被删除,被删除的结点的数据为%d\n",n);}
					  else printf("操作失败\n");
					  break;
			case 7: printf("请输入要查找的结点的数据:");							//查找结点命令 
			 		  scanf("%d",&n);getchar();										//用户输入待查找的结点
			 		  if(SearchList(head,n)==SUCCESS)printf("操作成功，该结点存在\n");  //查找该结点是否存在 
			 		  else printf("操作失败\n"); 
			 		  break;
			case 8: printf("开始遍历链表\n");										//遍历链表命令 
			 		  TraverseList_DuL(head,NULL);										//开始遍历链表 
					  break;
			case '0':break;															//退出程序命令 
    		default : printf("无效的操作!");break;									//若用户输入不规范，则弹出提示 
        }
	}while(i);
	return 0;
}

