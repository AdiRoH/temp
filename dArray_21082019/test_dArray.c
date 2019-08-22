#include<stdio.h>
#include<stddef.h>
#include "darrayGeneric.h"

struct Point
{	
	float m_x_coordinate;
	float m_y_coordinate;
}typedef Point;

/*print functions*/
void printError(int res);
int printArr(Point* dpnt);
int UI();

void destroyFunc1(void *_elem, void *context);
/*menu options*/
Point* caseCreate();
void caseDestroyArr(Point* dpnt);
void caseAddNum(Point* dpnt);
void caseDelNum(Point* dpnt);
void caseGet(Point* dpnt);
void caseSet(Point* dpnt);
void returnCurrCapa(Point* dpnt);



typedef enum menu{createArr=1,destroyArr=2,addNumber=3,deleteNumber=4,get=5,set=6,returnSize=7,sortArr=8}menu;


int main()
{
	
	Point* dpnt;
	int opt=10;

	while(opt>0)
	{
		opt=UI();

		switch(opt)
		{
			case createArr:
			{
				dpnt=caseCreate();
				break;
			}

			case destroyArr:
			{
				caseDestroyArr(dpnt);
				break;
			}

			case addNumber:
			{
				caseAddNum(dpnt);
				break;
			}

			case deleteNumber:
			{
				caseDelNum(dpnt);
				break;
			}

			case get:
			{
				caseGet(dpnt);
				break;
			}

			case set:
			{
				caseSet(dpnt);
				break;
			}

			case returnSize:
			{
				returnCurrCapa(dpnt);
				break;	
			}
			/*
			case sortArr:
			{
				res_sortArr=darraySort(darr);
				printError(res_sortArr);
				printArr(darr);
				break;
			}*/
		}
	}
	return 1;
}

Point* caseCreate()
{	
	Point** dpnt;
	size_t size;
	printf("Insert size of array\n\n");
	scanf("%zu",&size);

	printError(darrayCreate(dpnt,size));
	return &dpnt;
}

/*AdtStatus darrayCreate(Darray **dArr, size_t initial_capacity);*/


void caseDestroyArr(Point* dpnt)
{
	FILE *context;
	char nameFile[50];
	printf("Insert name of file\n\n");
	scanf("%s",nameFile);
	context=fopen(nameFile,"a");
	if(context==NULL)
	{
		return NULL;
	}

	darrayDestroy(*dpnt,destroyFunc1,context);

	//printError(darrayDestroy(dpnt,,fp));
}
		
void destroyFunc1(void *_elem, void *context)
{
	
	//ele-struct conte-fp;
	Point* temp;
	temp=(Point*)temp;
	if(_elem==NULL)
	{
		return;
	}

	if(context==NULL)
	{
		return;
	}
	
	fprintf(context,"coordinate X: %d coordinate Y: %d",temp->m_x_coordinate,temp->m_y_coordinate);
	free(temp);
}

void caseAddNum(Point* dpnt)
{
	int itemAdd;
	printf("Type the item that you want to add\n\n");
	scanf("%d",&itemAdd);
	printError(darrayAdd(dpnt,&itemAdd));
	printArr(dpnt);
	
}

void caseDelNum(Point* dpnt)
{
	void** itemDel;
	printError(darrayDelete(dpnt,itemDel));
	/*printArr(dpnt)*/;
}

void caseGet(Point* dpnt)
{
	size_t idxGet;
	void** getItem;
	printf("Insert index of item that you want to get\n\n");
	scanf("%zu",&idxGet);
	printError(darrayGet(dpnt,idxGet, getItem));
	/*printf("the item in index %zu is: %d\n\n",idxGet,getItem);*/
}

void caseSet(Point* dpnt)
{
	void* itemSet;
	size_t idxSet;
	printf("Insert a value of item\n\n");
	scanf("%d",&itemSet);
	printf("Insert index of Item\n\n");
	scanf("%zu",&idxSet);
	printError(darraySet(dpnt, idxSet, itemSet));
	printArr(dpnt);
}

void returnCurrCapa(Point* dpnt)
{	
	int numOfItems=0;
	printError(darrayItemsNum(dpnt, &numOfItems));
	printf("number of elements:  %d\n\n",numOfItems);			
}



void printError(int res)
{
		switch(res)
		{
			case 0:
				{
					printf("\nAllocationError\n\n");
					break;
				}

			case 1:
				{
					printf("\nOK\n\n");
					break;
				}
				
			case 2:
				{
					printf("\nWrongInput\n\n");
					break;
				}
			case 3:
				{
					printf("\nExceedingIDX\n\n");
					break;
				}
			case 4:
				{
					printf("\nAdressERROR\n\n");
					break;
				}
		}

}

int printArr(Point* dpnt)
{
	int i=0;

	if(dpnt==NULL)
		return AllocationError;

	return OK;
}

int UI()
{	
	int opt;
	printf("1:\tcreate array\n\n");
	printf("2:\tdestroy array\n\n");
	printf("3:\tadd a number to the end\n\n");
	printf("4:\tdelete a number from array\n\n");
	printf("5:\tget a number\n\n");
	printf("6:\tset a number\n\n");
	printf("7:\treturn size of arr\n\n");
	printf("8:\tsort the array\n\n");
	scanf("%d",&opt);

	return opt;
}