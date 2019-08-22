#include<stdlib.h>
#include "darrayGeneric.h"

struct Darray
{
	void* m_arr;
	unsigned int m_index;
	unsigned int m_currCapacity;
	unsigned int m_initial_capacity;
};

AdtStatus darrayCreate(Darray **dArr, size_t initial_capacity)
{
	*dArr=(Darray*)malloc(sizeof(Darray));

	if(initial_capacity<=0)
	{
		return WrongInput;
	}

	if(*dArr==NULL)
	{
		return AllocationError;
	}
	
	(*dArr)->m_arr=(void*)malloc(sizeof(void*)*initial_capacity);
	if((*dArr)->m_arr==NULL)
	{
		free(*dArr);
		return AllocationError;
	}


	(*dArr)->m_currCapacity=initial_capacity;
	(*dArr)->m_initial_capacity=initial_capacity;
	(*dArr)->m_index=0;

	return OK;
}

AdtStatus darrayDestroy(Darray* dArr, elementDestroy destroyFunc, void *context)
{
	int i=0;

	if(dArr==NULL)
	{
		return AllocationError;
	}

	if(dArr->m_arr==NULL)
	{
		return AllocationError;
	}
	
	for(i=0;i<dArr->m_currCapacity;i++)
		destroyFunc(dArr->m_arr[i],context);

	free(dArr);
	return OK;
}

AdtStatus darrayAdd(Darray* dArr, void*  _item)
{
	void* temp;

	if(dArr==NULL)
		return AdressError;
	if(dArr->m_arr==NULL)
	{
		return AdressError;
	}
	
	if(_item==NULL)
	{
		return AdressError;
	}

	if(dArr->m_index==0.75*(dArr->m_currCapacity))
	{
		temp=dArr->m_arr;	
		dArr->m_arr=(void*)realloc(dArr->m_arr,(dArr->m_currCapacity)*2);
		if(dArr->m_arr==NULL)
		{
			dArr->m_arr=temp;
			return AllocationError;
		}
	
		(dArr->m_currCapacity)*=2;
	}
	
	dArr->m_arr[dArr->m_index]=_item;
	dArr->m_index++;
	return OK;
}

AdtStatus darrayDelete(Darray *dArr,  void **_item)
{
	void* temp=dArr->m_arr;

	if(dArr->m_index<0)
		return ExceedingIDX;
	if(dArr==NULL)
		return AllocationError;
	if(dArr->m_arr==NULL)
		return AllocationError;
	if(*_item==NULL)
		return AllocationError;

	*_item=dArr->m_arr[dArr->m_index];

	if(dArr->m_index==dArr->m_initial_capacity*0.75)
	{
		dArr->m_arr=(void*)realloc(dArr->m_arr,dArr->m_currCapacity/2);
	}

	if(dArr->m_arr==NULL)
	{
		dArr->m_arr=temp;
		return AllocationError;
	}
	dArr->m_index--;
	return OK;
	
}

AdtStatus  darrayGet(Darray *dArr, size_t _index, void **_item)
{
	if(_index<0)
		return WrongInput;
	if(_index>=dArr->m_currCapacity)
		return ExceedingIDX;
	if(dArr==NULL)
		return AllocationError;
	if(dArr->m_arr==NULL)
		return AllocationError;
	if(**_item==NULL)
		return AllocationError;
	if(*_item==NULL)
		return AllocationError;
	**_item = &dArr->m_arr[_index];
	return OK;
}

AdtStatus  darraySet(Darray *dArr, size_t _index, void*  _item)
{
	if(dArr==NULL)
		return AllocationError;
	if(dArr->m_arr==NULL)
		return AllocationError;
	if(_index<0)
		return WrongInput;
	if(_index>=dArr->m_currCapacity)
		return ExceedingIDX;

	dArr->m_arr[_index]=*(_item);
	return OK;
}

AdtStatus darrayItemsNum(Darray *dArr, int*  _numOfItems)
{
	if(dArr==NULL)
		return AllocationError;
	if(dArr->m_arr==NULL)
		return AllocationError;
	if(_numOfItems==NULL)
		return AllocationError;
	if(*_numOfItems<=0)
		return ExceedingIDX;
	*_numOfItems = dArr->m_currCapacity;
	return OK;
}
/*
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
		return AllocationError;
	if(dArr->arr==NULL)
		return AllocationError;

	for(i=0;i<dArr->currCcapacity;i++)
	{
		for(j=i;j<dArr->currCapacity;j++)
		{
			if(dArr->arr[i]<dArr->arr[j])
			{
				swap(dArr->arr,i,j);
			}
		}
	}

	return OK;
}

