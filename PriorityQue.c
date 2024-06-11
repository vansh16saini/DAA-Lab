#include <stdio.h>
#include <stdbool.h>
#define size_m 100
typedef struct Queue
{
    int arr[size_m];
    int size;
}PQ;
void print(int* arr, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void heapifyUp(PQ *queue, int index)
{
    while (index > 0 && queue->arr[(index - 1) / 2] > queue->arr[index])
    {
        swap(&queue->arr[(index - 1) / 2], &queue->arr[index]);
        index = (index - 1) / 2;
    }
}
void heapifyDown(PQ *queue, int index)
{
    int left, right, smallest;
    while (1)
    {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < queue->size && queue->arr[left] < queue->arr[smallest])
            smallest = left;

        if (right < queue->size && queue->arr[right] < queue->arr[smallest])
            smallest = right;

        if (smallest != index)
        {
            swap(&queue->arr[index], &queue->arr[smallest]);
            index = smallest;
        }
        else
        {
            break;
        }
    }
}
void initializeQueue(PQ *queue)
{
    queue->size = 0;
}
bool isFull(PQ *queue)
{
    return queue->size >= size_m;
}

bool isEmpty(PQ *queue)
{
    return queue->size == 0;
}
void enqueue(PQ *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    queue->arr[queue->size] = value;
    heapifyUp(queue, queue->size++);
}

int dequeue(PQ *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int value = queue->arr[0];
    queue->arr[0] = queue->arr[--queue->size];
    heapifyDown(queue, 0);
    return value;
}
int main()
{
    PQ queue;
    initializeQueue(&queue);

    enqueue(&queue, 3);
    enqueue(&queue, 7);

    printf("Dequeued item: %d\n", dequeue(&queue));
    printf("Dequeued item: %d\n", dequeue(&queue));

    enqueue(&queue, 9);
    enqueue(&queue, 2);

    while (!isEmpty(&queue))
    {
        printf("Dequeued item: %d\n", dequeue(&queue));
    }

    return 0;
}