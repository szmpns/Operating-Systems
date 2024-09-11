#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define num_philosophers 5

pthread_mutex_t forks[num_philosophers];

void* philosopher(void* arg) {
    int id = *((int*)arg);

    while (1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);

        int fork1 = id;
        int fork2 = (id + 1) % num_philosophers;

        pthread_mutex_lock(&forks[fork1]);
        pthread_mutex_lock(&forks[fork2]);
        printf("Philosopher %d picks up forks.\n", id);

        printf("Philosopher %d is eating.\n", id);
        sleep(1);

        printf("Philosopher %d puts down forks.\n", id);
        pthread_mutex_unlock(&forks[fork1]);
        pthread_mutex_unlock(&forks[fork2]);
    }
}

int main(int argc, char* argv[]) {
    // Checking the number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <type> <n>\n", argv[0]);
        return 1;
    }

    int type = atoi(argv[1]);
    int n = atoi(argv[2]);

    if (n < 2 || n > 10) {
        fprintf(stderr, "The number of philosophers should be in the range 2..10.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        pthread_mutex_init(&forks[i], NULL);
    }

    pthread_t philosophers[n];
    int philosopher_ids[n];

    for (int i = 0; i < n; ++i) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }

    for (int i = 0; i < n; ++i) {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < n; ++i) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}