#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define Max_Count  10000
int i = 0;
int j = 0;


void *Counter()
{
    for (;;)
    {

        if (i >= Max_Count)
        {
            return NULL;
        }

        ++i;
        printf("i = %lld\n", i);
    }
}

void *Counter2()
{
    for (;;)
    {

        if (j >= Max_Count)
        {

            return NULL;
        }

        ++j;
        printf("j = %lld\n", j);
    }
}

int main(void)
{
    int i = 0;
    pthread_t thread1,thread2,thread3,thread4,thread5,thread6,thread7;

    system("pause");
    pthread_create(&thread1, NULL, &Counter, NULL); // This now plays both codes simulataneously
    pthread_create(&thread2, NULL, &Counter2, NULL);
    pthread_join(thread1, NULL); // These have to be at the bottom
    pthread_join(thread2, NULL);

    pthread_create(&thread3, NULL, &Counter, NULL);
    pthread_join(thread3, NULL);

    pthread_create(&thread4, NULL, &Counter, NULL);
    pthread_join(thread4, NULL);

    pthread_create(&thread5, NULL, &Counter, NULL);
    pthread_join(thread5, NULL);

    pthread_create(&thread6, NULL, &Counter, NULL);
    pthread_join(thread6, NULL);

    pthread_create(&thread7, NULL, &Counter, NULL);
    pthread_join(thread7, NULL);
}

/* OneThread.c

int main(void)
{
    int i = 0;
    pthread_t thread1;

    pthread_create(&thread1, NULL, &Counter, NULL);
    pthread_join(thread1, NULL);


}
*/

/* SimpleCounter.c

int main(void)
{
    int i = 0;
    Counter ();

}
*/

