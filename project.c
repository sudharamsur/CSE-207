#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


bool isSafe(int x, int y, int N, int maze[N][N])
{
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;

    return false;
}


bool ratInMaze(int N, int x, int y, int maze[N][N], int sol[N][N])
{

    if (isSafe(x, y, N, maze) == true)
    {

        // if (x, y is goal) return true
        if (x == N - 1 && y == N - 1)
        {
            sol[x][y] = 1;
            return true;
        }

        sol[x][y] = 1;

        if (ratInMaze(N, x + 1, y, maze, sol) == true)
            return true; // go to right ( row wise checking)

        if (ratInMaze(N, x, y + 1, maze, sol) == true)
            return true; // backtrack hoye niche check kora

        sol[x][y] = 0;
        return false;
    }

    return false;
}


void printSolution(int N, int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}


int main()
{

    srand (time(NULL));

    int N;
    int i, j;

    int choice;

    while(choice != 2)
    {

        printf("Enter square matrix value (N x N): ");
        scanf("%d", &N);

        int givenMaze[N][N];
        int solMaze[N][N];

        //assigning solMaze values to zero
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                solMaze[i][j] = 0;
            }
        }

        //getting the maze value using rand function
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                givenMaze[i][j] = (rand() % 2) + 0; //0,1
            }
        }

        if(ratInMaze(N, 0, 0, givenMaze, solMaze) == false)
        {

            printf("\n\nGiven Maze\n");
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                    printf(" %d ", givenMaze[i][j]);
                printf("\n");
            }
            printf("\n\nSolution Doesn't Exists\n\n");


            printf("Do you want to try again?\n");
            printf("Yes(1)\nExit(2)\n\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            if(choice == 1)
            {
                system("cls");
            }


        }
        else
        {

            printf("\n\nGiven Maze\n");
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                    printf(" %d ", givenMaze[i][j]);
                printf("\n");
            }
            printf("\n\nThe rat found out its way\n");
            printSolution(N, solMaze);

            printf("\n\nDo you want to try again?\n");
            printf("Yes(1)\nExit(2)\n\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            if(choice == 1)
            {
                system("cls");
            }

        }
    }




}
