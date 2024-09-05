#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

// Functions
void StartMotor(void);
void StopMotor(void);
void *ConveyorBelt(void);
void *GateSensor(void);

// Conveyor Belt
int Conveyor1 [101] = {0};
int Conveyor2 [101] = {0};
int list = 0;
int list2 = 0;

// Start & Stop Controls
int start = 0;
int pause = 0;
int wait = 0;

// Box Size Sensors
int sizes = 0;
int Sensor1 = 0;
int Sensor2 = 0;

// Box Creator
int build = 0;
int LargeBox = 4;
int SmallBox = 2;
int space = 15;
int spacemax = 15;

// Random Generator
int Random;
int Random2;

void *ConveyorBelt(void)
{

    // Large Box Sensor
    int BoxCount = 0;

    // Display Counters
    int LargeBoxCounter = 0;
    int SmallBoxCounter = 0;
    int TotalBoxCounter = 0;

    srand(time(0));

    // Code Runner
    while (1)
    {
        // Stop & Start
        if (pause == 0)
        {
            // Moving Conveyor Belt
            for (int i = 99; i >= 0; i--)
            {
                Conveyor1[i+1] = Conveyor1[i];  // Moves the value from 1 position to another
                Conveyor2[i+1] = Conveyor2[i];
            }
            Conveyor1[0] = 0; // Keeps the belt from producing several 1s.
            Conveyor2[0] = 0; // Keeps the belt from producing several 1s.

            // Conveyor Belt Display Screen
            system("cls");
            printf("Box Counter");
            printf("\nLarge Box: %d", LargeBoxCounter);
            printf("\nSmall Box: %d", SmallBoxCounter);
            printf("\nTotal: %d", TotalBoxCounter);
            printf("\n\n____________________________________________________________________________________________________\n\n");
            for (list = 0; list < 100; list++) // It prints a line of 0s (000000000000).
            {
                printf("%d", Conveyor1 [list]);
            }
            printf("\n--------------------------|--|----------------------------/-------------------------|---------------\n");
            printf("--------------------------B1-B2---------------------------G-------------------------CS--------------\n");
            printf("--------------------------|--|----------------------------/-------------------------|---------------\n");
            for (list2 = 0; list2 < 100; list2++)
            {
                printf("%d", Conveyor2 [list2]);
            }
            printf("\n____________________________________________________________________________________________________\n");
            if (list == 100 && list2 == 100) // IF the whole list is shown, set the belt printf back to the start.
            {
                list = 0;
                list2 = 0;
            }

            // Start of Code
            printf("\n\n1: Start Motor");
            printf("\n2: Stop Motor");
            printf("\n3: TEST");
            printf("\n4: Exit");
            printf("\n-------------------\nInput: ");
            if (start == 0)
            {
                pause = 1;
            }

            // Spaces + Box Size
            if (Random == 1)
            {
                Random2 = 4;
            }
            if (Random == 2)
            {
                Random2 = 2;
            }


            // Box Creator
            if (space >= spacemax + Random2)
            {
                space = 0; // Resets the Space

                // Conveyor 1 Box
                Random = (rand() % 2) + 1; // Sets the Random Value
                if (Random == 1)
                {
                    for (int i = 0; i < LargeBox; i++) // Creates a large Box
                    {
                        Conveyor1[build] = 1;
                        build++;
                    }
                }
                if (Random == 2)
                {
                    for (int i = 0; i < SmallBox; i++) // Creates a Smalls Box
                    {
                        Conveyor1[build] = 1;
                        build++;
                    }
                }
                build = 0; // Resets Box print Location

                // Conveyor 2 Box
                Random = (rand() % 2) + 1; // Sets the Random Value
                if (Random == 1)
                {
                    for (int i = 0; i < LargeBox; i++) // Creates a large Box
                    {
                        Conveyor2[build] = 1;
                        build++;
                    }
                }
                if (Random == 2)
                {
                    for (int i = 0; i < SmallBox; i++) // Creates a Small Box
                    {
                        Conveyor2[build] = 1;
                        build++;
                    }
                }
                build = 0; // Resets Box print Location

                Random2 = 0; // Resets Random + BoxSpace
            }
            space++; // Increments the box until it reaches the desired space.


            // Large Box Sensor
            if(Conveyor1[17] == 1)
            {
                sizes++;
                Sensor1 = 1;
            }
            if(Conveyor1[21] == 1)
            {
                Sensor2 = 1;
            }
            if(Sensor1 == 1 && Sensor2 == 1 && sizes == 4)
            {
                BoxCount++;
                Sensor1 = 0;
                Sensor2 = 0;
                sizes = 0;
            }


            // Delay Function
            for(int delay = 0; delay < 5000000; delay++)
            {

            }
        }
    }
}


void *Pause_Play(void)
{
    while (1)
    {
        int input;

        scanf("%d", &input);

        switch (input)
        {
          case 1: StartMotor(); /*pause = 0; start = 1;*/ break;
          case 2: StopMotor(); break;
        }
    }
}


void StartMotor(void)
{
    printf("\n----------------------- Motor Start ------------------------\n");
    for(int delay = 0; delay < 500000000; delay++)           // This slows down the speed of the Motor.
    {

    }
    pause = 0;
    start = 1;
    wait = 1;
}


void StopMotor(void)
{
    pause = 1;
    for(int delay = 0; delay < 500000000; delay++)           // This slows down the speed of the Motor.
    {

    }
    printf("\n------------------ Motor Stopped ------------------\n");
    for(int delay = 0; delay < 5000000; delay++)           // This slows down the speed of the Motor.
    {

    }
    printf("Input: ");
}


void *GateSensor (void)
{
    while (1)
    {
        if(Conveyor1[7] == 1)
        {

        }
    }
}


int main()
{

    pthread_t Size1;
    pthread_t Size2;
    pthread_t Size3;
    pthread_create(&Size1, NULL, ConveyorBelt, NULL);
    pthread_create(&Size3, NULL, GateSensor, NULL);
    pthread_create(&Size2, NULL, Pause_Play, NULL);


    pthread_join(Size1, NULL);
    pthread_join(Size2, NULL);
    pthread_join(Size3, NULL);

    return 0;
}
