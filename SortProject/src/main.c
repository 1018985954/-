#include<stdio.h>
#include "../inc/qgsort.h"
#include "../src/排序.c"
#include <stdlib.h>

int main(){
	int i = 1, j;
	int n ;
	int *temp = NULL;
	int *head = NULL;
	char *menu[14] = {
		    "1.创建数组",
			"2.插入排序",
		    "3.归并排序（合并数组）" ,
			"4.归并排序",
			"5.快速排序",
			"6.快速排序（非递归版）",
			"7.快速排序（枢轴存放）",
			"8.计数排序",
			"9.基数计数排序",
			"10.颜色排序",
			"11.无序找",
			"12.删除数组",
			"13.查看数组", 
			"0.退出程序"
			    };
	while (i) {
		printf("请输入对应数字以执行对应操作\n"); //菜单的制作
		for( j = 0; j < 13 ; j++)
		{
			printf("%s", menu[j] );
			printf("\t\t"); 
			if( j%2 == 0)printf("\n");
		}
		scanf("%d",&i);getchar();
		switch(i){
			case 1 : { 
				printf("请输入要创建的数组的大小\n");
				scanf("%d",&n); getchar();
				printf("请创建数组(数字之间请用空格分隔)\n");
				head = creatSort ( head ,  n);
				if(head == NULL)printf("操作失败:空间不足");
				else {
					printf("您创建的数组为：\n");
					outputSort( head , n);}
				getchar();
				break;
			case 2 : {
				printf("正在进行插入排序:\n"); 
				insertSort( head , n );
				printf("排序完成，结果如下:\n");
				outputSort( head , n);
				break;
			case 3 : {
				printf("正在进行归并排序\n"); 
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
