#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t lock;

void* inc(void* arg){
    pthread_mutex_lock(&lock);
    int i = *(int*)arg;
    printf("I am thread %d\n", i);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(){
    int N;
    scanf("%d", &N);
    pthread_t ids[N];
    pthread_mutex_init (&lock,NULL);
    int args[N];
    for(int i=0;i<N;i++){
        args[i] = i;
        pthread_create(&(ids[i]), NULL, inc, &(args[i]));
    }
    for(int i = 0; i  < N; i++){
        pthread_join(ids[i], NULL);  // Waits for all threads to finish
    }
    pthread_mutex_destroy(&lock);
    printf("I am the main thread\n");
}