#include<stdio.h>
#include "../inc/qgsort.h"
#include "../src/����.c"
#include <stdlib.h>

int main(){
	int i = 1, j;
	int n ;
	int *temp = NULL;
	int *head = NULL;
	char *menu[14] = {
		    "1.��������",
			"2.��������",
		    "3.�鲢���򣨺ϲ����飩" ,
			"4.�鲢����",
			"5.��������",
			"6.�������򣨷ǵݹ�棩",
			"7.�������������ţ�",
			"8.��������",
			"9.������������",
			"10.��ɫ����",
			"11.������",
			"12.ɾ������",
			"13.�鿴����", 
			"0.�˳�����"
			    };
	while (i) {
		printf("�������Ӧ������ִ�ж�Ӧ����\n"); //�˵�������
		for( j = 0; j < 13 ; j++)
		{
			printf("%s", menu[j] );
			printf("\t\t"); 
			if( j%2 == 0)printf("\n");
		}
		scanf("%d",&i);getchar();
		switch(i){
			case 1 : { 
				printf("������Ҫ����������Ĵ�С\n");
				scanf("%d",&n); getchar();
				printf("�봴������(����֮�����ÿո�ָ�)\n");
				head = creatSort ( head ,  n);
				if(head == NULL)printf("����ʧ��:�ռ䲻��");
				else {
					printf("������������Ϊ��\n");
					outputSort( head , n);}
				getchar();
				break;
			case 2 : {
				printf("���ڽ��в�������:\n"); 
				insertSort( head , n );
				printf("������ɣ��������:\n");
				outputSort( head , n);
				break;
			case 3 : {
				printf("���ڽ��й鲢����\n"); 
				MergeArray( head , 0 , (n-1)/2 , n-1 , temp );
				outputSort( head , n);
				break;
			}
			}
			}
		} 
	}
	return 0;
}
