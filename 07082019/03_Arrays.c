#include<stdio.h>

void printArray(int* arr,int size);
void swap(int* a,int* b);
void bubbleSort(int* arr,int size);
void countZero(int* arr,int size);
void sortEvenOdd(int* arr,int size);
int occurTheMost(int* arr, int size);



int main()
{
	int arr[]={1,5,5,4,3,6,2,0,9},size=8,i,res;
	printArray(arr,size);
	res=occurTheMost(arr,size);
	printf("\n\n");
	
	printf("%d\n",res);
	return 0;
}

void printArray(int* arr,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);
	}
}

void countZero(int* arr,int size)
{
	int i,counter=0;	
	for(i=0;i<size;i++)
	{
		if(arr[i]==0)
		{
			counter++;		
		}
	}
	for(i=0;i<counter;i++)
	{
		arr[i]=0;
	}
	for(i=counter+1;i<size;i++)
	{
		arr[i]=1;
	}
}

void swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void bubbleSort(int *arr,int size)
{
	int i=0,j,sizeCheck=size,counter=0;;
	while(i<sizeCheck)
		for(j=1;j<size;j++)
		{
			if(arr[j-1]>arr[j])
			{
				swap(&arr[j-1],&arr[j]);
				counter++;
			}	
		
			if(counter==0)
			{
				break;
			}
		}

		i++;
		sizeCheck=sizeCheck-1;
}



void sortEvenOdd(int* arr,int size)
{
	int i,j,temp,counter=0;
	for(i=1;i<size;i++)
	{
		if(arr[i]%2==0)
		{
			temp=arr[counter];
			arr[counter]=arr[i];
			for(j=i-1;j>counter;j--)
			{
				arr[j+1]=arr[j];
			}
			counter++;
			arr[counter]==temp;		
		}
	}
}

int occurTheMost(int* arr, int size)
{
	int i,j,val,elementcounter=1,max=0,mostOccur=arr[0],counter=1;	
	for(i=0;i<size;i++)
	{
		counter=1;
		for(j=0;j<size;j++)
		{
			if(arr[j]==arr[i]&&arr[j]!=-1)
			{
				arr[j]==-1;
				counter++;
			}

			if(max<counter)
			{
				max=counter;
				mostOccur=arr[i];
			}
		
		}
	}
	return mostOccur;
}
