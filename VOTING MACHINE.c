#include<stdio.h>
#include<string.h>//For the use of string functions
#include <stdlib.h>//For exit() and system(color) function
#include<conio.h>//For getch() function

void printMessageCenter(const char* message)
{
    int len = 0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message)) / 2;
    printf("\t\t\t");
    for (pos = 0; pos < len; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s", message);
}
void headMessage(const char* message)
{
      system("CLS");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                Voting Machine                     ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

void welcomeMessage()
{
    headMessage("Welcome to The Election");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  *------------------*\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                ELECTRONIC                 =");
    printf("\n\t\t\t        =                  VOTING                   =");
    printf("\n\t\t\t        =                 MACHINE                   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  *------------------*\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}

int main()
{
    system("color F0");//Changing the color
    welcomeMessage();
    int candidates_numbers, i=0,k=0,l=0,vote_count[200]={0},r=0;
    char t[100],file_name[30];
    char symbol, candidate_name[100][25],repeat[20],name[30],repeat_vote[20],vote[200][50],choose_symbol;
   headMessage("CANDIDATES");
    printf("\n\n");
    printf("                        ..................... WELCOME TO CLAIM YOUR RIGHT TO VOTE ..................\n");
    printf("\n\n");
    //Asking the user to enter the number of candidates
  A:  printf("\nEnter number of candidates\n");
    scanf("%d",&candidates_numbers);
    //If a single candidate is selected
    if(candidates_numbers==1)
    {
        printf("Please select at least 2 candidates.\n");
        goto A;
    }
    //Using for loop for collecting the information  about candidates
    while(i<candidates_numbers)
    {
        int z=0;//Initializing the variable
         printf("\n\n\n");
        printf("==========For candidate %d:=========\n\n\n",i+1);
        printf("Enter the name of candidate %d\n",i+1);
        scanf("%s",&candidate_name[i]);
        //Using fflush(stdin) for cleaning output buffer
        fflush(stdin);
        printf("Enter the symbol of the candidate %d:\n",i+1);
            scanf("%c",&symbol);
            z=0;
        for(int j=0;j<i;j++)
        {
          if(repeat[j]==symbol)//If symbol is repeated then error will appear
          {
              printf("\n\aThis symbol has already been taken please try another.\n\n");//If same symbol is repeated again
             z=1;
              break;
          }
        }
          if(z==0)
        {
              repeat[i]=symbol;//Saving the symbol
              i++;
        }
    }
        //Declaring variables for this section
        int instruction,vote_number=0,vote_compare=0,b=0,flag;
        char voter_ID[30];
        printf("\n\n\nEnter 1 to caste the vote.\n");
        printf("\nEnter any other key to exit the poll.\n");
        scanf("%d",&instruction);
        if(instruction!=1)
        {
            exit(1);//Abnormal termination
        }
        //Storing information about Casting the vote
        while(instruction==1)
        {
           printf("\n\n\n\n\n\nEnter any key to continue....\n");
           getch();//For holding the screen
           headMessage("VOTER DETAILS");
            printf("\nEnter your voter ID.\n");
            scanf("%s",&voter_ID);
            strcpy(vote[vote_number],voter_ID);//copying the voter ID into array
            vote_number++;
             if (strcmp(t, voter_ID) == 0)
            b = -1;
            //Using for loop for comparing the voter ID
            for(vote_compare=0;vote_compare<vote_number+1;vote_compare++)
            {
               if (strcmp(voter_ID,vote[vote_compare])==0)//Comparing the strings
               b++;
            }
            if (b==1)
            {
             flag =0;
            }
            else
            {
                flag =1;
            }
            b=0;//Updating the value of b for further use
            if(flag==0)
            {
                FILE* fp = fopen("VOTERS INFO.csv", "r"); //use "r" mode just to read data from cvs file
            // .csv file should save where .c is saved for code to work
            if (!fp) {//if file doesn't exist or missed
                printf("Can't open file\n");
                return 0;
            }
            char buf[1024];
            int field_count = 0, entries = 0;
            fgets(buf, 1024, fp);
            char* field = strtok(buf, ",");//string funtions to separate data
            while (fgets(buf, 1024, fp))
            {
                field_count = 0;
                field = strtok(buf, ",");
                if (strcmp(field, voter_ID) == 0)//compare string
                {
                    while (field)
                        {
                        if (field_count == 0) {//print voter id
                            printf("\nVOTER ID:\t");
                        }
                        if (field_count == 1) {//print name
                            printf("NAME:\t");
                        }
                        if (field_count == 2) {//print age
                            printf("AGE:\t");
                        }

                        printf("%s\n", field);//when find no comma then exit loop
                        field = strtok(NULL, ",");

                        field_count++;
                    }
                    printf("\n");
                }
            }
            //close file
            fclose(fp);
                printf("\n\n\n\n\n\nEnter any key to continue....\n");
                getch();
                //Asking the user to choose the symbol
                headMessage("CASTING THE VOTE.");
                printf("\n\n\n");
                 printf("\n\nCast your vote by selecting the symbol of your representative.\n\n");
                //Using for loop for displaying the representatives information
                for(i=0;i<candidates_numbers;i++)
                {
                    //Displaying candidate's information
                    printf("%d. %s\t(%c)\n\n",i+1,candidate_name[i],repeat[i]);
                }
                printf("\n\nEnter the symbol of your Representative :\n");
                getchar();
                scanf("%c",&choose_symbol);
                for (i=0;i<candidates_numbers;i++)
                {
                    //Using if else statement for counting the votes
                    if(choose_symbol==repeat[i])
                    {
                        r=1;
                        break;
                    }
                    else
                      r=0;
                }
               if(r==1)
                    {
                      for(i=0;i<candidates_numbers;i++)
                      {
                          if(choose_symbol==repeat[i])
                          {
                              vote_count[i]++;//Increment in the number of votes
                          }
                      }
                        //When vote has been casted
                           printf("\aThank You ! Your vote has been casted.\n\n\n\n\n\n\n");
                           printf("Press any key to continue\n");
                           getch();
                      }
                              //If wrong symbol is entered
                      else
                      {
                          printf("\n\n\nYou have chosen a wrong symbol, Please re-enter it.\n");
                          printf("\n\n\nEnter any key to continue.\n");
                          getch();
                          continue;
                      }
                       headMessage("MENU");
                      while(instruction==1)
                      {
                          //Declaring variables for this section
                          int choice,difference1,difference2;
                          printf("\n\n\nEnter your choice.\n");
                          printf("\n\nEnter 1 for Results.\nEnter 2 for difference between any two candidates.\n");
                          printf("Enter 3 for completion of your voting.\nEnter 4 to exit the poll.\n");
                          scanf("%d",&choice);
                        //Using if eles statement for running the program according to the instructions of the user
                          if(choice==1)//press 1 for result
                              {
                                  headMessage("Results");
                                printf("\n\n\nThe result of votes casted so far is:\n");
                                printf("Name\t\tSymbol\t\tNo. of votes\n");
                                for(i=0;i<candidates_numbers;i++)
                                {
                                    //Displaying the result
                                    printf("%s\t\t%c\t\t%d\n",candidate_name[i],repeat[i],vote_count[i]);
                                }

                              }
                            else if(choice==2)//press 2 to see difference b/w candidate's votes
                            {
                                printf("\n");
                                headMessage("Difference");
                                printf("\n\n\n");
                                 printf("Name\t\tSymbol\t\tNo. of votes\n\n");
                                //Displaying the display.
                                for(i=0;i<candidates_numbers;i++)
                                {
                                    printf("%s\t\t(%c)\t\t%d\n\n",candidate_name[i],repeat[i],vote_count[i]);
                                }
                               printf("\nEnter the serial No. of candidates whose difference is to be known.\n\n");
                                scanf("%d%d",&difference1,&difference2);
                                if(vote_count[difference1-1]==vote_count[difference2-1])//in case of same votes
                                {
                                    printf("\n\nIt's a tie between  both the candidates.\n");
                                }
                                else
                                {
                                    printf("\n\nThe difference between %s and %s is %d.\n",candidate_name[difference1-1],candidate_name[difference2-1],vote_count[difference1-1]-vote_count[difference2-1]);
                                }
                            }
                            else if(choice==3)//for complete vote caste
                            {
                                break;
                            }
                            else if(choice==4)//to exit pole
                            {
                                printf("\n\n\nThe result of votes casted so far is:\n");
                                printf("Name\t\tSymbol\t\tNo. of votes\n");
                                for(i=0;i<candidates_numbers;i++)
                                {
                                    //Displaying the result
                                    printf("%s\t\t%c\t\t%d\n",candidate_name[i],repeat[i],vote_count[i]);
                                }
                                getchar();
                                    goto B;
                            }
                            else if(choice>4)
                            {
                                printf("\aYou entered a wrong option, try again.\n");
                            }
                            else
                            {
                                instruction=0;
                            }

                        }
                    }
                 else
                 {
                     printf("\aSorry! You have already casted the vote.\n");
                     printf("Enter any key to continue.");
                     getch();
                 }
                }
               B: headMessage(" FINAL RESULTS");
            for(i=0;i<candidates_numbers;i++)
                {
            // File name for storing Candidate details
            sprintf(file_name, "Candidate%d.txt", i + 1);
            FILE *Election;
            Election = fopen(file_name, "w");
            // If above operation is failed print error and exit
            if (Election == NULL)
        {
            /* File not created hence exit */
            printf("Unable to create file.\n");
            exit(EXIT_FAILURE);//Unsuccessful execution of program
        }
        // Writing data in the file
        Election = fopen(file_name, "w"); //use "w" mode to write data in file
        printf("\nCandidate : %s", candidate_name[i]);

        fprintf(Election, "Candidate:%s\n", candidate_name[i]);

        printf("\t Symbol : %c", repeat[i]);
        fprintf(Election, "Symbol:%c\n", repeat[i]);

         printf("\t Votes : %d\n", vote_count[i]);
        fprintf(Election, "Votes:%d\n", vote_count[i]);

        /* Closing the file */
        fclose(Election);
    }
    printf("\n     A PROJECT MADE BY\n   MUHAMMAD ABDULLAH (332172)\n   MUHAMMAD SALMAN    (336192)");
    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############   THANK YOU FOR USING ELECTRONIC VOTING MACHINE   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################\n\n\n");
return 0;
   }    // .csv file should save where .c is saved for code to work
