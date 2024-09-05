/*
    JESSE & AMAAN CONVEYOR BELT CODE
*/

// Library
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include "cinterface.h"

// Functions
void StartMotor(void);
void StopMotor(void);
void End(void);
void *ConveyorBelt(void);
void *Menu(void);


// Conveyor Belt
int Conveyor1 [101] = {0};
int Conveyor2 [101] = {0};
int list = 0;
int list2 = 0;
int hide = 0;

// Start & Stop Controls
int start = 0;
int pause = 0;
int reset = 0;
int wait = 0;
int wait2 = 0;

// Box Size Sensors
int sizes = 0;
int sizes2 = 0;
int Sensor1 = 0;
int Sensor2 = 0;
int Sensor3 = 0;
int Sensor4 = 0;

// Sorting Gates
int state;
int state2;
char symbol[2] = {'/','|'};
char symbol2[2] = {'/','|'};
int Gate = 0;
int control = 0;
int control2 = 0;
int GateCount = 33;
int GateCount2 = 33;
int counter = 0;
int counter2 = 0;
int Boxstore[101];
int a = 1;
int b = 1;
int SmallCheck1 = 0;
int SmallCheck2 = 0;

// Box Creator
int build = 0;
int LargeBox = 4;
int SmallBox = 2;
int space = 15;
int spacemax = 15;

// Display Counters
int LargeBoxDetected1 = 0;
int SmallBoxDetected1 = 0;
int LargeBoxDetected2 = 0;
int SmallBoxDetected2 = 0;
int LargeBoxSum1 = 0;
int SmallBoxSum1 = 0;
int LargeBoxSum2 = 0;
int SmallBoxSum2 = 0;
int TotalBoxCounter = 0;
int TotalBoxDetected = 0;
int CountSensor = 0;
int button = 0;
int input2;

// Random Generator
int Random;
int Random2;


void *ConveyorBelt(void)
{
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

            if (hide != 1)
            {
            // Gates
            if (GateCount < 18)
            {
                printf("\nGate (Conveyor 1): OPEN     /");
            }
            else
            {
                printf("\nGate (Conveyor 1): CLOSED   |");
            }

            if (GateCount2 < 18)
            {
                printf("\nGate (Conveyor 2): OPEN     /");
            }
            else
            {
                printf("\nGate (Conveyor 2): CLOSED   |");
            }

            printf("\n\n____________________________________________________________________________________________________");
            printf("\n____________________________________________________________________________________________________\n\n");
            for (list = 0; list < 100; list++) // It prints a line of 0s (000000000000).
            {
                printf("%d", Conveyor1 [list]);
            }
            printf("\n                          |  |                            %c                         |               \n", symbol[a]);
            printf("                          S1 S2                           SG                        CS              \n");
            printf("                          |  |                            %c                         |               \n", symbol[b]);
            for (list2 = 0; list2 < 100; list2++)
            {
                printf("%d", Conveyor2 [list2]);
            }
            printf("\n____________________________________________________________________________________________________");
            printf("\n____________________________________________________________________________________________________\n\n");
            if (list == 100 && list2 == 100) // IF the whole list is shown, set the belt printf back to the start.
            {
                list = 0;
                list2 = 0;
            }
            }

            // Menu
            if (button == 0)
            {
                printf("\n\n------------ Menu ------------");
                printf("\n1: Start Motor");
                printf("\n2: Stop Motor");
                printf("\n\n---- Start Motor First ----");
                printf("\n3: Hide/Show Conveyor Belt");
                printf("\n4: Large Box Counter");
                printf("\n5: Small Box Counter");
                printf("\n6: Reset Box Counter");
                printf("\n7: Reset Sensors");
                printf("\n8: Exit");
                printf("\n-------------------\nInput: ");
            }
            if (button == 1)
            {
                Display_LargeBox(LargeBoxSum1,LargeBoxSum2,CountSensor);
            }
            if (button == 2)
            {
                Display_SmallBox(SmallBoxSum1,SmallBoxSum2);
            }

            // Start of Code
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


            // Box Size Function
            state = ReadSizeSensor('1',&Conveyor1,&Conveyor2,26,29);
            state2 = ReadSizeSensor('2',&Conveyor1,&Conveyor2,26,29);


            // Gate System
            if (state != 3 || state2 != 3) // if Box is small (1  0) (0  1)
            {
                Gate = 0; // CLOSED
            }
            if (state == 3) // if LargeBox on Conveyor 1 (1  1)
            {
                Gate = 1; // Conv1 OPEN
                GateCount = 33;
                control = 1;
            }
            if (state2 == 3) // if LargeBox on Conveyor 2 (1  1)
            {
                Gate = 2; // Conv2 OPEN
                GateCount2 = 33;
                control2 = 1;
            }
            if (state == 3 && state2 == 3) // if LargeBox on Conveyor 1 & 2
            {
                Gate = 3; // Conv1 & 2 OPEN
            }


            // Large Box Sensor (Conveyor 1)
            if (Conveyor1[26] == 0 || Conveyor1[29] == 0)
            {
                Sensor1 = 0;
                Sensor2 = 0;
            }
            if(Conveyor1[26] == 1)
            {
                Sensor1 = 1;
            }
            if(Conveyor1[29] == 1)
            {
                Sensor2 = 1;
            }
            if(Conveyor1[26] == 1 && Conveyor1[29] == 1)
            {
                LargeBoxSum1++;
                LargeBoxDetected1++;
                SmallCheck1 = -1;
            }


            // Large Box Sensor (Conveyor 2)
            if (Conveyor2[26] == 0 || Conveyor2[29] == 0)
            {
                Sensor3 = 0;
                Sensor4 = 0;
            }
            if(Conveyor2[26] == 1)
            {
                Sensor3 = 1;
            }
            if(Conveyor2[29] == 1)
            {
                Sensor4 = 1;
            }
            if(Sensor3 == 1 && Sensor4 == 1)
            {
                LargeBoxSum2++;
                LargeBoxDetected2++;
                SmallCheck2 = -1;
            }

            // Small Box Sensor (Conveyor 1)
            if (Conveyor1[26] == 1)
            {
                SmallCheck1++;
            }
            if (Conveyor1[26] == 0 && SmallCheck1 == 2 && Conveyor1[29] == 0)
            {
                SmallBoxSum1++;
                SmallBoxDetected1++;
                SmallCheck1 = 0;
            }

            // Small Box Sensor (Conveyor 2)
            if (Conveyor2[26] == 1)
            {
                SmallCheck2++;
            }
            if (Conveyor2[26] == 0 && SmallCheck2 == 2 && Conveyor2[29] == 0)
            {
                SmallBoxSum2++;
                SmallBoxDetected2++;
                SmallCheck2 = 0;
            }

            // Sorting Gates
            if(Gate == 0) // State0: Nothing is in the Sensors (CLOSED)
            {
                if (wait < 18)
                {
                    Conveyor1[58] = 0;
                }
                if (wait2 < 18)
                {
                    Conveyor2[58] = 0;
                }
            }
            else if(Gate == 1) // State1: Conv1 Sensed LargeBox (OPEN)
            {
                Conveyor1[58] = Conveyor1[58];
            }
            else if(Gate == 2) // State2: Conv2 Sensed LargeBox (OPEN)
            {
                Conveyor2[58] = Conveyor2[58];
            }
            else if(Gate == 3) // State3: Conv1&2 Sensed LargeBox (OPEN)
            {
                Conveyor1[58] = Conveyor1[58];
                Conveyor2[58] = Conveyor2[58];
            }

            // FINAL Gate Check Conveyor1 (29 + 4 tick wait period)
            if (control == 1 && GateCount > 0) //29
            {
                GateCount--;
                wait++;
                if (GateCount < 18)
                {
                    Conveyor1[58] = Conveyor1[58];
                    a = 0;
                }
            }
            if (GateCount == 0)
            {
                GateCount = 33;
                wait = 1;
                control = 0;
                a = 1;
            }

            // FINAL Gate Check Conveyor2 (29 + 4 tick wait period)
            if (control2 == 1 && GateCount2 > 0) //29
            {
                GateCount2--;
                wait2++;
                if (GateCount2 < 18)
                {
                    Conveyor2[58] = Conveyor2[58];
                    b = 0;
                }
            }
            if (GateCount2 == 0)
            {
                GateCount2 = 33;
                wait2 = 1;
                control2 = 0;
                b = 1;
            }

            // Count Sensor
            if (Conveyor1[85] == 1)
            {
                counter++;
                if (counter == 4)
                {
                    CountSensor++;
                    counter = 0;
                }
            }

            if (Conveyor2[85] == 1)
            {
                counter2++;
                if (counter2 == 4)
                {
                    CountSensor++;
                    counter2 = 0;
                }
            }

            // Total
            TotalBoxDetected = LargeBoxDetected1 + LargeBoxDetected2;

            // Delay Function
            int number = 5000000;
            for(int delay = 0; delay < number; delay++)
            {

            }
        }
    }
}

int button2 = 0;
void *Menu(void)
{
    while (1)
    {
        int input;

        scanf("%d", &input);

        switch (input)
        {
          case 1: StartMotor(); break;
          case 2: StopMotor(); break;
          case 3: if (start == 1)
                    {hide++; if (hide > 1) {hide = 0;}} break;
          case 4: if (start == 1)
                    {button++; if (button > 1) {button = 0;}} break;
          case 5:   if (start == 1)
                    {button = 2; button2++; if (button2 > 1) {button = 0; button2 = 0;}} break;
          case 6: usleep(500000); pause = 1; usleep(50000); ResetCount(&LargeBoxSum1,&LargeBoxSum2,&SmallBoxSum1,&SmallBoxSum2); CountSensor = 0; usleep(1000000); if (start == 1) {pause = 0;} break;
          case 7: usleep(500000); pause = 1; usleep(50000); ResetSensors(&LargeBoxDetected1,&LargeBoxDetected2,&SmallBoxDetected1,&SmallBoxDetected2); TotalBoxDetected = 0; usleep(1000000); if (start == 1) {pause = 0;} break;
          case 8: End(); break;
          default: usleep(500000); pause = 1; usleep(50000); printf("\n\nInvalid Input\n"); system("pause"); if (start == 1) {pause = 0;} Menu(); //ConveyorBelt(); Menu();
        }
    }
}


void End(void)
{
    usleep(1000000); // 1 second = 1,000,000 microseconds
    pause = 1;
    system("cls");
    system("cls");
    printf("\n\n------------------ Goodbye ------------------\n\n\n");
    usleep(50000); // 1 second = 1,000,000 microseconds
    exit(0);
}


void StartMotor(void)
{
    /* ----------------------- Motor Start ------------------------ */

    pause = 0;
    start = 1;
}


void StopMotor(void)
{
    /* ------------------ Motor Stopped ------------------ */

    usleep(50000);
    pause = 1;
}

// NOT IN USE
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}


int main()
{

    pthread_t Size1;
    pthread_t Size3;
    pthread_create(&Size1, NULL, ConveyorBelt, NULL);
    pthread_create(&Size3, NULL, Menu, NULL);


    pthread_join(Size1, NULL);
    pthread_join(Size3, NULL);

    return 0;
}
