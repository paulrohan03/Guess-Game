#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    cout << "\n\t\t\tWelcome to the GuessTheNumber game!" << endl;
    cout << "Try to guess a number between 1 and 100. "
            "You'll have a limited number of attempts based on the "
            "difficulty level you choose. Good Luck!"
         << endl;

    while (true) {
        cout << "\nEnter the difficulty level: \n";
        cout << "1 for easy!\t";
        cout << "2 for medium!\t";
        cout << "3 for difficult!\t";
        cout << "0 to end the game!\n" << endl;

        int difficultyChoice;
        cout << "Enter your choice: ";
        cin >> difficultyChoice;

        srand(time(0));
        int secretNumber = 1 + (rand() % 100);
        int playerChoice;

        int maxAttempts;
        string difficultyLabel;

        switch (difficultyChoice) {
            case 1:
                maxAttempts = 10;
                difficultyLabel = "easy";
                break;
            case 2:
                maxAttempts = 7;
                difficultyLabel = "medium";
                break;
            case 3:
                maxAttempts = 5;
                difficultyLabel = "difficult";
                break;
            case 0:
                exit(0);
            default:
                cout << "Invalid choice! Please enter 0, 1, 2, or 3." << endl;
                continue;
        }

        cout << "\nYou have " << maxAttempts << " attempts to find the "
                "secret number between 1 and 100 in " << difficultyLabel << " mode." << endl;

        for (int attempt = 1; attempt <= maxAttempts; attempt++) {
            cout << "\nEnter your guess (Attempt " << attempt << "): ";
            cin >> playerChoice;

            if (playerChoice == secretNumber) {
                cout << "Congratulations! You've won. "
                    << playerChoice
                    << " is the secret number." << endl;
                cout << "\t\t\t Thanks for playing...."
                    << endl;
                cout << "Play the game again with "
                        "us!!\n\n"
                    << endl;
                break;
            } else {
                cout << "Incorrect, " << playerChoice
                    << " is not the correct number." << endl;
                cout << "The secret number is "
                        << ((playerChoice > secretNumber) ? "smaller" : "greater")
                        << " than the number you have chosen." << endl;
                int attemptsLeft = maxAttempts - attempt;
                cout << attemptsLeft << " attempts left. "
                    << endl;

                if (attemptsLeft == 0) {
                    cout << "You couldn't find the "
                            "secret number. It was "
                        << secretNumber
                        << ". You lose!!\n\n";
                    cout << "Play the game again to "
                            "win!!!\n\n";
                }
            }
        }
    }
    return 0;
}

