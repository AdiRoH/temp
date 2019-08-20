#include<stdlib.h>
#include "header.h"

struct darray
{
	int* arr;
	unsigned int index;
	unsigned int capacity;
	unsigned int initial_capacity;
};

AdtStatus darrayCreate(darray** dArr, size_t initial_capacity)
{
	darray* temp;
	temp=malloc(sizeof(darray*));
	if(temp==NULL)
	{
		return 0;
	}
	
	temp->arr=malloc(sizeof(int)*initial_capacity);
	if(temp->arr==NULL)
	{
		return 0;
	}

	temp->capacity=initial_capacity;

	return 1;
}

AdtStatus darrayDestroy(darray* dArr)
{
	if(dArr==NULL)
	{
		return AllocationError;
	}
	if(dArr->arr==NULL)
	{
		return AllocationError;
	}

	free(dArr->arr);
	free(dArr);
	return OK;
}

AdtStatus darrayAdd(darray* dArr,  int  _item)
{
	if(dArr==NULL)
		return 0;
	if(dArr->arr==NULL)
		return 0;
	
	if(dArr->index==0.75*dArr->capacity)
	{
		int* temp=dArr->arr;	
		dArr->arr=(int*)realloc(dArr,dArr->capacity*2);
		if(dArr->arr==NULL)
		{
			dArr->arr=temp;
			return 0;
		}
	
		dArr->capacity*=2;
	}
	
	dArr->arr[dArr->index]=_item;
	dArr->index+=1;
	return 1;
}

AdtStatus darrayDelete(darray *dArr,  int* _item)
{
	int* temp=dArr->arr;

	if(dArr==NULL)
		return 0;
	if(dArr->arr==NULL)
		return 0;
	*_item=dArr->arr[dArr->index];
	if(dArr->index==dArr->initial_capacity*0.75)
	{
		dArr->arr=(int*)realloc(dArr,dArr->capacity/2);
	}
	if(dArr->arr==NULL)
	{
		dArr->arr=temp;
		return 0;
	}
	dArr->index-=1;
	
	
}

AdtStatus  darrayGet(darray *dArr, size_t _index, int* _item)
{
	if(dArr==NULL)
		return 0;
	if(dArr->arr==NULL)
		return 0;
	if(_item==NULL)
		return 0;

	*_item = dArr->arr[_index];
	return 1;
}

AdtStatus  darraySet(darray *dArr, size_t _index, int  _item)
{
	if(dArr==NULL)
		return 0;
	if(dArr->arr==NULL)
		return 0;

	dArr->arr[_index]=_item;
	return 1;
}

AdtStatus darrayItemsNum(darray *dArr, int*  _numOfItems)
{
	if(dArr==NULL)
		return 0;
	if(dArr->arr==NULL)
		return 0;
	*_numOfItems = dArr->capacity;
}

static int swap(int* arr, int i, int j)
{
	int temp;

	if(arr==NULL)
		return 0;
	temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	return 1;
}

AdtStatus darraySort(darray *dArr)
{
	int i=0,j=0;

	if(dArr==NULL)
		return 0;
	if(dArr->arr==NULL)
		return 0;

	for(i=0;i<dArr->capacity;i++)
	{
		for(j=i;j<dArr->capacity;j++)
		{
			if(dArr->arr[i]<dArr->arr[j])
			{
				swap(dArr->arr,i,j);
			}
		}
	}
}

