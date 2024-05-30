#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int isNumber(char* str) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int main() {
    
    srand(time(NULL));

    restart:
    printf("\n**************************************************\n");
    printf("\nWelcome to the world of Gussing numbers\n");
    printf("\nGuess a number between 0 to 100.\n");
    printf("\n*** You can close the game anytime by using \" ctrl + c \". ***\n");

    char input[100];
    int number, randomNumber, numberOfGuess = 0;
    
    do {
        goOn:
        printf("\n**************************************************\n");
        
        printf("\nAttempt %d", ++numberOfGuess);

        printf("\nPlease enter a number: ");
        scanf("%s", &input);

        if (isNumber(input)) {
            number = atoi(input);
            if (number < 0 || number > 101) {
            printf("\n*** Nerd, I told you to enter a number between 0 to 100. ***\n\n");
            } else {
                randomNumber = (rand() % 101);
                printf("\n\nThis time the number is %d.\n", randomNumber);

                printf("\n**************************************************\n");
            }
        } else {
            printf("\n*** Nerd, I told you to enter a number between 0 to 100. ***\n\n");
        }
        

        if (numberOfGuess % 20 == 0) {
            
            char c;
            invalid2:
            printf("\nDo you accept defeat? (y/n): ");
            scanf(" %c", &c);

            if (c == 'n') {
                goto goOn;
            } else if (c == 'y') {
                return 0;
            } else {
                printf("\nInvalid input!\n");
                printf("\nNerd, enter a valid input.\n");
                goto invalid2;
            }
        }
        
    } while (number != randomNumber);

    if (numberOfGuess == 1) {
        printf("\nCongratulaitons\nYou have gussed the number in 1 attempt.\n");
    } else {
        printf("\nCongratulaitons\nYou have gussed the number in %d attempts.\n", numberOfGuess);
    }

    char c;
    invalid1:
    printf("\nNow you have 2 choices:\n\nTo restart enter 'r'.\n\nTo exit enter 'e'.\n\nEnter your choice: ");
    scanf(" %c", &c);

    if (c == 'r') {
        goto restart;
    } else if (c == 'e') {
        return 0;
    } else {
        printf("\nInvalid input!\n");
        goto invalid1;
    }

    return 0;
}