/*
 * Rock Paper Scissors Game
 * Team 1
 * Concepts: Random Numbers, Loops, Conditions
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int userChoice, compChoice;
    int userScore = 0, compScore = 0;
    const char *items[] = {"Rock", "Paper", "Scissors"};

    srand(time(0));
    printf("=========================================\n");
    printf("    ROCK - PAPER - SCISSORS TOURNAMENT   \n");
    printf("=========================================\n");

    for (int round = 1; round <= 5; round++) {
        printf("\n--- Round %d/5 ---\n", round);
        printf("1. Rock | 2. Paper | 3. Scissors\nEnter choice (1-3): ");
        if (scanf("%d", &userChoice) != 1 || userChoice < 1 || userChoice > 3) {
            printf("Invalid input! Round forfeited.\n");
            continue;
        }

        compChoice = (rand() % 3) + 1;
        printf("You picked    : %s\n", items[userChoice - 1]);
        printf("Computer picked: %s\n", items[compChoice - 1]);

        if (userChoice == compChoice) {
            printf(">> Result: Tie round!\n");
        } else if ((userChoice == 1 && compChoice == 3) ||
                   (userChoice == 2 && compChoice == 1) ||
                   (userChoice == 3 && compChoice == 2)) {
            printf(">> Result: You WIN this round!\n");
            userScore++;
        } else {
            printf(">> Result: Computer WINS this round!\n");
            compScore++;
        }
        printf("Scoreboard -> You: %d | Computer: %d\n", userScore, compScore);
    }

    printf("\n================ FINAL OUTCOME ================\n");
    printf("Final Score -> User: %d | Computer: %d\n", userScore, compScore);
    if (userScore > compScore) printf(">>> CHAMPION! You won the match! <<<\n");
    else if (userScore < compScore) printf(">>> Computer won the tournament! Try again! <<<\n");
    else printf(">>> Series tied overall! <<<\n");
    printf("===============================================\n");

    return 0;
}
