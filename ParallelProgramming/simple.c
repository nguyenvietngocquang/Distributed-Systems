#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int shared = 10;

void * fun(void * args) {
	time_t start = time(NULL);
	time_t end = start + 5; //run for 5 seconds

	printf("time start:\t%ld\n", start);
	while (1) {
		if (time(NULL) >= end)
			break;
		shared++;
	}
	printf("time end:\t%ld\n", end);
	
	return NULL;
}

int main() {
	pthread_t thread_id;

	pthread_create(&thread_id, NULL, fun, NULL);

	pthread_join(thread_id, NULL);

	printf("shared:\t\t%d\n", shared);
	
	return 0;
}