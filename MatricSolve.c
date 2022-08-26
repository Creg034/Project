// Generate Random Number from 1 to 15 anywhere
// getch instead of getkey
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
int flashBack(char name[]);
int intro();
int printArr(int array[4][4]);
int swap(int *a1, int *b1);
int strcomp(int array[4][4], int win[4][4]);
int gamebase(int array[4][4]);
int main()
{
    int array[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 0, 14, 15}};
    intro();
    printArr(array);
    gamebase(array);
    return 0;
}
int printArr(int array[4][4])
{
    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            if (array[i][j] != 0)
                printf("%4d ", array[i][j]);
            else
                printf("%4c ", ' ');
        }
        printf("\n");
    }
}
int swap(int *a1, int *b1)
{
    int temp;
    temp = *a1;
    *a1 = *b1;
    *b1 = temp;
}
int gamebase(int array[4][4])
{
    int a, game = 1;
    int i = 3, j = 1;
    int life = 4;
    int win[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
    printf("\nLIFE : %d", life);
    while (life)
    {
        a = getch();
        system("cls");
        switch (a)
        {
        case 72:
            if (i != 3)
            {
                swap(&array[i][j], &array[i + 1][j]);
                printArr(array);
                i = i + 1;
                printf("\n\t\t");
                printf("UP");
                life -= 1;
                printf("\nLIFE : %d", life);
            }
            else
            {
                printArr(array);
                printf("\n\t\t");
                printf("Enter Valid Command");
                printf("\nLIFE : %d", life);
            }
            break;

        case 75:
            if (j != 3)
            {
                swap(&array[i][j], &array[i][j + 1]);
                printArr(array);
                j = j + 1;
                printf("\n\t\t");
                printf("LEFT");
                life -= 1;
                printf("\nLIFE : %d", life);
            }
            else
            {
                printArr(array);
                printf("\n\t\t");
                printf("Enter Valid Command");
                printf("\nLIFE : %d", life);
            }
            break;

        case 80:
            if (i != 0)
            {
                swap(&array[i][j], &array[i - 1][j]);
                printArr(array);
                i = i - 1;
                printf("\n\t\t");
                printf("DOWN");
                life -= 1;
                printf("\nLIFE : %d", life);
            }
            else
            {
                printArr(array);
                printf("\n\t\t");
                printf("Enter Valid Command");
                printf("\nLIFE : %d", life);
            }
            break;

        case 77:
            if (j != 0)
            {
                swap(&array[i][j], &array[i][j - 1]);
                printArr(array);
                j = j - 1;
                printf("\n\t\t");
                printf("RIGHT");
                life -= 1;
                printf("\nLIFE : %d", life);
            }
            else
            {
                printArr(array);
                printf("\n\t\t");
                printf("Enter Valid Command");
                printf("\nLIFE : %d", life);
            }
            break;
        }
        game = strcomp(array, win);
        if (game == 0)
            break;
    }
    if (game == 0)
        printf("\nYou Win!");
    else
        printf("\nYou Lose!");
    _getch();
}
int strcomp(int array[4][4], int win[4][4])
{
    int ok = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (array[i][j] != win[i][j])
            {
                ok = 1;
            }
        }
    }
    if (ok)
    {
        return 1;
    }
    else
        return 0;
}
int intro()
{
    char name[100];
    system("cls");
    printf("***************************************************\n");
    printf("*  Wellcome to Mt-Sort : The Matrix Sorting Game  *\n");
    printf("***************************************************\n");
    printf("(<^>)         Please Enter Your Name          (<^>)\n");
    printf(">>---> ");
    scanf("%s", name);
    system("cls");
    flashBack(name);
}
int flashBack(char name[])
{
    char yn = 't';
    printf("*******************************************************************************\n");
    printf("                                Hey %s,I'm Rucha                               \n", name);
    printf("*******************************************************************************\n");
    printf("(<^>)             Are You Playing This Game For The First Time           (<^>) \n\t\t (y/n) >>---->\t");
    scanf("%c", &yn);
    scanf("%c", &yn);
    if (yn == 'y')
    {
        printf("No Worry!, I will guide you\n");
        printf("Press Any Key to Move Toward Battle Ground\n");
        _getch();
    }
    else if (yn == 'n')
    {
        printf("Nice, Let's Go To The Ground\n");
    }
    else
        printf("I did'nt Understood\n");
    _getch();
}