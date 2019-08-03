#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//todo:
//gui?
//handle overcrowding case

int main()
{
    //initialization
    //should switch to vectors for variable size
    int first[10][10];
    int second[10][10];
    int temp[10][10];
    int increment=0;
    srand((int)time(0));

    //zeros grids
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            first[i][j] = 0;
            second[i][j] = 0;
        }
    }

    //randomizes first grid
    for(int i=1;i<9;i++)
    {
        for(int j=1;j<9;j++)
        {
            first[i][j] = rand()%2;
        }
    }
/*
    //prints first grid
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout << first[i][j] << " ";
        }
        cout << "\n";
    }*/
    //how many times the game runs, i.e. generations
    for(int loop=0;loop<10;loop++)
    {
        //prints first grid
        for(int i=0;i<10;i++)
        {
            cout << "\n";
            for(int j=0;j<10;j++)
            {
            cout << first[i][j] << " ";
            }
        }
        cout << "\n";

        //check values
        for(int k=1;k<9;k++)
        {


            for(int l=1;l<9;l++)
            {
                //8 if statements to check surroundings
                //increment value if value = 1
                //top
                if(first[k-1][l-1]==1)
                {
                    increment++;
                }
                if(first[k-1][l]==1)
                {
                    increment++;
                }
                if(first[k-1][l+1]==1)
                {
                    increment++;
                }
                //mid
                if(first[k][l-1]==1)
                {
                    increment++;
                }
                if(first[k][l+1]==1)
                {
                    increment++;
                }
                //bottom
                if(first[k+1][l-1]==1)
                {
                    increment++;
                }
                if(first[k+1][l]==1)
                {
                    increment++;
                }
                if(first[k+1][l+1]==1)
                {
                    increment++;
                }
                //else
                //{
                //    cout << "error 1";
                //}

                //switch statement based on number of surroundings
                switch(increment)
                {
                case 0:
                    second[k][l] = 0;
                    //cout << increment;
                    break;
                case 1:
                    second[k][l] = 0;
                    //cout << increment;
                    break;
                case 2:
                    second[k][l] = 1;
                   //cout << increment;
                    break;
                case 3:
                    second[k][l] = 1;
                    //cout << increment;
                    break;
                case 4:
                    second[k][l] = 0;
                    //cout << increment;
                    break;
                case 5:
                    second[k][l] = 0;
                    //cout << increment;
                    break;
                case 6:
                    second[k][l] = 0;
                    //cout << increment;
                    break;
                case 7:
                    second[k][l] = 0;
                    //cout << increment;
                    break;
                case 8:
                    second[k][l] = 0;
                    //cout << increment;
                    break;
                default :
                    cout << "error 2";
                }
                increment = 0;
            }
        }
        //changes value of primary array to reflect changes in secondary array
        for(int i=1;i<9;i++)
        {
            for(int j=1;j<9;j++)
            {
            first[i][j] = second[i][j];
            }
        }
    }
}
