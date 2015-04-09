#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 100

void quicksort(int *a,int left,int right);//快速排序的声明
void findMM(int a[],int *max,int *min,int low,int high);//寻找最大最小值的声明

void findMM(int a[],int *max,int *min,int low,int high)
{	
	if(low >= high)
	{	
		if(*max < a[low])	*max = a[low];
		if(*min > a[low])	*min = a[low];
		return;
	}
	findMM(a,max,min,low,low+(high-low)/2);
	findMM(a,max,min,low+(high-low)/2+1,high);
}

void quicksort(int *a,int left,int right)//从小到大排列
{
	int i = left,j=right,temp=a[left];//定义一个临时变量来存储当前的轴值
	if(left>=right) return; //如果左边的数大于右边就带表排完一组了
	while(i<j)
	{
		while(i<j && temp<=a[j]) j--;//控制在组内寻找一遍，右边的应该比轴值大，如果找到
		//一个小于轴值的就往前交换
		a[i] = a[j];
		while(i<j&& temp>=a[i]) i++;//从左向右寻找比轴值大的数
		a[j] = a[i];
	}
	a[i] = temp;//将暂存的轴值存放到相应的位置上
	quicksort(a,left,i-1);//递归遍历左边
	quicksort(a,i+1,right);	//递归遍历右边
}

int main(int argc, char const *argv[])
{
	int i = 0,max,min;
	int Data[MAXSIZE];
    srand((unsigned)time(NULL));//生成种子
	for(i=0;i<MAXSIZE;i++)
	{
		Data[i] = rand() %100 +1;//生成1-100之间的随机数
	}
	

	for(i=0;i<MAXSIZE;i++)
	{
		if(i!=0 && i%5 == 0)
		{
			printf("\n");
		}
		printf("%4d",Data[i]);
	}

	printf("\n\n+++++++++++++++++++++++++\n\n");
	//先排序后输出方便看出最大值和最小值
	quicksort(Data,0,MAXSIZE-1);
	for(i=0;i<MAXSIZE;i++)
	{
		if(i!=0 && i%5 == 0)
		{
			printf("\n");
		}
		printf("%4d",Data[i]);
	}

	max = min = Data[0];
	findMM(Data,&max,&min,0,MAXSIZE);

	printf("\n最大值是：%d\n最小值是：%d\n",max,min);
	return 0;
}
