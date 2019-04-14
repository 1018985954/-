#include <stdlib.h>

/**
 *  @name        : void outputSort(int *a,int n);
 *  @description : 输出数组 
 *  @param       : 数组指针 a, 数组长度 n
 */
void outputSort(int* head , int n){
	int j;
	for( j=0 ; j < n ; j++)
		printf("%d\t",head[j]);
	printf("\n");
}

/**
 *  @name        : void createtSort(int *a,int n);
 *  @description : 创建数组 
 *  @param       : 数组指针 a, 数组长度 n
 */
 
int* creatSort(int* head , int n)
	{
		int i;
		head = (int *)malloc(n*sizeof(int));
		if(head == NULL ) return head;
		
		for(i = 0; i < n; i++){
			scanf("%d",&head[i]);
		}
		return head ;
	}

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n)
	{	
		if ( a == NULL ) {
			printf("操作失败"); 
			return ; }
		int i , j  ;   		 // i用于找出需要插入的数 ，j用于判断其左边的数是否右移 ,k则用于将其左边的数右移 
		int t1 , t2 ;      			 // t1用于中间变量暂时存放数值 ,t2用于标记下标 
		for(i = 0;i < n; i++ ) 
		{
			t2 = i ;
			for( j = i ; j < n ; j++){
				if( a[j] < a[t2] ){
					t2 = j;
				} 
				t1 = a[t2];
				a[t2] = a[i];
				a[i] = t1 ;
			}
		 } 
	}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int* temp_left = (int* ) malloc(( mid - begin ) * sizeof ( int ));
	int* temp_right = ( int* ) malloc(( end - mid -1 ) * sizeof (int));
	if(temp_left == NULL && temp_right == NULL)printf("操作失败:空间不足");
	int i ,j ,k;
	k = 0;
	for( i = 0 ; i<= mid ; i++) temp_left[i] = a[k++];
	for( j = 0 ; j<= end-mid-1 ; j++) temp_right[j] = a[k++];
	if( mid!=begin ) {
 		MergeArray ( temp_left , 0 , (mid - begin)/2 , mid , NULL);
		}
	if( mid+1!=end ) {
		MergeArray ( temp_right , 0 , (end - mid -1)/2 , end , NULL);
	}
	for( i = 0 , j = 0 , k = 0; i > mid + 1 ; ) {
		if( i > mid ) {
			while( j <= end - mid - 1 ){
				a[k++] = temp_right[j++];
			}
			break;
		}
		if( j > (end - mid - 1) ) {
			while ( i <= mid ){
				a[k++] = temp_left[i++];
			}
			break;
		}
		if( temp_left[i] < temp_right[j] ) a[k++] = temp_right [j++];
		else a[k++] = temp_left[i++];
	}
	free(temp_right);free(temp_left);
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */

