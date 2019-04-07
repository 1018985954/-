#include "../head/linkedList.h"
#include <stdlib.h>

/**
 *  @name        : Status CreateList(LinkList head);
 *	@description : create a list with the number that user wants of nodes 
 *	@param		 : p1(the head node)
 *	@return		 : status
 *  @notice      : addtional 
 */
Status CreateList(LinkedList p1){						//�˺������ڴ������� 
	if (p1==NULL){ printf("���ȳ�ʼ������\n");        //���û�δ��ʼ�������򷢳���ʾ�����ز˵� 
	   return ERROR;
	}
	int i=1;											// i ������ʾ�û���ǰ��Ϊ�� i �����д������ 
	LinkedList p2=p1;									// p1 ���ڶ�ȡ�¿��ٵĽ���λ�ã�p2 ���ڱ�־��һ��� 
    printf("��ʼ��������....(��ʱֻ֧������)\n"			//��ʾ�û���Ϣ���������� 
	       "ֹͣ����������0\n");
	printf("�������%d���������ݣ�",i);				// ��ʾ�û������ i ��������Ϣ 
	scanf("%d",&p1->data);getchar();
	if(p1->data==0){printf("�����ٴ���һ����㣡\n");	// ���û������Ľ������һ��������ʾ��Ϣ�����ز˵� 
	         return ERROR;}
	for(i=2;;i++){										//������������ 
	  p1=(LinkedList)malloc(sizeof(LNode));				//p1 ��ȡ�¿��ٵĽ���λ��
	  if(p1==NULL){										//���ڵ㿪��ʧ�ܣ�����ʾ��Ϣ�����ز˵� 
	    printf("�ռ䲻��!");return ERROR;}
	  p2->next=p1;										//���ý������һ����������� 
	  printf("�������%d���������ݣ�",i);				//��ʾ�û����������Ϣ 
	  scanf("%d",&p1->data);getchar();
	  if(p1->data==0){									//���û�ֹͣ������������¿��ٵĽ���ͷ� 
	     free(p1);break;}
	  else p2=p1;
	}
	p2->next=NULL;										//�����һ������ָ����ָ��� 
	return SUCCESS;
}

/**
 *  @name        : Status FindList(LinkedList L,ElemType n,LinkedList *p1);
 *	@description : create a list with the number that user wants of nodes 
 *	@param		 : L(the head node) n (the node`s value) p1(return the node we find)
 *	@return		 : Status(whether we can find out this node or not)
 *  @notice      : addtional 
 */
 Status FindList(LinkedList L,ElemType n,LinkedList *p1){//�˺�������Ѱ�������е�ĳ����㣬��ͨ������ָ��p1���ظý���λ�� 
 	if(L==NULL){										 //����㲻���ڣ���ʾ��Ϣ�����ز˵� 
	  printf("�������ڣ�\n");
	  return ERROR ;}
	*p1=L;												 //��ʼ��p1ָ��ָ���ֵ 
 	while(*p1!=NULL){									 //��ʼѰ�Ҹ����ݶ�Ӧ�Ľ���Ƿ���� 
 		if((*p1)->data==n)return SUCCESS; 
 		*p1=(*p1)->next;}
 	printf("Ѱ�Ҳ���Ŀ����!\n");
	return ERROR;										 
	 
 }
 
/**
 *  @name        : LinkedList Create_a_Node();
 *	@description : create a list with the number that user wants of nodes 
 *	@param		 : none
 *	@return		 : p2(a list created)
 *  @notice      : addtional 
 */
 LinkedList Create_a_Node(){                         	//�˺������ڴ���һ���µĽ�㣬�����û��������� 
 	LinkedList p2;										// p2 ���ڶ�ȡ�¿��ٵĽ���ָ�� 
 	p2=(LinkedList)malloc(sizeof(LNode));
 	if(p2==NULL)printf("�ռ䲻�㣡");					//����㿪�ٲ��ɹ�������ʾ��Ϣ����p2��Ϊ�� 
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
	*L=(LinkedList)malloc(sizeof(LNode));   // L ��ȡ�¿��ٵĽ���ָ�� �������䴫�ݸ���������main�е�headָ�� 
	if(*L==NULL) {							//����㿪�ٲ��ɹ�������ʾ��Ϣ�����ز˵� 
	printf("�ռ䲻��!");
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
	LinkedList p1,p2;					  //p1���ڶ�ȡ��һ��㣬p2���ڱ�Ǵ����ٽ���λ�� 
	p1=p2=*L;							   
	while(p2!=NULL){					  //��ʼ�������� 
		p1=p1->next;					  //p1��������һ��� 
		free(p2);						  //����p2���ڽ�� 
		p2=p1;							  //��p2������һ�������ٵĽ�� 						  
	}
	*L=NULL;							  //������ɺ󣬽�L��ָ���ָ�루�������ͷָ�룩��Ϊ�� 
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if(q==NULL)return ERROR;			 //�жϸò�����Ƿ���ڣ��������򷵻ز˵� 
	q->next=p->next;					 //�� p��ָ��Ľ������p��ָ�Ľ��
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
	if(p==NULL) return ERROR;			//����㲻���ڣ��򷵻ز˵� 
	LNode *p1,*p2;					    //p1���ڶ�ȡ��ɾ��������һ���,p2���ڶ�ȡp1����һ��� 
	p1=p->next;
	*e=p->data;						//��ȡ��ɾ���������� 
	p2=p1->next; 
	*p=*p1;							//������һ��㵽�ý�� 
	p->next=p2;						//������������ 
	free(p1);					   //ɾ������Ľ�� 
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
	  printf("�������ڣ�\n");return ;
	 }
	int i;
 	for(i=1;L!=NULL;L=L->next){
	  printf("%5d",L->data);
	  if(i%5==0)printf("\n");}
	printf("\n");
	printf("�����ɹ�\n");
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
	printf("�������ڣ�");return ERROR;
    }
 	while(L!=NULL){
 		if(L->data==e)return SUCCESS;
 		L=L->next;}
 	printf("Ѱ�Ҳ���Ŀ����!\n");
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
	if(*L==NULL){  printf("�������ڣ�\n");
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
      printf("����Ϊ�գ�\n");
	  return ERROR;}
	p1=p2=L;
	while(1){
		p1=p1->next;
		if(p1==NULL){printf("�������ڻ�\n");
		     return SUCCESS;} 
		else if(p1==p2){
		     printf("������ڻ�");
		     return SUCCESS;}
		p1=p1->next;
		if(p1==NULL){printf("�������ڻ�\n");
		     return SUCCESS;} 
		else if(p1==p2){
		     printf("������ڻ�");
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
      printf("����Ϊ�գ�\n");
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
