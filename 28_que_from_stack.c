#include <stdio.h>
#include <stdlib.h>

int top1 = -1;
int top2 = -1;

void enqueue(int num, int test[], int example[], int n);
void push1(int num, int test[], int n);
void dequeue(int test[], int example[], int n);
void push2(int temp, int example[], int n);
void pop2(int example[], int n);
void peek(int test[], int example[], int n);
void display(int test[], int example[], int n);

int main()
{
    // we need two stacks to implement a queue
    int n;
    printf("what should be the size of the queue?\n");
    scanf(" %d", &n);

    // now we will create two stacks to act as a queue
    int test[n];
    int example[n];

    int choice;
    printf("what do you want to do? enqueue(1) dequeue(2) peek(3) display(4) exit(5)\n");
    scanf(" %d", &choice);

    do
    {
        switch (choice)
        {
        case 1:
            int num;
            printf("what do you want to enqueue?\n");
            scanf(" %d", &num);

            enqueue(num, test, example, n);
            break;
        case 2:
            dequeue(test, example, n);
            break;
        case 3:
            peek(test, example, n);
            break;
        case 4:
            display(test, example, n);
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("please enter valid integer\n");
            break;
        }

        printf("what do you want to do? enqueue(1) dequeue(2) peek(3) display(4) exit(5)\n");
        scanf(" %d", &choice);
    } while (choice != 5);
    return 0;
}

void enqueue(int num, int test[], int example[], int n)
{
    if (top1 == (n - 1))
    {
        printf("overflow\n");
    }
    else
    {
        push1(num, test, n);
        printf("enqueued %d\n", num);
    }
}

void push1(int num, int test[], int n)
{
    top1++;
    test[top1] = num;
}

void dequeue(int test[], int example[], int n)
{
    if (top1 == -1)
    {
        printf("underflow\n");
    }
    else
    {
        int copy_of_top1 = top1;
        for (int i = copy_of_top1; i > -1; i--)
        {
            int temp = test[top1];
            top1--;
            push2(temp, example, n);
        }
        pop2(example, n);
        int copy_of_top2 = top2;
        for (int i = copy_of_top2; i > -1; i--)
        {
            int atemp = example[top2];
            top2--;
            push1(atemp, test, n);
        }
    }
}

void push2(int temp, int example[], int n)
{
    top2++;
    example[top2] = temp;
}

void pop2(int example[], int n)
{
    printf("dequeued %d\n", example[top2]);
    top2--;
}

void peek(int test[], int example[], int n)
{
    if (top1 == -1)
    {
        printf("underflow\n");
    }
    else
    {
        int copy_of_top1 = top1;
        for (int i = copy_of_top1; i > -1; i--)
        {
            int temp = test[top1];
            top1--;
            push2(temp, example, n);
        }
        // pop2(example, n);
        printf("the first element in queue is %d\n", example[top2]);
        int copy_of_top2 = top2;
        for (int i = copy_of_top2; i > -1; i--)
        {
            int atemp = example[top2];
            top2--;
            push1(atemp, test, n);
        }
    }
}

void display(int test[], int example[], int n)
{
    if (top1 == -1)
    {
        printf("underflow\n");
    }
    else
    {
        int copy_of_top1 = top1;
        for (int i = copy_of_top1; i > -1; i--)
        {
            int temp = test[top1];
            top1--;
            push2(temp, example, n);
        }
        // pop2(example, n);
        for (int i = top2; i >= 0; i--)
        {
            printf("the element in queue is %d\n", example[i]);
        }
        int copy_of_top2 = top2;
        for (int i = copy_of_top2; i > -1; i--)
        {
            int atemp = example[top2];
            top2--;
            push1(atemp, test, n);
        }
    }
}