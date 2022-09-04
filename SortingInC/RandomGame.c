#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int number = (rand() % 100) + 1;
    
    printf("Guessing Game.\n");
    printf("Choose number [1 - 100], 0 to exit.\n");
    
    int guess = 0;
    do
    {
        printf("Guess [1 - 100] : ");
        scanf("%d", &guess);

        if(guess == 0) printf("Exit Game. Ok.\n");
        else if(guess == number) printf("You got it!\n");
        else if(guess < number) printf("Guess Higher\n");
        else printf("Guess Lower\n");

    } while (number != guess && guess != 0);
    

    printf("Random number is: %d\n", number);

    return 0;
}