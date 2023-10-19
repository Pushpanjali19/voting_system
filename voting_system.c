#include <stdio.h>
#include <stdlib.h>


void Record_vote() 

{
    char VoterName[50];
    int Candidate_choice;

    printf("Enter your name: ");
    scanf("%s", VoterName);

    printf("Select a candidate (1, 2, or 3): ");
    scanf("%d", &Candidate_choice);

    
    FILE *file = fopen("voting_data.txt", "a");


    if (file == NULL) 
    
    {
        printf("Error opening the file.\n");
        exit(1);
    }

    
    fprintf(file, "%s %d\n", VoterName, Candidate_choice);
    fclose(file);
}


void Display_results() 

{
    int Candidate_votes[3] = {0};

    
    FILE *file = fopen("voting_data.txt", "r");


    if (file == NULL) 
    
    {
        printf("No votes recorded yet.\n");
        return;
    }

    char Voter_name[50];
    int Candidate_choice;

    
    while (fscanf(file, "%s %d", Voter_name, &Candidate_choice) != EOF) 
    
    {
        if (Candidate_choice >= 1 && Candidate_choice <= 3) 
        
        {
            Candidate_votes[Candidate_choice - 1]++;
        }
    }

    fclose(file);

    
    for (int i = 0; i < 3; i++) 
    
    {
        printf("Candidate %d: %d votes\n", i + 1, Candidate_votes[i]);
    }

}

int main() 

{
    int choice;

  do

   {
        printf("\nVoting System Menu\n");
        printf("\n1.Record a vote");
        printf("\n2.Display results");
        printf("\n3.Exit");
        printf("\n------------------------------------------------------------\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        
         {
            case 1:
                Record_vote();
                break;
            case 2:
                Display_results();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } 
    
     while (choice != 3);

    return 0;
}
