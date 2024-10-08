#include <stdio.h>
#include <stdlib.h>

#define GUESS_RANGE 100

int main() {
    int lower_bound = 1, higher_range = GUESS_RANGE;
    char answer;
    int guess;
    int attempts = 0;

    printf("Think a number between 1 and %d, and I'll try to guess it!\n", GUESS_RANGE); // asking a user to think about a number

    // Continue guessing using while loop to validate the range
    while (lower_bound <= higher_range) {       // checking the boundaries
        guess = (lower_bound + higher_range) / 2;
        attempts++;
        printf("I guessed %d.\n", guess);
        printf("rules of the game. \n");
        printf("If the number you though about is HIGHER than my guess, enter 'H'.\n");  
        printf("If the number you though about is LOWER than my guess, enter 'L'.\n");
        printf("If my guess is correct, enter '='.\n");
        printf("Type your response: ");   // asking a user to type reponse
        scanf(" %c", &answer);             // save the response

        if (answer == 'H') {               // comparing the answer with the guess
            lower_bound = guess + 1;
        } else if (answer == 'L') {
            higher_range = guess - 1;
        } else if (answer == '=') {
            printf("Got the right number with %d guesses!\n", attempts);
            break;  // used break to end the game if the guesses match
        } else {
            printf("incorrect entry '%c'. Please enter between H, L, or =\n", answer); // incase you write something that is not H,L or =
        }
    }
// adding the inconsistency
 if (lower_bound > higher_range) {
    
    printf("Inconsistent responses found. Exiting the program...\n");
 }

  return 0;
}
