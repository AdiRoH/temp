#include<stdio.h>
#include "header.h"

int main()
{
	int opt,size,res;
	darray* darr;

	typedef enum menu{createArr=1,destroyArr=2,addNumber=3,deleteNumber=4,get=5,set=6,returnSize=7,sortArr=8}menu;
	

	while(opt>0)
	{
		printf("1:\tcreate array\n\n");
		printf("2:\tdestroy array\n\n");
		printf("3:\tadd a number to the end\n\n");
		printf("4:\tdelete a number from array\n\n");
		printf("5:\tget a number\n\n");
		printf("6:\tset a number\n\n");
		printf("7:\treturn size of arr\n\n");
		printf("8:\tsort the array\n\n");
		scanf("%d",&opt);
		
		switch(opt)
		{
			case createArr:
			{
				printf("Insert size of array\n\n");
				scanf("%d",&size);
				res=darrayCreate(&darr, size);
				printf("%d\n\n",res);
				break;
			}
			case destroyArr:
			{
				res = darrayDestroy(darr);
				printf("%d\n\n",res);
				break;
			}
			case addNumber:
			{

			}
			case deleteNumber:
			{

			}
			case get:
			{

			}
			case set:
			{

			}
			case returnSize:
			{

			}
			case sortArr:
			{

			}
		}
	}
	return 1;
}
