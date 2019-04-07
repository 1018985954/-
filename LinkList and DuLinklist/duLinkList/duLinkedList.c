#include "../head/duLinkedList.h"
#include<stdlib.h>

/**
 *  @name        : Status CreateList(DuLinkedList head);
 *	@description : create a list with the number that user wants of nodes 
 *	@param		 : p1(the head node)
 *	@return		 : status
 *  @notice      : addtional 
 */
Status CreateList_Dul(DuLinkedList p1){						//�˺������ڴ������� 
	if (p1==NULL){ printf("���ȳ�ʼ������\n");        //���û�δ��ʼ�������򷢳���ʾ�����ز˵� 
	   return ERROR;
	}
	int i=1;											// i ������ʾ�û���ǰ��Ϊ�� i �����д������ 
	DuLinkedList p2,p3;									// p1 ���ڶ�ȡ�¿��ٵģ���һ���Ľ���λ�ã�p2 ���ڱ�־�м��� ,p3���ڱ�־��һ��� 
    printf("��ʼ��������....(��ʱֻ֧������)\n"			//��ʾ�û���Ϣ���������� 
	       "ֹͣ����������0\n");
	printf("�������%d���������ݣ�",i);				// ��ʾ�û������ i ��������Ϣ 
	scanf("%d",&p1->data);getchar();
	if(p1->data==0){printf("�����ٴ���һ����㣡\n");	// ���û������Ľ������һ��������ʾ��Ϣ�����ز˵� 
	         return ERROR;}
	p3=p2=p1;
	for(i=2;;i++){										//������������ 
	  p1=(DuLinkedList)malloc(sizeof(DuLNode));				//p1 ��ȡ�¿��ٵĽ���λ��
	  if(p1==NULL){										//���ڵ㿪��ʧ�ܣ�����ʾ��Ϣ�����ز˵� 
	    printf("�ռ䲻��!");return ERROR;}				
	  p2->next=p1;										//���¿��Ľ������һ�����������  
	  if(i>2)p2->prior=p3;								//�ٽ���һ��������Ͻ���������� 
	  else p2->prior=NULL;								
	  printf("�������%d���������ݣ�",i);				//��ʾ�û����������Ϣ 
	  scanf("%d",&p1->data);getchar();
	  if(p1->data==0){									//���û�ֹͣ������������¿��ٵĽ���ͷ� 
	     free(p1);break;}
	  else { p3=p2;
	    p2=p1;
	}
	p2->next=NULL;										//�����һ������ָ����ָ��� 
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
	*L=(DuLinkedList)malloc(sizeof(DuLNode));   // L ��ȡ�¿��ٵĽ���ָ�� �������䴫�ݸ���������main�е�headָ�� 
	if(*L==NULL) {							//����㿪�ٲ��ɹ�������ʾ��Ϣ�����ز˵� 
	printf("�ռ䲻��!");
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
	DuLinkedList p1,p2;					  //p1���ڶ�ȡ��һ��㣬p2���ڱ�Ǵ����ٽ���λ�� 
	p1=p2=*L;							   
	while(p2!=NULL){					  //��ʼ�������� 
		p1=p1->next;					  //p1��������һ��� 
		free(p2);						  //����p2���ڽ�� 
		p2=p1;							  //��p2������һ�������ٵĽ�� 						  
	}
	*L=NULL;							  //������ɺ󣬽�L��ָ���ָ�루�������ͷָ�룩��Ϊ��
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(q==NULL)return ERROR;			 //�жϸò�����Ƿ���ڣ��������򷵻ز˵� 
	q->prior=p->prior;					 //�� p��ָ��Ľ������p��ָ�Ľ��� 
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
	if(q==NULL)return ERROR;			 //�жϸò�����Ƿ���ڣ��������򷵻ز˵� 
	q->next=p->next;					 //�� p��ָ��Ľ������p��ָ�Ľ��� 
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
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	
}

