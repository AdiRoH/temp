#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
	int opt,numOfMeet;
	Calendar_t* diaryPTR=malloc(sizeof(Calendar_t));
	Meeting_t* meetPTR=malloc(sizeof(Meeting_t));
	printf("Please choose option. to exit type 2\n");
	scanf("%d",&opt);
	while(1)
	{
		switch(opt){
		
			case 1:
				
					printf("Please insert number of meetings\n");
					scanf("%d",&numOfMeet);
					diaryPTR=CreatAD(diaryPTR,numOfMeet);
					/*diaryPTR->meetings=meetPTR;*/
					
					break;
				
			case 2:
				return -1;
		}
	}
	return 0;
}
