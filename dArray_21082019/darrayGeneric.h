/****************************************************************************
    Created by: Yuval Shaul.
    Creation date:      12.8.2019
    Description: Dynamic array, that grows and shrinks automatically.
*****************************************************************************/
#ifndef H_DARRAY
#define H_DARRAY
#include <stdlib.h>

typedef enum AdtStatus{AllocationError=0,OK=1,WrongInput=2,ExceedingIDX=3,AdressERROR=4}AdtStatus; 

typedef void (* elementDestroy)(void *_elem, void *context);
typedef int (* elementCompare)(void *_elemA, void *_elemB);

/* forward declaration of the darray type */
typedef struct Darray Darray;

/* Create a new dynamic array. Return its address in d_arr.
   The initial capacity is the number of items that can be stored
   before a new allocation is needed. */
AdtStatus darrayCreate(Darray **dArr, size_t initial_capacity);
AdtStatus darrayDestroy(Darray *dArr, elementDestroy destroyFunc, void *context);

/* Add number to the end. */
AdtStatus   darrayAdd(Darray *dArr,  void  *_item);

/* Delete number from the end, hand-over the deleted item 
   in a variable pointed to by _item */
AdtStatus   darrayDelete(Darray *dArr,  void **_item);

AdtStatus   darrayGet(Darray *dArr, size_t _index, void **_item);
AdtStatus   darraySet(Darray *dArr, size_t _index, void  *_item);
AdtStatus   darrayItemsNum(Darray *dArr, int*  _numOfItems);

/* in place (ascending) sorting an array of size arraySize */
/*AdtStatus darraySort(Point *dPnt); /* correct this !!! */
#endif