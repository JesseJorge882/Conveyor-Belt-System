#ifndef CINTERFACE_H_INCLUDED
#define CINTERFACE_H_INCLUDED

// Functions
int ReadSizeSensor(char Conv, int Conv1[51], int Conv2[51], int Sensor1, int Sensor2);
void ResetCount(int* largesum0,int* largesum1,int* smallsum0,int* smallsum1);
void ResetSensors(int* largedetected0,int* largedetected1,int* smalldetected0,int* smalldetected1);
void Display_LargeBox(int LargeConv1, int LargeConv2, int counting);
void Display_SmallBox (int SmallConv1, int SmallConv2);

void Display_LargeBox (int LargeConv1, int LargeConv2, int counting)
{
    printf("\n\n--------- Large Box Display ---------");
    printf("\n\nLarge Box Detected (Conveyor 1): %d", LargeConv1);
    printf("\nLarge Box Detected (Conveyor 2): %d", LargeConv2);
    printf("\n\nLarge Box Collected: %d", counting);
    printf("\n\n------4: Close");
    printf("\n------5: Small Box Counter");
    printf("\n------6: Reset Counter");
    printf("\n------7: Reset Sensors");
    printf("\n-------------------Input: ");
}

void Display_SmallBox (int SmallConv1, int SmallConv2)
{
    printf("\n\n--------- Small Box Display ---------");
    printf("\n\nSmall Box Detected (Conveyor 1): %d", SmallConv1);
    printf("\nSmall Box Detected (Conveyor 2): %d", SmallConv2);
    printf("\n\n------5: Close");
    printf("\n------4: Large Box Counter");
    printf("\n------6: Reset Counter");
    printf("\n------7: Reset Sensors");
    printf("\n-------------------Input: ");
}

int ReadSizeSensor(char Conv, int *Conv1, int *Conv2, int Sensor1, int Sensor2)
{
    if (Conv == '1')
    {
        int SNRA = Conv1[Sensor1];
        int SNRB = Conv1[Sensor2];
        return SNRA + SNRB * 2;
    }
    if (Conv == '2')
    {
        int SNRA = Conv2[Sensor1];
        int SNRB = Conv2[Sensor2];
        return SNRA + SNRB * 2;
    }
}

void ResetCount(int* largesum0,int* largesum1,int* smallsum0,int* smallsum1)
{
    *largesum0 = 0;
    *largesum1 = 0;
    *smallsum0 = 0;
    *smallsum1 = 0;

    printf("\n\nCounter Reset");
}

void ResetSensors(int* largedetected0,int* largedetected1,int* smalldetected0,int* smalldetected1)
{
    // Reset sensors data
    *largedetected0 = 0;
    *largedetected1 = 0;
    *smalldetected0 = 0;
    *smalldetected1 = 0;

    printf("\n\nSensors Reset");
}


#endif // CINTERFACE_H_INCLUDED
