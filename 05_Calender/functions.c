#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*
struct meet
{
	float begin;
	float end;
	int numRoom;
};


struct calender
{
	Meeting_t *meetings;
};
*/



Calendar_t* CreatAD(Calendar_t* ptr,int numOfMeet)
{
	Calendar_t* p=ptr;
	ptr->meetings=(Meeting_t*)realloc(ptr->meetings,(numOfMeet*2)*sizeof(Meeting_t));
	if(ptr==NULL) 
	{
		ptr=p;	
	}
	return ptr;	
}


Meeting_t* CreateMeet(float M_begin,float M_end,int M_numRoom)
{
	Meeting_t* meet;
	if(M_begin>=M_end)
		return NULL;
	meet=malloc(sizeof(meet));
	if(meet==NULL)
		return NULL;
	meet->begin=M_begin;
	meet->end=M_end;
	meet->numRoom=M_numRoom;
	return meet; 
}

int binarSearch(int float search,first,last)
{
	int middle = (first+last)/2,res;
 
    while (first <= last) 
    {
      if (middle < search)
      {
         first = middle + 1;
      }    
      else if (middle == search) 
      {
         res=1;
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (first > last)
      res=0;
   return res;
}

void Insert(Calendar_t* ptr,numOfMeet)
{
	int i,count_meet=0,betweenMeet,j;
	for(i=0;i<numOfMeet)
	{
		if(count_meet==0)
		{
			//insert the array
		}
		
		for(j=i-1;j>=0lj--)
		{
			betweenMeet=binarSearch(ptr->meetings[counter]->begin);
		}
		
	}		
}





