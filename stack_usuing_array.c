#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack_arr[MAX];
int first = -1;

int isFull(){
    if(first == MAX-1)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if(first == -1)
        return 1;
    else
        return 0;
}

void push(int data){
    if (isFull())
    {
        printf("stack overflow\n");
        exit(1);
    }

    first +=1;
    for (int i = first; i > 0; i--)
    {
        stack_arr[i] = stack_arr[i-1];
    }
    stack_arr[0] = data;

}

int pop(){

    int val = stack_arr[0];
     if (isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    
    for (int i = 0; i < first; i++)

        stack_arr[i] = stack_arr[i+1];

    first -=1;
    return val;
}

int peek(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack_arr[0];
}


void print(){
    if(first == -1){
        printf("stack underflow\n");
    }
    for (int i = 0; i <= first; i++)
    {
        printf("%d ",stack_arr[i]);
    }

}
int main(){
    int b,data, choice;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top most element\n");
        printf("4. Show all element\n");
        printf("5. Quit\n");
        printf("Enter The Choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d",&data);
            push(data);
            break;

        case 2:
            printf("Enter the element to be pushed: ");
            data = pop();
            printf("The deleted element is: %d", b);
            break;

        case 3:
            b = peek();
            printf("The Top element is: %d", b);
            break;

        case 4:
            printf("All Element is: ");
            print();
            printf("\n");
            break;

        case 5:
            exit(1);
            break;

        default:
            printf("Wrong choice\n");
            break;
        }
        }

    return 0;


}
