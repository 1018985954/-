#include <stdlib.h>

/**
 *  @name        : void outputSort(int *a,int n);
 *  @description : ������� 
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void outputSort(int* head , int n){
	int j;
	for( j=0 ; j < n ; j++)
		printf("%d\t",head[j]);
	printf("\n");
}

/**
 *  @name        : void createtSort(int *a,int n);
 *  @description : �������� 
 *  @param       : ����ָ�� a, ���鳤�� n
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
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n)
	{	
		if ( a == NULL ) {
			printf("����ʧ��"); 
			return ; }
		int i , j  ;   		 // i�����ҳ���Ҫ������� ��j�����ж�����ߵ����Ƿ����� ,k�����ڽ�����ߵ������� 
		int t1 , t2 ;      			 // t1�����м������ʱ�����ֵ ,t2���ڱ���±� 
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
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int* temp_left = (int* ) malloc(( mid - begin ) * sizeof ( int ));
	int* temp_right = ( int* ) malloc(( end - mid -1 ) * sizeof (int));
	if(temp_left == NULL && temp_right == NULL)printf("����ʧ��:�ռ䲻��");
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
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */

