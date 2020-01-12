#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MAXSTACK 20

typedef enum{TRUE,FALSE} Boolean;

int count=0;
int pop1,pop2;      //No.of Elements in Queue

typedef struct Stackone{
    int top1;
    int data1[MAXSTACK];
}stack1;

typedef struct Stacktwo{
    int top2;
    int data2[MAXSTACK];
}stack2;

void CreateStack(stack1 *S1,stack2 *S2)
{
    S1->top1=-1;
    S2->top2=-1;
}

Boolean IsStackFull(stack1 *S1)
{
    return(S1->top1 == MAXSTACK-1);
}

Boolean IsStackEmpty(stack1 *S1)
{
    return(S1->top1 == -1);
}

void Pop1(stack1 *S1,int *x)
{
    *x=pop1=S1->data1[S1->top1];
    (S1->top1)--;
}

void Pop2(stack2 *S2,int *x)
{
    *x=pop2=S2->data2[S2->top2];
    (S2->top2)--;
}

void Push1(stack1 *S1,int x)
{
    S1->top1++;
    S1->data1[S1->top1]=x;
}

void Push2(stack2 *S2,int x)
{
    S2->top2++;
    S2->data2[S2->top2]=x;
}

void EnQueue(stack1 *S1,int x)
{
    if(IsStackFull(S1))
    {
        printf("Queue is FULL !!!");
    }
    else
    {
        Push1(S1,x);
    }
    count++;
}

void DeQueue(stack1 *S1,stack2 *S2,int *x)
{
    int i;
    if(IsStackEmpty(S1))
    {
        printf("Queue is Empty !!!");
    }
    else
    {
        for(i=1;i<count;i++)
        {
            Pop1(S1,*x);
            Push2(S2,pop1);
        }
        Pop1(S1,*x);
        printf("\nRemoved Element is %d\n",pop1);
        count--;
        for(i=0;i<count;i++)
        {
            Pop2(S2,*x);
            Push1(S1,pop2);
        }
    }
}

void DisplayQueue(stack1 *S1)
{
    int i;
    for(i=0;i<=S1->top1;i++)
    {
        printf("%d ",S1->data1[i]);
    }
}

void Swap(int *xp, int *yp)
{
    int swap = *xp;
    *xp = *yp;
    *yp = swap;
}

void BubbleSort(stack1 *S1)
{
   int i, j;
   for (i = 0; i < count-1; i++){
       for (j = 0; j < count-i-1; j++){
           if (S1->data1[j] > S1->data1[j+1]){
              Swap(&S1->data1[j], &S1->data1[j+1]);
           }
       }
   }

   for(i=0;i<count;i++){
        printf("%d ",S1->data1[i]);}
}

int LinearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void main()
{
    stack1 S1;
    stack2 S2;
    CreateStack(&S1,&S2);
    int x,search;
    EnQueue(&S1,78);
    EnQueue(&S1,56);
    EnQueue(&S1,100);
    EnQueue(&S1,66);
    EnQueue(&S1,91);
    EnQueue(&S1,64);
    EnQueue(&S1,87);
    EnQueue(&S1,52);
    EnQueue(&S1,94);
    EnQueue(&S1,33);
    printf("Queue Is:\n");
    DisplayQueue(&S1);
    printf("\n\nNo.of Elements in QUEUE: %d",count);
    printf("\n\nRemoving An Element [First IN First OUT]..........\n");
    DeQueue(&S1,&S2,&x);
    printf("\nQueue Is:\n");
    DisplayQueue(&S1);
    printf("\n\nNo.of Elements in QUEUE: %d",count);
    printf("\n\nSorted Queue Is:\n");
    BubbleSort(&S1);
    printf("\n\n");

    /*
    printf("Enter an Element to search: ");scanf("%d",&search);
    int result=LinearSearch(S1.data1,count,search);
    if (result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found.");
    */
    //Can you find what is the error in this Searching Process?????
}
