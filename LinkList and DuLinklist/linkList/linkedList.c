#include "../head/linkedList.h"
#include <stdlib.h>

/**
 *  @name        : Status CreateList(LinkList head);
 *	@description : create a list with the number that user wants of nodes 
 *	@param		 : p1(the head node)
 *	@return		 : status
 *  @notice      : addtional 
 */
Status CreateList(LinkedList p1){						//此函数用于创建链表 
	if (p1==NULL){ printf("请先初始化链表！\n");        //若用户未初始化链表，则发出提示并返回菜单 
	   return ERROR;
	}
	int i=1;											// i 用于提示用户当前在为第 i 个结点写入数据 
	LinkedList p2=p1;									// p1 用于读取新开辟的结点的位置，p2 用于标志上一结点 
    printf("开始创建链表....(暂时只支持整型)\n"			//提示用户信息并创建链表 
	       "停止创建请输入0\n");
	printf("请输入第%d个结点的数据：",i);				// 提示用户输入第 i 个结点的信息 
	scanf("%d",&p1->data);getchar();
	if(p1->data==0){printf("请至少创建一个结点！\n");	// 若用户创建的结点少于一个，则提示信息并返回菜单 
	         return ERROR;}
	for(i=2;;i++){										//继续创建链表 
	  p1=(LinkedList)malloc(sizeof(LNode));				//p1 读取新开辟的结点的位置
	  if(p1==NULL){										//若节点开辟失败，则提示信息并返回菜单 
	    printf("空间不足!");return ERROR;}
	  p2->next=p1;										//将该结点与上一结点连接起来 
	  printf("请输入第%d个结点的数据：",i);				//提示用户输入结点的信息 
	  scanf("%d",&p1->data);getchar();
	  if(p1->data==0){									//若用户停止创建链表，则把新开辟的结点释放 
	     free(p1);break;}
	  else p2=p1;
	}
	p2->next=NULL;										//将最后一个结点的指针域指向空 
	return SUCCESS;
}

/**
 *  @name        : Status FindList(LinkedList L,ElemType n,LinkedList *p1);
 *	@description : create a list with the number that user wants of nodes 
 *	@param		 : L(the head node) n (the node`s value) p1(return the node we find)
 *	@return		 : Status(whether we can find out this node or not)
 *  @notice      : addtional 
 */
 Status FindList(LinkedList L,ElemType n,LinkedList *p1){//此函数用于寻找链表中的某个结点，并通过二级指针p1返回该结点的位置 
 	if(L==NULL){										 //若结点不存在，提示信息并返回菜单 
	  printf("链表不存在！\n");
	  return ERROR ;}
	*p1=L;												 //初始化p1指针指向的值 
 	while(*p1!=NULL){									 //开始寻找该数据对应的结点是否存在 
 		if((*p1)->data==n)return SUCCESS; 
 		*p1=(*p1)->next;}
 	printf("寻找不到目标结点!\n");
	return ERROR;										 
	 
 }
 
/**
 *  @name        : LinkedList Create_a_Node();
 *	@description : create a list with the number that user wants of nodes 
 *	@param		 : none
 *	@return		 : p2(a list created)
 *  @notice      : addtional 
 */
 LinkedList Create_a_Node(){                         	//此函数用于创造一个新的结点，并让用户输入数据 
 	LinkedList p2;										// p2 用于读取新开辟的结点的指针 
 	p2=(LinkedList)malloc(sizeof(LNode));
 	if(p2==NULL)printf("空间不足！");					//若结点开辟不成功，则提示信息并将p2置为空 
 	return p2;
 }
 
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	*L=(LinkedList)malloc(sizeof(LNode));   // L 读取新开辟的结点的指针 ，并将其传递给主函数的main中的head指针 
	if(*L==NULL) {							//若结点开辟不成功，则提示信息并返回菜单 
	printf("空间不足!");
	return ERROR;}
	else return SUCCESS;
}


/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p1,p2;					  //p1用于读取下一结点，p2用于标记待销毁结点的位置 
	p1=p2=*L;							   
	while(p2!=NULL){					  //开始销毁链表 
		p1=p1->next;					  //p1先移向下一结点 
		free(p2);						  //销毁p2所在结点 
		p2=p1;							  //将p2移向下一个待销毁的结点 						  
	}
	*L=NULL;							  //销毁完成后，将L所指向的指针（即链表的头指针）置为空 
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if(q==NULL)return ERROR;			 //判断该插入点是否存在，不存在则返回菜单 
	q->next=p->next;					 //在 p所指向的结点后插入p所指的结点
	p->next=q;							 
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
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
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
 	if(L==NULL){
	  printf("链表不存在！\n");return ;
	 }
	int i;
 	for(i=1;L!=NULL;L=L->next){
	  printf("%5d",L->data);
	  if(i%5==0)printf("\n");}
	printf("\n");
	printf("操作成功\n");
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e 
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	if(L==NULL){
	printf("链表不存在！");return ERROR;
    }
 	while(L!=NULL){
 		if(L->data==e)return SUCCESS;
 		L=L->next;}
 	printf("寻找不到目标结点!\n");
	return ERROR;
} 

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if(*L==NULL){  printf("链表不存在！\n");
	  return ERROR;
	}
	LinkedList p1,p2,p3;
	p2=p3=*L;
	p1=(*L)->next;
	while(p1!=NULL){
		p2=p1;
		p1=p1->next;
		p2->next=p3;
		p3=p2;
	}
	if(p2==*L)return SUCCESS;
	(*L)->next=NULL;
	*L=p2;
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    LinkedList p1,p2;
    if(L==NULL){
      printf("链表为空！\n");
	  return ERROR;}
	p1=p2=L;
	while(1){
		p1=p1->next;
		if(p1==NULL){printf("链表不存在环\n");
		     return SUCCESS;} 
		else if(p1==p2){
		     printf("链表存在环");
		     return SUCCESS;}
		p1=p1->next;
		if(p1==NULL){printf("链表不存在环\n");
		     return SUCCESS;} 
		else if(p1==p2){
		     printf("链表存在环");
		     return SUCCESS;}
	}
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish 
 */
LNode* ReverseEvenList(LinkedList *L) {
	if(*L==NULL){
      printf("链表为空！\n");
	  return NULL;}
	if((*L)->next==NULL) return *L;
	LinkedList p1,p2,p3,p4;
	int i;
	p1=p2=p3=*L;
	p2=p3->next;
	p1=p2->next;
	for(i=1;p1!=NULL;i++){
		if(p2->data%2==0){
			p3->next=p1;
			p2->next=p3;
			if(i==1)*L=p2;
			p4->next=p2;
			p4=p2;
		}
		else { p4->next=p3;
		   p4=p3;p3=p2;}	
		p2=p1;p1=p1->next;
	}
	if(p2->data%2==0){ p2->next=p3;
	                   p3->next=NULL;
	                   p4->next=p2;
	                 }
	else p2->next=NULL;
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish 
 */
LNode* FindMidNode(LinkedList *L) {
	
}
