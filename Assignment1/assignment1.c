/* A program that runs as a mathematical quiz.
    Must re-display menu after each menu option is completed.
    Number of questions per round must be selected before quiz is started.
    Scores can only show after the quiz is played through and score must reset each time.
    The menu will only terminate after 4.
    Ciara Sastre DT282-1    30/10/2015 - 11/11/2015
*/
#include <stdio.h>
#include <conio.h>
main()
{
    int menu_num;
    int user_answer;
    int round = 0;
    int set_round = -1;
    int correct = 0;
    int incorrect = 0;
    char menu;
    
    do //while menu is 'm'
    {   
        menu = 'a'; //must be assigned so case 2 doesnt jump out of loop.
        
        clrscr();
        
        printf("**MENU**\n");
        printf("\nPlease enter numbers 1-4 to select your menu options.\n\n");
        printf("1) Enter the number of questions to be asked for this round of the quiz\n");
        printf("   (maximum of 5 questions allowed).\n\n");
        printf("2) Start Quiz.\n\n");
        printf("3) Display the number of questions that were answered (i) correctly and (ii)\n");
        printf("   incorrectly for this round.\n\n");
        printf("4) Exit Program");
        
        scanf("%d", &menu_num);
        
        switch(menu_num)
        {
            //First menu number 1.
            case 1:
                
                clrscr();
                
                printf("**NUMBER OF QUESTIONS PER ROUND**\n");
                printf("\nPlease enter a number 1-5 of questions to be asked per round");
                scanf("%d", &set_round);
                    
                while(set_round > 5 || set_round < 0)
                {
                    printf("\nIm sorry, You need to type in a number between 1 and 5.\n");
                    scanf("%d", &set_round);
                    
                }//end while
                    
                printf("\n%d rounds? Great!\n", set_round);
                printf("\nPress 'm' to return to the menu.");
                scanf("%1s", &menu);
                
                //set_round needs to be one larger so that round can be round<set_round
                set_round++;
                
            break; //exit case 1
            
            //Second menu number 2.
            case 2:
                
                if(set_round > 6 || set_round < 0)
                {
                    clrscr();
                    
                    printf("**ERROR**");
                    printf("\n\nYou must select the number of questions per round first.");
                    printf("\n\nPress 'm' to return to menu.");
                    scanf("%1s", &menu);
                    
                }
                
                for(round=1; round<set_round; round++)
                {
                    if(round == 1)
                    {
                        clrscr();
                        
                        printf("**MATH QUESTIONS!**\n");
                        printf("\nROUND 1:  1+1 =  ");
                        scanf("%d", &user_answer);
                        
                        if(user_answer == 2)
                        {
                            printf("\n You entered %d - Correct!\n", user_answer);
                            correct = correct+1;
                        }//end inner if
                        
                        else
                        {
                            printf("\n You entered %d - Wrong!", user_answer);
                            printf("  The correct answer is 2.\n");
                            incorrect = incorrect+1;
                        }//end else
                        
                    }//end if ROUND 1
                    
                    if(round == 2)
                    {
                        printf("\n\nROUND 2: 2+2 = ");
                        scanf("%d", &user_answer);
                        
                        if(user_answer == 4)
                        {
                            printf("\n You entered %d - Correct!\n", user_answer);
                            correct = correct+1;
                        }//end inner if
                        
                        else
                        {
                            printf("\n You entered %d - Wrong!", user_answer);
                            printf("  The correct answer is 4.\n");
                            incorrect = incorrect+1;
                        }//end else
                        
                    }//end if ROUND 2
                    
                    if(round == 3)
                    {
                        printf("\n\nROUND 3: 10*5 = ");
                        scanf("%d", &user_answer);
                        
                        if(user_answer == 50)
                        {
                            printf("\n You entered %d - Correct!\n", user_answer);
                            correct = correct+1;
                        }//end inner if
                        
                        else
                        {
                            printf("\n You entered %d - Wrong!", user_answer);
                            printf("  The correct answer is 50.\n");
                            incorrect = incorrect+1;
                        }//end else
                        
                    }//end if ROUND 3
                    
                    if(round == 4)
                    {
                        printf("\n\nROUND 4: 100/50 = ");
                        scanf("%d", &user_answer);
                        
                        if(user_answer == 2)
                        {
                            printf("\n You entered %d - Correct!\n", user_answer);
                            correct = correct+1;
                        }//end inner if
                        
                        else
                        {
                            printf("\n You entered %d - Wrong!", user_answer);
                            printf("  The correct answer is 2.\n");
                            incorrect = incorrect+1;
                        }//end else
                        
                    }//end if ROUND 4
                    
                    if(round == 5)
                    {
                        printf("\n\nROUND 5: 30*2/6 = ");
                        scanf("%d", &user_answer);
                        
                        if(user_answer == 10)
                        {
                            printf("\nYou entered %d - Correct!\n", user_answer);
                            correct = correct+1;
                        }//end inner if
                        
                        else
                        {
                            printf("\nYou entered %d - Wrong!", user_answer);
                            printf("  The correct answer is 10.\n");
                            incorrect = incorrect+1;
                        }//end else
                        
                    }//end inner ROUND 5
                    
                }//end for
                if(round == set_round)
                    {
                        printf("\n\n**FINISHED**\n\n");
                        printf("Press 'm' to return to menu to view your scores.");
                        scanf("%1s", &menu);
                    }//end if
                    
                break;
                    
                
            //Third menu number 3.
            case 3:
                
                if(round != set_round)
                {
                    clrscr();
                    
                    printf("**ERROR**");
                    printf("\n\nIn order to view your scores you must play at least one questionaire");
                    printf("\n\nPress 'm' to return to menu.");
                    scanf("%1s", &menu);
                }//end if
                
                else
                {
                    clrscr();
                    
                    //Return set_round to normal
                    set_round--; 
                    printf("**SCORES**");
                    printf("\n\nHere are the questions you answered correctly for this round.\n");
                    printf("SCORE = %d", correct);
                    
                    printf("\n\nHere are the questions you answered incorrectly for this round.\n");
                    printf("SCORE = %d", incorrect);
                    
                    //reset the scores
                    correct = 0;
                    incorrect = 0;
                    
                    //set_round++; allows for replay
                    set_round++;
                    printf("\n\nPress 'm' to return to menu.");
                    scanf("%1s", &menu);
                    
                }//end else
                
                break;
                
            case 4:
                return 0;
                
            
            default:
                printf("\nPlease enter a number 1-4 from the menu");
            
        }//end switch
        
    }
    while(menu=='m');

    flushall();
    
    
    getchar();
    
}//end main()
    
    