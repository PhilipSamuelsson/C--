#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

using namespace std;

void playGame(int &totalGames, int &totalUserWins, int &totalComputerWins, int &totalDraws);
void showStatistics(int totalGames, int totalUserWins, int totalComputerWins, int totalDraws);
string getChoiceName(int choice);

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int choice;
    int totalGames = 0;
    int totalUserWins = 0;
    int totalComputerWins = 0;
    int totalDraws = 0;

    do
    {
        cout << "\n--- Sten, Sax, Påse ---\n";
        cout << "1. Starta nytt spel\n";
        cout << "2. Visa statistik\n";
        cout << "3. Avsluta spelet\n";
        cout << "Välj ett alternativ: ";
        cin >> choice;

        // Input validering
        if (cin.fail())
        {
            cin.clear();                                                   // Clear the error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            cout << "Ogiltigt val. Försök igen.\n";
            choice = 0; // Återställ valet så att loopen fortsätter
            continue;   // starta om loop
        }

        switch (choice)
        {
        case 1:
            playGame(totalGames, totalUserWins, totalComputerWins, totalDraws);
            break;
        case 2:
            showStatistics(totalGames, totalUserWins, totalComputerWins, totalDraws);
            break;
        case 3:
            cout << "Avslutar spelet. Hej då!\n";
            break;
        default:
            cout << "Ogiltigt val. Försök igen.\n";
        }
    } while (choice != 3);

    return 0;
}

void playGame(int &totalGames, int &totalUserWins, int &totalComputerWins, int &totalDraws)
{
    int userScore = 0;
    int computerScore = 0;

    while (userScore < 3 && computerScore < 3)
    {
        int userChoiceNum = 0;

        // Be användaren om ett val och validera det
        while (true)
        {
            cout << "\nAnge ditt val (1 = sten, 2 = påse, 3 = sax): ";
            cin >> userChoiceNum;

            // Input validering
            if (cin.fail() || userChoiceNum < 1 || userChoiceNum > 3)
            {
                cin.clear();                                                   // Clear the error flags
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                cout << "Ogiltigt val. Försök igen.\n";
                continue;
            }
            break; // Avsluta loopen om valet är giltigt
        }

        int computerChoice = rand() % 3 + 1;
        cout << "Datorn valde: " << getChoiceName(computerChoice) << "\n";

        // Bestäm vinnaren
        if (userChoiceNum == computerChoice)
        {
            cout << "Oavgjort!\n";
            totalDraws++;
        }
        else if ((userChoiceNum == 1 && computerChoice == 3) ||
                 (userChoiceNum == 2 && computerChoice == 1) ||
                 (userChoiceNum == 3 && computerChoice == 2))
        {
            cout << "Du vinner denna runda!\n";
            userScore++;
            totalUserWins++;
        }
        else
        {
            cout << "Datorn vinner denna runda!\n";
            computerScore++;
            totalComputerWins++;
        }

        cout << "Ställning - Du: " << userScore << " Datorn: " << computerScore << "\n";
    }

    if (userScore == 3)
    {
        cout << "\nGrattis! Du vann spelet!\n";
    }
    else
    {
        cout << "\nDatorn vann spelet. Bättre lycka nästa gång!\n";
    }

    totalGames++;
}

void showStatistics(int totalGames, int totalUserWins, int totalComputerWins, int totalDraws)
{
    cout << "\n--- Statistik ---\n";
    cout << "Totalt antal spelade spel: " << totalGames << "\n";
    cout << "Antal gånger du vann: " << totalUserWins << "\n";
    cout << "Antal gånger datorn vann: " << totalComputerWins << "\n";
    cout << "Antal oavgjorda: " << totalDraws << "\n";
}

string getChoiceName(int choice)
{
    switch (choice)
    {
    case 1:
        return "sten";
    case 2:
        return "påse";
    case 3:
        return "sax";
    default:
        return "Ogiltigt";
    }
}