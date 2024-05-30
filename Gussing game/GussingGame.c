#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL));

    restart:
    printf("\n**************************************************\n");
    printf("\nWelcome to the world of Gussing numbers\n");
    printf("\nGuess a number between 0 to 100\n");

    int number, randomNumber, numberOfGuess = 0;
    
    do {
        numberOfGuess++;

        printf("\n**************************************************\n");
        
        printf("\nPlease enter a number: ");
        scanf("%d", &number);

        if (number < 0 || number > 100){
            printf("\nDumb-ass, I told you to enter a number between 0 to 100.\n");
        } else {
            randomNumber = (rand() % 100);
            printf("\n\nThis time the number is %d\n", randomNumber);

            printf("\n**************************************************\n");
        }
        
    } while (number != randomNumber);

    if (numberOfGuess == 1) {
        printf("\nCongratulaitons\nYou have gussed the number in 1 attempt.\n");
    } else {
        printf("\nCongratulaitons\nYou have gussed the number in %d attempts.\n", numberOfGuess);
    }

    char c;
    printf("\nDo you want to exit(y/n): ");
    scanf(" %c", c);

    if (c == 'y') {
        goto restart;
    } else if (c == 'n') {
        return 0;
    } else {
        printf("\nInvalid input!\n");
    }

    return 0;
}