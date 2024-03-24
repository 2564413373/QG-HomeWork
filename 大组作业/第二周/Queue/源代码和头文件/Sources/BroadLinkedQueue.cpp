#include "../Headers/BroadLinkedQueue.h"

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, void* element) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = element;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void* dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return NULL;
    }

    QueueNode* temp = queue->front;
    void* data = temp->data;
    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

void* peek(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return NULL;
    }

    return queue->front->data;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

int size(Queue* queue) {
    int count = 0;
    QueueNode* temp = queue->front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void clear(Queue* queue) {
    QueueNode* temp = queue->front;
    while (temp != NULL) {
        QueueNode* next = temp->next;
        free(temp);
        temp = next;
    }
    queue->front = NULL;
    queue->rear = NULL;
}

int main() {
    Queue* queue = createQueue();

    int element1 = 10;
    enqueue(queue, &element1);

    double element2 = 3.14;
    enqueue(queue, &element2);

    char element3 = 'A';
    enqueue(queue, &element3);

    printf("Queue elements: ");
    while (!isEmpty(queue)) {
        void* element = dequeue(queue);

        if (element != NULL) {
            if (element == &element1) {
                printf("%d ", *(int*)element);
            } else if (element == &element2) {
                printf("%lf ", *(double*)element);
            } else if (element == &element3) {
                printf("%c ", *(char*)element);
            }
        }
    }
    
    clear(queue);
    free(queue);
    printf("\n");
    system("pause");
    return 0;
}
