#include <stdio.h>
#include <pthread.h>

#define N 5
#define MAX_PRODUCE 1000

int buffer[N];
int inptr = 0, outptr = 0;
int count = 0;
int total = 0;
static int current = 0;

pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int produce()
{
    if (current > MAX_PRODUCE) return -1;
    return current++;
}

void consume(int data)
{
    if (data == -1) return;
    total += data;
}

void *producer()
{
    int data;
    for (;;) {
        data = produce();
        pthread_mutex_lock(&lock);
        while (count >= N) pthread_cond_wait(&full, &lock);
        buffer[inptr] = data;
        inptr = (inptr + 1) % N;
        count = count + 1;
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&lock);
        if (data == -1) break;
    }
    return NULL;
}

void *consumer()
{
    int data;
    for (;;) {
        pthread_mutex_lock(&lock);
        while (count <= 0) pthread_cond_wait(&empty, &lock);
        data = buffer[outptr];
        outptr = (outptr + 1) % N;
        count = count - 1;
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&lock);
        consume(data);
        if (data == -1) break;        
    }
    return NULL;
}

int main()
{
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    printf("Total: %d\n", total);
    return 0;
}