#include "../head/duLinkedList.h"
#include<stdlib.h>

/**
 *  @name        : Status CreateList(DuLinkedList head);
 *	@description : create a list with the number that user wants of nodes 
 *	@param		 : p1(the head node)
 *	@return		 : status
 *  @notice      : addtional 
 */
Status CreateList_Dul(DuLinkedList p1){						//此函数用于创建链表 
	if (p1==NULL){ printf("请先初始化链表！\n");        //若用户未初始化链表，则发出提示并返回菜单 
	   return ERROR;
	}
	int i=1;											// i 用于提示用户当前在为第 i 个结点写入数据 
	DuLinkedList p2,p3;									// p1 用于读取新开辟的，下一结点的结点的位置，p2 用于标志中间结点 ,p3用于标志上一结点 
    printf("开始创建链表....(暂时只支持整型)\n"			//提示用户信息并创建链表 
	       "停止创建请输入0\n");
	printf("请输入第%d个结点的数据：",i);				// 提示用户输入第 i 个结点的信息 
	scanf("%d",&p1->data);getchar();
	if(p1->data==0){printf("请至少创建一个结点！\n");	// 若用户创建的结点少于一个，则提示信息并返回菜单 
	         return ERROR;}
	p3=p2=p1;
	for(i=2;;i++){										//继续创建链表 
	  p1=(DuLinkedList)malloc(sizeof(DuLNode));				//p1 读取新开辟的结点的位置
	  if(p1==NULL){										//若节点开辟失败，则提示信息并返回菜单 
	    printf("空间不足!");return ERROR;}				
	  p2->next=p1;										//将新开的结点与上一结点连接起来  
	  if(i>2)p2->prior=p3;								//再讲上一结点与上上结点连接起来 
	  else p2->prior=NULL;								
	  printf("请输入第%d个结点的数据：",i);				//提示用户输入结点的信息 
	  scanf("%d",&p1->data);getchar();
	  if(p1->data==0){									//若用户停止创建链表，则把新开辟的结点释放 
	     free(p1);break;}
	  else { p3=p2;
	    p2=p1;
	}
	p2->next=NULL;										//将最后一个结点的指针域指向空 
	p2->prior=p3; 
	return SUCCESS;
}

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	*L=(DuLinkedList)malloc(sizeof(DuLNode));   // L 读取新开辟的结点的指针 ，并将其传递给主函数的main中的head指针 
	if(*L==NULL) {							//若结点开辟不成功，则提示信息并返回菜单 
	printf("空间不足!");
	return ERROR;}
	else return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p1,p2;					  //p1用于读取下一结点，p2用于标记待销毁结点的位置 
	p1=p2=*L;							   
	while(p2!=NULL){					  //开始销毁链表 
		p1=p1->next;					  //p1先移向下一结点 
		free(p2);						  //销毁p2所在结点 
		p2=p1;							  //将p2移向下一个待销毁的结点 						  
	}
	*L=NULL;							  //销毁完成后，将L所指向的指针（即链表的头指针）置为空
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(q==NULL)return ERROR;			 //判断该插入点是否存在，不存在则返回菜单 
	q->prior=p->prior;					 //在 p所指向的结点后插入p所指的结点后 
	p->prior=q;
	q->prior->next=q;
	q->next=p;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(q==NULL)return ERROR;			 //判断该插入点是否存在，不存在则返回菜单 
	q->next=p->next;					 //在 p所指向的结点后插入p所指的结点后 
	p->prior=q;
	q->prior=p;
	p->next=q;
								 
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if(p==NULL) return ERROR;			//若结点不存在，则返回菜单 
	LNode *p1,*p2;					    //p1用于读取被删除结点的下一结点,p2用于读取p1的下一结点 
	p1=p->next;
	*e=p->data;						//读取待删除结点的数据 
	p2=p1->next; 
	*p=*p1;							//复制下一结点到该结点 
	p->next=p2;						//重新连接链表 
	free(p1);					   //删除多余的结点 
	return SUCCESS;
}
 
/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	
}

