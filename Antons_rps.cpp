#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <map>
#include <string>

using namespace std;

// Enum class that represents choices with a number.
enum class Choice
{
    ROCK,
    PAPER,
    SCISSOR,
    INVALID,
    STOP,
    HELP,
    STATS
};

// Struct to hold scores.
struct Statistics
{
    int userScore = 0;
    int aiScore = 0;
    int ties = 0;
    int userWins = 0;
    int aiWins = 0;
    int rockWins = 0;
    int paperWins = 0;
    int scissorWins = 0;
    int userTotalRounds = 0;
    int aiTotalRounds = 0;
    int tiesTotal = 0;
};

// Global variables
Statistics gameStats;

// Function declaration
Choice askUser();
Choice randChoice();
string choiceToString(Choice choice);
void printWinner(Choice userChoice, Choice aiChoice);
int setPointsToWin();
void game();
void printScore();
void printInstructions();
void printMenu();
void menuChoice(int &choice);

// Main
int main()
{
    srand(time(0));
    int choice;

    do
    {
        printMenu();
        menuChoice(choice);

        switch (choice)
        {
        case 1:
            game();
            break;
        case 2:
            printScore();
            break;
        case 3:
            printInstructions();
            break;
        case 4:
            cout << "Exiting the game..\n";
            break;
        }
    } while (choice != 4);
    return 0;
}

// Function to get user input.
Choice askUser(Choice &lastUserChoice)
{
    string answer;
    Choice userChoice = Choice::INVALID;

    while (userChoice == Choice::INVALID)
    {
        cout << "\nRock, paper or scissor? [Enter] to repeat previous input: ";
        getline(cin, answer);

        if (answer.empty() && lastUserChoice != Choice::INVALID)
        {
            userChoice = lastUserChoice;
            cout << "Repeating...\n";
        }

        else
        {
            transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

            if (answer == "help")
            {
                userChoice = Choice::HELP;
            }
            else if (answer == "stats")
            {
                userChoice = Choice::STATS;
            }
            else if (answer == "stop")
            {
                userChoice = Choice::STOP;
            }
            else if (answer.find("r") == 0)
            {
                userChoice = Choice::ROCK;
                lastUserChoice = userChoice;
            }
            else if (answer.find("s") == 0)
            {
                userChoice = Choice::SCISSOR;
                lastUserChoice = userChoice;
            }
            else if (answer.find("p") == 0)
            {
                userChoice = Choice::PAPER;
                lastUserChoice = userChoice;
            }
            else
            {
                cout << "Invalid input, try again. \n";
            }
        }
    }
    return userChoice;
}

// Function to generate ai choice.
Choice randChoice()
{
    int randomChoice = rand() % 3;

    switch (randomChoice)
    {
    case 0:
        return Choice::ROCK;
    case 1:
        return Choice::SCISSOR;
    default:
        return Choice::PAPER;
    }
}

// Function to convert choices to strings.
string choiceToString(Choice choice)
{
    switch (choice)
    {
    case Choice::ROCK:
        return "Rock";
    case Choice::PAPER:
        return "Paper";
    case Choice::SCISSOR:
        return "Scissor";
    default:
        return "Error";
    }
}

// Function to compare ai and user choice and print result.
void printWinner(Choice userChoice, Choice aiChoice)
{
    string userStr = choiceToString(userChoice);
    string aiStr = choiceToString(aiChoice);
    Choice winningChoice;

    cout << "\nYour choice: " << userStr << endl;
    cout << "Computers choice: " << aiStr << endl;

    if (userChoice == aiChoice)
    {
        cout << "\nIt's a tie.\n";
        gameStats.ties++;
        gameStats.tiesTotal++;
    }
    else if ((userChoice == Choice::ROCK && aiChoice == Choice::SCISSOR) ||
             (userChoice == Choice::SCISSOR && aiChoice == Choice::PAPER) ||
             (userChoice == Choice::PAPER && aiChoice == Choice::ROCK))
    {
        cout << "\nYou won this round :D\n";
        gameStats.userScore++;
        gameStats.userTotalRounds++;
        winningChoice = userChoice;
    }
    else
    {
        cout << "\nComputer won this round :(\n";
        winningChoice = aiChoice;
        gameStats.aiTotalRounds++;
        gameStats.aiScore++;
    }
    switch (winningChoice)
    {
    case Choice::ROCK:
        gameStats.rockWins++;
        break;
    case Choice::SCISSOR:
        gameStats.scissorWins++;
        break;
    case Choice::PAPER:
        gameStats.paperWins++;
        break;
    default:
        break;
    }
}

// Function to set points.
int setPointsToWin()
{
    int pointsToWin = 3;
    string input;
    while (true)
    {
        cout << "\nSet the number of points needed to win the Rock-Paper-Scissors "
                "match (default 3): ";
        getline(cin, input);
        if (input.empty())
        {
            cout << "Winner will need 3 points to win.\n";
            break;
        }
        try
        {
            pointsToWin = stoi(input);
            if (pointsToWin > 0)
            {
                cout << "Winner will need " << pointsToWin << " point to win.\n";
                break;
            }
            else
            {
                cout << "Invalid value. The number of points must be greater than 0. "
                        "Please try again.\n";
            }
        }
        catch (const invalid_argument &)
        {
            cout << "Invalid input. Please enter a valid number.\n";
        }
        catch (const out_of_range &)
        {
            cout << "Too many points. Please enter a smaller number.\n";
        }
    }
    return pointsToWin;
}

// Function to run game.
void game()
{
    gameStats.userScore = 0;
    gameStats.aiScore = 0;
    gameStats.ties = 0;
    Choice lastUserChoice = Choice::INVALID;
    int pointsToWin = setPointsToWin();

    while (gameStats.userScore < pointsToWin && gameStats.aiScore < pointsToWin)
    {
        Choice userChoice = askUser(lastUserChoice);
        if (userChoice == Choice::STOP)
        {
            cout << "The game has ended.\n";
            return;
        }
        else if (userChoice == Choice::HELP)
        {
            printInstructions();
            continue;
        }
        else if (userChoice == Choice::STATS)
        {
            printScore();
            continue;
        }
        Choice aiChoice = randChoice();
        printWinner(userChoice, aiChoice);

        cout << "\nThe score: You " << gameStats.userScore << " - Computer "
             << gameStats.aiScore << " - Ties " << gameStats.ties << endl;
        cout << "\n--------------------------------------" << endl;
    }

    if (gameStats.userScore == pointsToWin)
    {
        cout << "You won the game :D\n";
        gameStats.userWins++;
    }
    else
    {
        cout << "Computer won the game :(\n";
        gameStats.aiWins++;
    }
}

// Function to print statistics.
void printScore()
{
    cout << "\n--- Statistics ---\n";
    cout << "Player matches wins: " << gameStats.userWins << endl;
    cout << "Computer matches wins: " << gameStats.aiWins << endl;
    cout << "Player round wins: " << gameStats.userTotalRounds << endl;
    cout << "Computer round wins: " << gameStats.aiTotalRounds << endl;
    cout << "Ties: " << gameStats.tiesTotal << endl;
    cout << "-------------------\n";
    cout << "Rock Wins: " << gameStats.rockWins << endl;
    cout << "Paper Wins: " << gameStats.paperWins << endl;
    cout << "Scissor Wins: " << gameStats.scissorWins << endl;
    cout << "-------------------\n";
}

// Function to print docs
void printInstructions()
{
    cout << "\n--------------- How to Play ---------------\n\n";
    cout << "Type 'rock', 'paper', or 'scissor' to make your move.\n";
    cout << "You can also just type 'r', 'p', or 's'.\n";
    cout << "Press Enter to repeat your last choice.\n";
    cout << "Type 'stop' to exit a round.\n";
    cout << "Type 'help' to review instructions.\n";
    cout << "Type 'stats' to see statistics during a game.\n";
    cout << "\n---------------------------------------------\n";
}

// Function to print menu.
void printMenu()
{
    cout << "\n --- Menu ---\n";
    cout << "1. Start a new game\n";
    cout << "2. Print statistics\n";
    cout << "3. View instructions\n";
    cout << "4. Exit the game\n";
}

// Function to get a choice from user.
void menuChoice(int &choice)
{
    string input;
    while (true)
    {
        cout << "Enter your choice [1-4]: ";
        getline(cin, input);
        if (input.empty())
        {
            cout << "Please make a choice.\n";
            continue;
        }
        bool isNumber = all_of(input.begin(), input.end(), ::isdigit);
        if (!isNumber)
        {
            cout << "Invalid input, please enter a number between 1 and 4.\n";
            continue;
        }
        choice = stoi(input);
        if (choice >= 1 && choice <= 4)
        {
            break;
        }
        else
        {
            cout << "Invalid number, please choose a number between 1 and 4.\n";
        }
    }
}