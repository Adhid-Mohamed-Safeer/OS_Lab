#include <stdio.h>

int mutex = 1;
int empty = 3;
int full = 0;
int item = 0;

void wait(int* s) {
    (*s)--;
}

void signal(int* s) {
    (*s)++;
}

void producer() {
    wait(&mutex);
    signal(&full);
    wait(&empty);
    item++;
    printf("Produced item %d\n", item);
    signal(&mutex);
}

void consumer() {
    wait(&mutex);
    wait(&full);
    signal(&empty);
    printf("Consumed item %d\n", item);
    item--;
    signal(&mutex);
}

int main() {
    int choice;

    printf("Producer Consumer\n");
    printf(" [1] Produce\n");
    printf(" [2] Consume\n");
    printf(" [3] Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (mutex == 1 && empty != 0)
                producer();
            else
                printf("Buffer is full\n");
        } else if (choice == 2) {
            if (mutex == 1 && full != 0)
                consumer();
            else
                printf("Buffer is empty\n");
        } else if (choice == 3) {
            printf("Exiting\n");
            break;
        } else {
            printf("INVALID CHOICE\n");
        }
    }

    return 0;
}