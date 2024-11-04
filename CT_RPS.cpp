#include <iostream>
#include <random>

using namespace std;

#define ROUND_PER_GAME 3

#define ROCK 0
#define PAPER 1
#define SCISSORS 2

struct GameStats
{
    int player_total = 0;
    int pc_total = 0;
    int moves_counter[3] = {0, 0, 0};
};

const string rpsMoves[3] = {"Rock", "Paper", "Scissors"};

void print_statistics(GameStats stats)
{
    cout << endl;
    cout << "---------STATISTICS----------" << endl;
    cout << "-----------------------------" << endl;
    cout << "Player wins: " << stats.player_total << "" << endl;
    cout << "Computer wins: " << stats.pc_total << "" << endl;
    cout << "Games played: " << stats.player_total + stats.pc_total << "" << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Move " << rpsMoves[i] << " :" << stats.moves_counter[i] << endl;
    }
}

void game(GameStats &stats)
{
    // Returns true if player wins, false if computer wins
    int pc_score = 0;
    int player_score = 0;

    while (pc_score < ROUND_PER_GAME && player_score < ROUND_PER_GAME)
    {
        int pc_move = rand() % 3;
        int player_move;

        do
        {
            cout << "Rock (0), Paper (1) or Scissors (2)?\n";
            cin >> player_move;
        } while (player_move < 0 || player_move > 2);

        cout << "Player: " << rpsMoves[player_move] << "\n";
        cout << "Computer: " << rpsMoves[pc_move] << "\n";

        stats.moves_counter[player_move]++;
        stats.moves_counter[pc_move]++;

        if (player_move == pc_move)
        {
            cout << "It's a tie!\n";
        }
        else if ((player_move == ROCK && pc_move == SCISSORS) ||
                 (player_move == PAPER && pc_move == ROCK) ||
                 (player_move == SCISSORS && pc_move == PAPER))
        {
            cout << "Player wins!\n";
            player_score++;
        }
        else
        {
            cout << "Computer wins!\n";
            pc_score++;
        }
    }
    if (player_score == 3)
    {
        stats.player_total++;
    }
    else
    {
        stats.pc_total++;
    }
}

int main()
{
    int menu_answ;
    GameStats stats;

    srand(time(0));

    while (true)
    {
        cout << endl;
        cout << "------------------------------" << endl;
        cout << "\nWELCOME TO ROCK PAPER SCISSOR!" << endl;
        cout << "------------------------------" << endl;
        cout << "NEW GAME (1)" << endl;
        cout << "SHOW STATISTICS (2)" << endl;
        cout << "QUIT (3)" << endl;
        cout << "------------------------------" << endl;

        cout << "What do you want to do?" << endl;
        cin >> menu_answ;
        switch (menu_answ)
        {
        case 1:
            game(stats);
            break;
        case 2:
            print_statistics(stats);
            break;
        case 3:
            cout << "Thank you for playing!" << endl;
            exit(0);

        default:
            cout << "Try again!" << endl;
        }
    }
}