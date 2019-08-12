#ifndef header
 
typedef struct meet
{
	float begin;
	float end;
	int numRoom;
}Meeting_t;

typedef struct calender
{
	Meeting_t *meetings;
}Calendar_t;

Calendar_t* CreatAD(Calendar_t* ptr,int numOfMeet);
Meeting_t* CreateMeet(float M_begin,float M_end,int M_numRoom);
int binarSearch(int float search,first,last);




#endif
