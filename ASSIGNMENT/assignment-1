#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void insert(int value)
{
 
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue Overflow! Buffer is full.\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    printf("Request %d inserted.\n", value);
}

void deleteRequest()
{
    int value;

    if (front == -1)
    {
        printf("Queue Underflow! Buffer is empty.\n");
        return;
    }

    value = queue[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }

    printf("Request %d deleted.\n", value);
}
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Requests in Circular Queue: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    insert(101);
    insert(102);
    insert(103);
    insert(104);
    insert(105);

    display();
    insert(106);

    deleteRequest();
    deleteRequest();

    display();
    insert(106);
    insert(107);

    display();
    deleteRequest();
    deleteRequest();
    deleteRequest();
    deleteRequest();
    deleteRequest();
    display();

  
    deleteRequest();

    return 0;
}


