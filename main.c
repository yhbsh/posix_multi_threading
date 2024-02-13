#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LEN 1000
#define THREADS_COUNT 20
#define THREAD_RANGE ((ARR_LEN / THREADS_COUNT))

static int arr[ARR_LEN];
static int sum = 0;
pthread_mutex_t sum_mutex;

void *add(void *argp) {

  pthread_mutex_lock(&sum_mutex);

  int start = *(int *)argp;
  for (int i = start; i < start + THREAD_RANGE; i++) {
    sum += arr[i];
  }

  pthread_mutex_unlock(&sum_mutex);

  return NULL;
}

int main(void) {
  fprintf(stderr, "ARR_LEN = %d\nTHREADS_COUNT = %d\nTHREAD_RANGE = %d\n", ARR_LEN, THREADS_COUNT, THREAD_RANGE);

  srand(time(0));
  pthread_mutex_init(&sum_mutex, NULL);

  for (int i = 0; i < ARR_LEN; i++) {
    arr[i] = rand() % 20;
  }

  pthread_t tid[THREADS_COUNT] = {0};

  for (int i = 0; i < THREADS_COUNT; i++) {
    int start = i * THREAD_RANGE;
    printf("start = %d\n", start);

    pthread_create(&tid[i], NULL, add, &start);
  }

  for (int i = 0; i < THREADS_COUNT; i++) {
    pthread_join(tid[i], NULL);
  }

  printf("Sum = %d\n", sum);
  pthread_mutex_destroy(&sum_mutex);

  return 0;
}
