#include <iostream>
#include <cstdlib>
#include <ctime>
#define print(x) std::cout << x << std::endl;

int main() {
    srand(time(0));
    int RandomNumber = rand() % 100 + 1;
    print("Guess a number between 1 and 100.");

    int userguess;
    bool correct = false;
    std::string again_or_not;

    int moves = 5;

    while (!correct) {
        print("You've got 5 moves!");
        print("Enter your guessed number: ");
        std::cin >> userguess;

        if (moves > 1) {
            if (userguess == RandomNumber) {
                print("Congratulations! You guessed it right.");
                moves--;
                print("You've got it in " << 5 - moves << " moves");
                correct = true;
            }
            else if (userguess > RandomNumber) {
                print("Your guessed number is greater. Try it again!");
                moves--;
                print("Your remaining moves: " << moves);
            }
            else {
                print("Your guessed number is lower. Try it again!");
                moves--;
                print("Your remaining moves: " << moves);
            }
        }
        else {
            print("You are out of moves :(");
            print("Do you want to play it again?");
            print("1. Yes");
            print("2. No");

            int choice;
            std::cin >> choice;

            switch (choice) {
            case 1:
                correct = false;
                RandomNumber = rand() % 100 + 1;
                moves = 5;
                break;
            case 2:
                return 0;
            default:
                print("Invalid choice. Please select 1 or 2.");
            }
        }
    }
    return 0;
}
