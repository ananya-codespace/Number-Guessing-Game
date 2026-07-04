#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Choose the level
int chooseLevel(int level)
{
    if (level == 1)
        return 50;
    else if (level == 2)
        return 200;
    else if (level == 3)
        return 500;
    else
        return 0;
}

// Maximum attempts for each level
int maxAttempts(int level)
{
    if (level == 1)
        return 10;
    else if (level == 2)
        return 7;
    else if (level == 3)
        return 5;
    else
        return 0;
}

// The main function - The Game
int playGame(int num, int range, int max_attempts)
{
    int guess; int attempts = 0; int found = 0;
    float diff; char *direction;
    int won = 0;

    while (!found && attempts < max_attempts)
    {
        printf("\nEnter your Guess: ");
        scanf("%d", &guess);
        diff = (float)abs(guess - num) / range * 100;

        if (guess < 1 || guess > range)
        {
            printf("\nInvalid Guess, Please enter a number between 1 and %d\n", range);
            continue;   // continue skips the rest of the current loop iteration and jumps back to the top of the loop
        }
        
        attempts++;
        if (num == guess)
        {
            printf("\nCORRECT GUESS!!!\nYou guessed it in %d attempts!\n", attempts);
            won++;
            found = 1;
        }
        else if (attempts == max_attempts)
            break;
        else
        {
            if (guess > num)
                direction = "high";
            else
                direction = "low";

            if (diff <= 2)
                printf("\nEXTREMELY CLOSE! You are almost there.\nYour guess is just a tiny bit %s.\n", direction);
            else if (diff <= 10)
                printf("\nVERY CLOSE! You are in the right direction.\nYour guess is a little %s.\n", direction);
            else if (diff <= 30)
                printf("\nGETTING WARMER! You are getting closer to the correct answer.\nYour guess is %s.\n", direction);
            else    
                printf("\nIT'S COLD! You are very far from the correct answer.\nYour guess is too %s.\n", direction);
        }
    }
    if (found == 0)
        printf("\nYOU LOST! The number was %d.\nBETTER LUCK NEXT TIME!\n", num);
    return won;
}

int main()
{
    int level;
    int range; int num;
    int max_attempts;
    char again;
    int rounds = 0; int won = 0;

    srand(time(NULL));   // to set the seed (starting number of the sequence) for rand() different for each run
    // rand() generates a random number between 0 and a very large number; rand() % 100 : between 0-99;  rand() % 100 + 1 : between 1-100
    printf("\n -------------------- NUMBER GUESSING GAME -------------------- \n\n");
    printf("WELCOME!\n");
    printf("\nRULES");
    printf("\n---------------------------------------- \n");
    printf("This is a fun Number Guessing Game where you need to guess the number.\n\n");
    printf("1. There are 3 levels:\n\ta. Easy - You guess a number between 1-50 and you have 10 attempts.\n");
    printf("\tb. Medium - You guess a number between 1-200 and you have 7 attempts.\n\tc. Hard - You guess a number between 1-500 and you have 5 attempts.\n");
    printf("2. After each guess you are provided with hints that will help you in making the successive guesses.\n");
    printf("3. If you fail to guess within the number of attempts available for each level, you lose the game.\n");
    printf("4. You get to choose the level for each round and can play the game any number of times.\n");
    printf("\nHope you enjoy the game!\nLET'S START!!!");
    printf("\n---------------------------------------- \n");

    while (1)
    {
        do 
        {
            printf("\nChoose a level :\n1. Easy (1-50)\n2. Medium (1-200)\n3. Hard (1-500)\n");
            scanf("%d", &level);
            range = chooseLevel(level);
            if (range == 0)
                printf("\nInvalid Level, Try Again...\n");
        } 
        while (range == 0);
        
        num = rand() % range + 1;
        max_attempts = maxAttempts(level);
        won += playGame(num, range, max_attempts);
        rounds++;

        printf("\nDo you want to play again? (Enter 'y' for 'Yes' or 'n' for 'No'): ");
        scanf(" %c", &again);   // space before scanf - to avoid reading the '\n' char in the buffer when level is entered
        // without space only the newline char is read and y/n is not read, with 'space' all leading whitespaces (spaces, tabs, newline) are ignored
        if (again == 'n')
        {
            printf("\nExiting the game...\n");
            printf("\nGAME RECAP");
            printf("\n-------------------- \n");
            printf("Rounds played : %d\n", rounds);
            printf("Rounds won    : %d\n", won);
            printf("Rounds lost   : %d\n", rounds - won);
            printf("-------------------- \n\n");
            printf("THANK YOU!\n\n");
            break;
        }
    }

    return 0;
}


/*
new topics learnt :
about rand and srand - and how to use them (document it or include in git readme)
time used in srand
space before scanf :
    %d automatically skips leading whitespace before reading a number. 
    %c doesn't — it reads literally the very next character including whitespace. That's why only %c needs the space.


    sprintf
    compare and qsort
    hashmap in c - learn
    Other useful functions from <ctype.h>:
tolower(ch)	Convert uppercase to lowercase
toupper(ch)	Convert lowercase to uppercase
isalpha(ch)	Is it a letter?
isdigit(ch)	Is it a digit (0-9)?
isalnum(ch)	Letter or digit?
islower(ch)	Lowercase letter?
isupper(ch)	Uppercase letter?
isspace(ch)	Space, tab, newline, etc.?
ispunct(ch)	Punctuation character?

when a ll is created using malloc the 1st node is a dummy node and if u r returning the ll u need to return 'list->next' coz from the next nodes, the actual values r stored
*/ 

