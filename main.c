#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LEN 10000

static int arr[ARR_LEN];
static int sum = 0;
pthread_mutex_t sum_mutex;

void *routine(void *argp) {
  int temp = *(int *)argp;

  pthread_mutex_lock(&sum_mutex);
  sum += temp;
  pthread_mutex_unlock(&sum_mutex);

  return NULL;
}

int main(void) {
  srand(time(0));
  pthread_mutex_init(&sum_mutex, NULL);

  for (int i = 0; i < ARR_LEN; i++) {
    arr[i] = rand() % 20;
  }

  pthread_t tid[ARR_LEN] = {0};

  for (int i = 0; i < ARR_LEN; i++) {
    pthread_create(&tid[i], NULL, routine, &arr[i]);
  }

  for (int i = 0; i < ARR_LEN; i++) {
    pthread_join(tid[i], NULL);
  }

  printf("Sum = %d\n", sum);

  pthread_mutex_destroy(&sum_mutex);
  return 0;
}
