#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>
#define ARRAY_SIZE 5

/*
    THIS CODE WAS THE OLD VERSION OF PRINTING A NEW BOX
    EVERYTIME A CERTAIN SPACE IS DESIRED

    NOT NEED ANYMORE
*/


int Conveyor1 [101] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int LargeBox [4] = {1,1,1,1};
int SmallBox [2] = {1,1};
int Conveyor2 [101] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


int main()
{

    int list = 0;
    int list2 = 0;
    int trial = 0;
    int loop[10] = {-1,-1,-1};
    int loop2 [10] = {0,0,0,0,0,0,0,0,0,0};
    int loop3 = -1;
    int loop4 = 0; //[10] = {0,0,0,0,0,0,0,0,0,0};
    int lag [10] = {0,0,0,0,0,0,0,0,0,0};
    int lag2 = 0;
    int lag_wait [10] = {0,0,0,0,0,0,0,0,0,0};
    int delay;
    int count [10] = {0,0,0,0,0,0,0,0,0,0};
    int count2 = 0;
    int maxvalue1 = 3;
    int maxvalue2 = 1;
    int BoxCount = 0;
    int Random[10];
    int Random2[10];
    int start = 0;
    int i = 0;

    srand(time(0));

    while (1)
    {
            system("cls");
            printf("Loop[1]: %d", loop[1]);
            printf("\nLag_Wait[0]: %d", lag_wait[0]);
            printf("\ni[0]: %d", i);

            printf("\n\n____________________________________________________________________________________________________\n\n");
            for (trial = 0; trial < 100; trial++)                                        // It prints a line of 0s (000000000000).
            {
                printf("%d", Conveyor1 [list]);
                list++;
            }
            printf("\n____________________________________________________________________________________________________\n\n");
            for (trial = 0; trial < 100; trial++)
            {
                printf("%d", Conveyor1 [list2]);
                list2++;
            }
            printf("\n____________________________________________________________________________________________________\n");
            if (list == 100 && list2 == 100)                      // IF the whole list is shown, set the 10000... back to the start.
            {
                list = 0;
                list2 = 0;
                loop[0]++;
                loop3++;
            }
            if (start == 0)
            {
                start = 1;
                Random[0] = (rand() % 2) + 1;
            }
            if (loop[0] == loop2[0])                                  // IF loop has been +1 and now equals loop 2.
            {
                if (Random[0] == 1)
                {
                    Random2[0] = 3;
                    if (count[0] > maxvalue1)
                    {
                        Conveyor1[lag[0]] = 0;                         // 01100
                        Conveyor1[loop2[0]] = 1; //LargeBox[maxvalue1];     // 00110
                        lag[0]++;
                        loop2[0]++;
                        lag_wait[0]++;
                    }
                    if (count[0] <= maxvalue1)                            // if count 1 or 2 is less than 7. when both 7 -> stops
                    {
                        Conveyor1[loop2[0]] = LargeBox[count[0]];         // = 1
                        loop2[0]++;                                // Helping go through the arrays
                        count[0]++;
                    }
                }
                if (Random[0] == 2)
                {
                    Random2[0] = 1;
                    if (count[0] > maxvalue2)
                    {
                        Conveyor1[lag[0]] = 0;                         // 01100
                        Conveyor1[loop2[0]] = 1; //LargeBox[maxvalue1];     // 00110
                        lag[0]++;
                        loop2[0]++;
                        lag_wait[0]++;
                    }
                    if (count[0] <= maxvalue2)                            // if count 1 or 2 is less than 7. when both 7 -> stops
                    {
                        Conveyor1[loop2[0]] = SmallBox[count[0]];         // = 1
                        loop2[0]++;                                // Helping go through the arrays
                        count[0]++;
                    }
                }
            }
            if (lag_wait[0] > 15)    //       if (lag_wait[i] > 10)
            {
                Random[1] = (rand() % 2) + 1;
                if (Random[1] == 1)
                {
                    Random2[1] = 3;
                    if (count[1] > maxvalue1)
                    {
                        Conveyor1[lag[1]] = 0;                         // 01100
                        Conveyor1[loop2[1]] = 1; //LargeBox[maxvalue1];     // 00110
                        lag[1]++;
                        loop[1]++;
                        loop2[1]++;
                        lag_wait[1]++;
                    }
                    if (count[1] <= maxvalue1)                            // if count 1 or 2 is less than 7. when both 7 -> stops
                    {
                        Conveyor1[loop2[1]] = LargeBox[count[1]];         // = 1
                        loop2[1]++;                                // Helping go through the arrays
                        count[1]++;
                        loop[1]++;
                    }
                }
                if (Random[1] == 2)
                {
                    Random2[1] = 1;
                    if (count[1] > maxvalue2)
                    {
                        Conveyor1[lag[1]] = 0;                         // 01100
                        Conveyor1[loop2[1]] = 1; //LargeBox[maxvalue1];     // 00110
                        lag[1]++;
                        loop[1]++;
                        loop2[1]++;
                        lag_wait[1]++;
                    }
                    if (count[1] <= maxvalue2)                            // if count 1 or 2 is less than 7. when both 7 -> stops
                    {
                        Conveyor1[loop2[1]] = SmallBox[count[1]];         // = 1
                        loop2[1]++;                                // Helping go through the arrays
                        count[1]++;
                        loop[1]++;
                    }
                }
            }
            if (lag_wait[1] > 15)
            {
                Random[2] = (rand() % 2) + 1;
                if (Random[2] == 1)
                {
                    Random2[2] = 3;
                    if (count[2] > maxvalue1)
                    {
                        Conveyor1[lag[2]] = 0;                         // 01100
                        Conveyor1[loop2[2]] = 1; //LargeBox[maxvalue1];     // 00110
                        lag[2]++;
                        loop[2]++;
                        loop2[2]++;
                        lag_wait[2]++;
                    }
                    if (count[2] <= maxvalue1)                            // if count 1 or 2 is less than 7. when both 7 -> stops
                    {
                        Conveyor1[loop2[2]] = LargeBox[count[2]];         // = 1
                        loop2[2]++;                                // Helping go through the arrays
                        count[2]++;
                        loop[2]++;
                    }
                }
                if (Random[2] == 2)
                {
                    Random2[2] = 1;
                    if (count[2] > maxvalue2)
                    {
                        Conveyor1[lag[2]] = 0;                         // 01100
                        Conveyor1[loop2[2]] = 1; //LargeBox[maxvalue1];     // 00110
                        lag[2]++;
                        loop[2]++;
                        loop2[2]++;
                        lag_wait[2]++;
                    }
                    if (count[2] <= maxvalue2)                            // if count 1 or 2 is less than 7. when both 7 -> stops
                    {
                        Conveyor1[loop2[2]] = SmallBox[count[2]];         // = 1
                        loop2[2]++;                                // Helping go through the arrays
                        count[2]++;
                        loop[2]++;
                    }
                }
            }
            if (lag_wait[2] > 15)
            {
                Random[3] = (rand() % 2) + 1;
                if (Random[3] == 1)
                {
                    Random2[3] = 3;
                    if (count[3] > maxvalue1)
                    {
                        Conveyor1[lag[3]] = 0;                         // 01100
                        Conveyor1[loop2[3]] = 1; //LargeBox[maxvalue1];     // 00110
                        lag[3]++;
                        loop[3]++;
                        loop2[3]++;
                        lag_wait[3]++;
                    }
                    if (count[3] <= maxvalue1)                            // if count 1 or 2 is less than 7. when both 7 -> stops
                    {
                        Conveyor1[loop2[3]] = LargeBox[count[3]];         // = 1
                        loop2[3]++;                                // Helping go through the arrays
                        count[3]++;
                        loop[3]++;
                    }
                }
                if (Random[3] == 2)
                {
                    Random2[3] = 1;
                    if (count[3] > maxvalue2)
                    {
                        Conveyor1[lag[3]] = 0;                         // 01100
                        Conveyor1[loop2[3]] = 1; //LargeBox[maxvalue1];     // 00110
                        lag[3]++;
                        loop[3]++;
                        loop2[3]++;
                        lag_wait[3]++;
                    }
                    if (count[3] <= maxvalue2)                            // if count 1 or 2 is less than 7. when both 7 -> stops
                    {
                        Conveyor1[loop2[3]] = SmallBox[count[3]];         // = 1
                        loop2[3]++;                                // Helping go through the arrays
                        count[3]++;
                        loop[3]++;
                    }
                }
            }
            if (lag_wait[3] > 15)
            {
                Random[4] = (rand() % 2) + 1;
                if (Random[4] == 1)
                {
                    Random2[4] = 3;
                    if (count[4] > maxvalue1)
                    {
                        Conveyor1[lag[4]] = 0;                         // 01100
                        Conveyor1[loop2[4]] = 1; //LargeBox[maxvalue1];     // 00110
                        lag[4]++;
                        loop[4]++;
                        loop2[4]++;
                        lag_wait[4]++;
                    }
                    if (count[4] <= maxvalue1)                            // if count 1 or 2 is less than 7. when both 7 -> stops
                    {
                        Conveyor1[loop2[4]] = LargeBox[count[4]];         // = 1
                        loop2[4]++;                                // Helping go through the arrays
                        count[4]++;
                        loop[4]++;
                    }
                }
                if (Random[4] == 2)
                {
                    Random2[4] = 1;
                    if (count[4] > maxvalue2)
                    {
                        Conveyor1[lag[4]] = 0;                         // 01100
                        Conveyor1[loop2[4]] = 1; //LargeBox[maxvalue1];     // 00110
                        lag[4]++;
                        loop[4]++;
                        loop2[4]++;
                        lag_wait[4]++;
                    }
                    if (count[4] <= maxvalue2)                            // if count 1 or 2 is less than 7. when both 7 -> stops
                    {
                        Conveyor1[loop2[4]] = SmallBox[count[4]];         // = 1
                        loop2[4]++;                                // Helping go through the arrays
                        count[4]++;
                        loop[4]++;
                    }
                }
            }
            if (lag_wait[4] > 15)
            {
                Random[5] = (rand() % 2) + 1;
                if (Random[5] == 1)
                {
                    Random2[5] = 3;
                    if (count[5] > maxvalue1)
                    {
                        Conveyor1[lag[5]] = 0;                         // 01100
                        Conveyor1[loop2[5]] = 1; //LargeBox[maxvalue1];     // 00110
                        lag[5]++;
                        loop[5]++;
                        loop2[5]++;
                        lag_wait[5]++;
                    }
                    if (count[5] <= maxvalue1)                            // if count 1 or 2 is less than 7. when both 7 -> stops
                    {
                        Conveyor1[loop2[5]] = LargeBox[count[5]];         // = 1
                        loop2[5]++;                                // Helping go through the arrays
                        count[5]++;
                        loop[5]++;
                    }
                }
                if (Random[5] == 2)
                {
                    Random2[5] = 1;
                    if (count[5] > maxvalue2)
                    {
                        Conveyor1[lag[5]] = 0;                         // 01100
                        Conveyor1[loop2[5]] = 1; //LargeBox[maxvalue1];     // 00110
                        lag[5]++;
                        loop[5]++;
                        loop2[5]++;
                        lag_wait[5]++;
                    }
                    if (count[5] <= maxvalue2)                            // if count 1 or 2 is less than 7. when both 7 -> stops
                    {
                        Conveyor1[loop2[5]] = SmallBox[count[5]];         // = 1
                        loop2[5]++;                                // Helping go through the arrays
                        count[5]++;
                        loop[5]++;
                    }
                }
            }

            if (loop[0] > 101 + Random2[0])
            {
                loop2[0] = 0;             // These make the boxes loop back
                count[0] = 0;
                loop[0] = -1;
                lag[0] = 0;
                Random[0] = (rand() % 2) + 1;
                Random2[0] = 0;
                //i = 3;
                lag_wait[0] = 15;
            }
            if (loop[1] > 101 + Random2[1])
            {
                loop2[1] = 0;
                count[1] = 0;
                loop[1] = -1;
                lag[1] = 0;
                Random[1] = (rand() % 2) + 1;
                lag_wait[0] = 15;
            }
            if (loop[2] > 101 + Random2[2])
            {
                loop2[2] = 0;
                count[2] = 0;
                loop[2] = -1;
                lag[2] = 0;
                Random[2] = (rand() % 2) + 1;
                lag_wait[1] = 15;
            }
            if (loop[3] > 101 + Random2[3])
            {
                loop2[3] = 0;
                count[3] = 0;
                loop[3] = -1;
                lag[3] = 0;
                Random[3] = (rand() % 2) + 1;
                lag_wait[2] = 15;
            }
            if (loop[4] > 101 + Random2[4])
            {
                loop2[4] = 0;
                count[4] = 0;
                loop[4] = -1;
                lag[4] = 0;
                Random[4] = (rand() % 2) + 1;
                lag_wait[3] = 15;
            }
            if (loop[5] > 101 + Random2[5])
            {
                loop2[5] = 0;
                count[5] = 0;
                loop[5] = -1;
                lag[5] = 0;
                Random[5] = (rand() % 2) + 1;
                lag_wait[4] = 15;
            }

            for(delay = 0; delay < 5000000; delay++)           // This slows down the speed of the Motor.
            {

            }
      }
}
