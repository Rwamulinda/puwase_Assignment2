#include <stdio.h>
#include <stdlib.h>

#define GUESS_RANGE 100

int main() {
    int lower_bound = 1, higher_range = GUESS_RANGE;
    char response;
    int guess;
    int attempts = 0;

    printf("Think of a number between 1 and %d, and I'll try to guess it!\n", GUESS_RANGE);

    // Continue guessing while the range is valid (low <= high)
    while (lower_bound <= higher_range) {
        guess = (lower_bound + higher_range) / 2;
        attempts++;
        printf("I guess %d.\n", guess);
        printf("If the answer is HIGHER than my guess, enter 'H'.\n");
        printf("If the answer is LOWER than my guess, enter 'L'.\n");
        printf("If my guess is correct, enter '='.\n");
        printf("Response: ");
        scanf(" %c", &response);

        if (response == 'H') {
            lower_bound = guess + 1;
        } else if (response == 'L') {
            higher_range = guess - 1;
        } else if (response == '=') {
            printf("Got the right number with %d guesses!\n", attempts);
            break;  // End the game if the correct number is guessed
        } else {
            printf("Invalid entry '%c'. Please enter H, L, or =\n", response);
        }
    }

    // If low becomes greater than high, it means there was an inconsistency
    if (lower_bound > higher_range) {
        printf("Inconsistent responses detected. Exiting...\n");
    }

    return 0;
}
