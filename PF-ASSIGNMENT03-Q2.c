#include <stdio.h>
#include <string.h>

#define max_balls 12

struct Player {
    int ballScores[max_balls];
    char playerName[50];
    int totalScore;
};

void playGame(struct Player *player) {
    printf("Enter player name: ");
    scanf("%s", player->playerName);

    printf("Enter scores for each ball:\n");
    for (int i = 0; i < max_balls; i++) {
        printf("Ball %d: ", i + 1);
        scanf("%d", &player->ballScores[i]);
        player->totalScore = player->totalScore + player->ballScores[i];
    }
}

int validateScore(int score) {
    return score >= 0 && score <= 6;
}

void findWinner(struct Player player1, struct Player player2) {
    if (player1.totalScore > player2.totalScore) {
        printf("%s wins!\n", player1.playerName);
    } else if (player2.totalScore > player1.totalScore) {
        printf("%s wins!\n", player2.playerName);
    } else {
        printf("It's a tie!\n");
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) {
    float avg;
	printf("\nMatch Scoreboard\n");
    printf("--------------------\n");
    printf("%s:\n", player1.playerName);
    for (int i = 0; i < max_balls; i++) {
        printf("Ball %d: %d\n", i + 1, player1.ballScores[i]);
    }
    printf("Total Score: %d\n", player1.totalScore);
    avg = player1.totalScore / max_balls;
    printf("Average Score: %.2f\n", avg);

    printf("\n%s:\n", player2.playerName);
    for (int i = 0; i < max_balls; i++) {
        printf("Ball %d: %d\n", i + 1, player2.ballScores[i]);
    }
    printf("Total Score: %d\n", player2.totalScore);
    avg = player2.totalScore / max_balls;
    printf("Average Score: %.2f\n", avg);
}

int main() {
    struct Player player1, player2;

    playGame(&player1);
    playGame(&player2);

    findWinner(player1, player2);
    displayMatchScoreboard(player1, player2);

    return 0;
}