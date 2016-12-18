/* Assignment 2.
    A lotto game which reads in users 6 numbers and displays
    if they have won or not. Each function has a specific task
    to complete which is explained before
    each function and all code must be in pointer notation.
    Ciara Sastre DT282/1 17/02/2016
*/
#include <stdio.h>
#include <stdlib.h>

//PROTOTYPES
int *option1();
void option2(int[]);
int *option3(int[]);
void option4(int[]);
void option5(int[]);
#define SIZE 6
main()
{
    int menu = 2;
    char option;
    static int pass = 0; //Validation to allow you to pass to a different funciton
    static int *p, *k;
    
    do //While menu ==  2
    {
        system("cls");
        
        printf("\n**********MENU**********\n");
        printf("Welcome to the Lotto Game!");
        printf("\nPlease enter in the number of which option you want to take:\n\n");
        printf("1) Enter in your six lotto numbers.\n");
        printf("2) See your chosen lotto numbers here.\n");
        printf("3) See them in increasing order here!\n");
        printf("4) See your winnings here.\n");
        printf("5) Frequency of number entered.\n");
        printf("6) Exit.\n");
        scanf("%1s", &option);
        
        switch (option)
        {
            case '1':
            {
                system("cls");
                
                //Call function option1
                p = option1(); //returns lotto_array and stores into p
                printf("\n\nPress Enter to return");
                pass = 2;
                break;
            }
            
            case '2':
            {
                if(pass > 1)
                {
                    system("cls");
                    
                    //Call function option2
                    option2(p); //We bring lotto_array over
                    printf("\n\nPress Enter to return");
                    pass++;
                }
                else
                {
                    printf("Im sorry you need to enter in your Lotto Numbers first.");
                    printf("\n\nPress Enter to return");
                }
                break;
            }
            
            case '3':
            {
                if(pass > 2)
                {
                    system("cls");
                    
                    //Call function option3
                    k = option3(p); //We bring lotto_array over AND store the new sorted array
                    printf("\n\nPress Enter to return");
                    pass++;
                }
                else
                {
                    printf("Im sorry you need to go through option2 first.");
                    printf("\n\nPress Enter to return");
                }
                break;
            }
            
            case '4':
            {
                if(pass > 3)
                {
                    system("cls");
                    
                    //Call function option4
                    option4(k); //Bring sorted array over
                    printf("\n\nPress Enter to return");
                    pass++;
                }
                else
                {
                    printf("Im sorry you need to go through option3 first.");
                    printf("\n\nPress Enter to return");
                }
                break;
            }
            
            case '5':
            {
                if(pass > 4)
                {
                    system("cls");
                    
                    //Call function option5
                    option5(k); //Bring the sorted array over
                    printf("\n\nPress Enter to return");
                }
                else
                {
                    printf("Im sorry you need to go through option4 first.");
                    printf("\n\nPress Enter to return");
                }
                break;
            }
            
            case '6':
            {
                exit(0);
            }
            
            default:
            {
                printf("ERROR it must be a number ranging from 1-7.");
            }
            
        }//end switch
        
        flushall();
        getchar();
        
    }while(menu == 2);
    
}//end main
 
/*Implement Option1 which will ask the user to enter in 6 numbers
    and return it so it can then be used in Option2.
    It will also validate if the number is between 1-42 
    and that the numbers are all different.
*/
int *option1()
{
    int i, j;
    int valid = 0;
    static int lotto_array[SIZE];
    static int stay = 2; //This keeps the process in the do while loop
    
    printf("********** Welcome to Option 1 **********\n");
    do //While stay == 2
    {
        stay = 1;
        
        printf("\n\nEnter in your 6 Lotto numbers! \n");
        printf("\nKeep in mind that they must: \n");
        printf("Range from 1-42\n");
        printf("All be different\n");
            
        //Store numbers into array
        for(i=0; i<SIZE; i++)
        {
            scanf("%d", &*(lotto_array+i) );
        }
        
        printf(" ");
        
        //Checks if all numbers are different
        for(i=0; i<SIZE; i++)
        {
            for(j=1+valid; j<SIZE; j++)
            {
                if( *(lotto_array+i) == *(lotto_array+j) )
                {
                    printf("\n%d is not valid, you cannot enter the same number more than once.", *(lotto_array+j) );
                    stay = 2;
                }
            }
            
            valid++;
        }
        
        //Checks if numbers range from 1-42
        for(i=0; i<SIZE; i++)
        {
            if( *(lotto_array+i) < 1 || *(lotto_array+i) > 42)
            {
                printf(" Im sorry the numbers must range from 1-42");
                stay = 2;
            }
        }
    }
    while( stay == 2 );
    
    return(lotto_array);
    
 }

/*Implement Option 2 which will take a copy of the array entered by the user in Option1
    and display it.
 */
void option2(int display_array[])
 {
    int i;
    
    printf("********** Welcome to Option 2 **********\n");
    printf("\n\nYour Lotto numbers are: ");
    printf("\n{");
     
    for(i=0; i<SIZE; i++)
    {
        printf(" %d,", *(display_array+i));
    }
    printf(" }");
}

/* Implement Option3 which will take the lotto_array entered by user in Option1
    and sort it in increasing order using the Insertion sort algorithim.

    I used the insertion sort algorithm because i believe it is more effective and quicker
    in comparison to the bubble sort or selection sort as it is designed to INSERT the number 
    in its correct place in the array.
*/
int *option3(int sort_array[])
{
    int i, j, temp;
    
    printf("********** Welcome to Option 3 **********\n");
    
    //Now use insertion sort
    for(i=1; i<SIZE; i++)
    {
        temp = *(sort_array+i);
        j = i-1;
        
        while( (temp < *(sort_array+j) ) && (j >= 0) ) 
        {
            *(sort_array+j+1) = *(sort_array+j); 
            j = j-1;
        }
        
        *(sort_array+j+1) = temp;
    }
    
    //Display after sorting
    printf("\n\n Your lotto Numbers in ascending order is:\n");
    
    for(i=0; i<SIZE; i++)
    {
        printf(" %d", *(sort_array+i) );
    }
    
    return(sort_array);
}

/*Implement Option4 so you can compare the sorted array with the winning array
    and display what the user has won.
*/
void option4(int comparison_array[])
{
    int i,j;
    int win_array[SIZE] = {1,3,5,7,9,11}; //Remove the bonus number 42
    int win = 0;
    int bonus = 0;
    
    printf("********** Welcome to Option 4 **********\n\n");
    
    /* Go through each individual value in
            the arrays and when both match, add one to win variable.
            Then if winner variable = 1 you dont win, if variable = 6 jackpot etc.
        */
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if( *(win_array+i) == *(comparison_array+j) )
            {
                win++;
            }
        }
    }
    
    //Now check to see if they had the bonus number
    for(i=0; i<SIZE; i++)
    {
        if( *(comparison_array+i) == 42)
        {
            bonus++;
        }
    }
    
    //Now a check is done to see what prize they will recieve
    if(win == 6)
    {
        printf("\n*******************\n");
        printf("***   JACKPOT   ***\n");
        printf("*******************");
    }
    
    if(win == 5 && bonus == 1)
    {
        printf("\nYou Won: ");
        printf("\n\n *** New Car! ***");
    }
    
    if(win == 5 && bonus == 0) //Bonus needs to be 0 otherwise it will show up with New Car
    {
        printf("\nYou Won: ");
        printf("\n\n *** Holiday! ***");
    }
    
    if(win == 4 && bonus == 1)
    {
        printf("\nYou Won: ");
        printf("\n\n *** Week end Away! ***");
    }
    
    if(win == 4 && bonus == 0)
    {
        printf("\nYou Won: ");
        printf("\n\n *** Night Out! ***");
    }
    
    if(win == 3 && bonus == 1)
    {
        printf("\nYou Won: ");
        printf("\n\n *** A Cinema Ticket! *** ");
    }
    
    if(win == 3 && bonus == 0 || win < 3)
    {
        printf("\nIm sorry you have not won anything.");
    }
    
}//End option4

/* Implement option5 to get the frequency of numbers the user has entered
*/
void option5(int user_array[])
{
    int i, j;
    static int freq_array[100];
    static int temp_size = 0;
    static int limit;
    int count;
    
    printf("********** Welcome to Option 5 **********\n");
    printf("\n\nFrequency of numbers entered is :\n\n");
    
    limit = limit+6; //This is used so user doesnt exceed freq_array[100]
    
    if( limit <101 )
    {
    
        //Copies user_array into freq_array,  temp_size is used as freq_array will expand
        for(i=0; i<SIZE; i++)
        {
            *(freq_array+i+temp_size) = *(user_array+i);
        }
        
        //Find frequency
        for(i=0; i<SIZE+temp_size; i++)
        {
            count = 0;
            
            for(j=0; j<SIZE+temp_size; j++)
            {
                if( *(freq_array+i) == *(freq_array+j) )
                {
                    count++;
                }
                
            }
            
            printf("\nNumber %d has been entered %d time(s)", *(freq_array+i), count);
            
        }//end for
        
        temp_size = temp_size + 6;
        
    }//end if
    else
    {
        printf("\nData is full please restart the game to play again");
    }
}//End option5
