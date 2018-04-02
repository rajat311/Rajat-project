#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t s;
void *F2()
{
	sem_wait(&s);
	printf("\nThis is F2 ran by T2\n\n");
	sem_post(&s);
}
void *F1()
{
	sem_wait(&s);
	printf("\nThis is F1 running by thread T1");
	pthread_t T2;
	printf("\nCreating Thread T2");
	pthread_create(&T2,NULL,F2,NULL);
	printf("\nThread T2 created");
	sem_post(&s);
}
void *fa()
{
	sem_wait(&s);
	printf("\nThis is fa\n");
	sleep(1);
	sem_post(&s);
}
void *fb()
{
	sem_wait(&s);
	printf("\nThis is fb\n");
	sleep(1);
	sem_post(&s);

}
void *fc()
{
	sem_wait(&s);
	printf("\nThis is fc\n");
	sleep(1);
	sem_post(&s);
	
}
int main()
{
	sem_init(&s,0,1);
	pthread_t T1;
	pthread_t T2;
	pthread_create(&T1,NULL,F1,NULL);
	printf("\nthread T1 is created");
	pthread_join(T1,NULL);
	printf("\nthread T2 is calling fa");
	pthread_create(&T2,NULL,fa,NULL);
	pthread_join(T2,NULL);
	printf("\nthread T1 is calling fb");
	pthread_create(&T1,NULL,fb,NULL);
	pthread_join(T1,NULL);
	printf("\nthread T2 is calling fc");
	pthread_create(&T2,NULL,fc,NULL);
	pthread_join(T2,NULL);
	
}