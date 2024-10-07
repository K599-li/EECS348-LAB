#include <stdio.h>

// Function to find all unique combinations of scoring plays that result in the given score
void findCombinations(int score) {
    int td, fg, safety, td_plus_2pt, td_plus_fg;

    // Loop through all possible numbers of TD + 2pt
    for (td_plus_2pt = 0; td_plus_2pt <= score / 8; td_plus_2pt++) {
        // Loop through all possible numbers of TD + FG
        for (td_plus_fg = 0; td_plus_fg <= (score - 8 * td_plus_2pt) / 7; td_plus_fg++) {
            // Loop through all possible numbers of TD 
            for (td = 0; td <= (score - 8 * td_plus_2pt - 7 * td_plus_fg) / 6; td++) {
                // Loop through all possible numbers of FG
                for (fg = 0; fg <= (score - 8 * td_plus_2pt - 7 * td_plus_fg - 6 * td) / 3; fg++) {
                    // Calculate remaining score for safeties
                    safety = score - 8 * td_plus_2pt - 7 * td_plus_fg - 6 * td - 3 * fg;
                    // Safety points must be a non-negative multiple of 2
                    if (safety % 2 == 0 && safety >= 0) {
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                               td_plus_2pt, td_plus_fg, td, fg, safety / 2);
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 0 or 1 to STOP): ");
        scanf("%d", &score);
        
        if (score <= 1) {
            printf("Terminating the program.\n");
            break;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
        findCombinations(score);
        printf("\n");
    }

    return 0;
}
