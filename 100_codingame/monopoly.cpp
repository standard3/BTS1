#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Player
{
    string username;
    int position;
} Player;

int main()
{
    vector <Player> playerList;
    
    int totalPlayers;
    int totalDices;
    string dice;
    string boardline;

    // Retrieving total players
    cin >> totalPlayers; cin.ignore();
    for (int i = 0; i < totalPlayers; i++)
    {
        // "<playerName> <initialPosition>"
        string player;
        getline(cin, player);

        size_t pos = player.find(" ");

        Player tmp = { player, stoi(player.substr(pos))};
        playerList.push_back(tmp);
    }

    // Retrieving number of dices rolls in playing order
    cin >> totalDices; cin.ignore();
    for (int i = 0; i < totalDices; i++)
    {
        string dice;
        getline(cin, dice);
        cout << dice;
    }

    for (int i = 0; i < 40; i++)
    {
        string boardline;
        getline(cin, boardline);
    }

    

    bool gameLoop = true;
    for (int i = 0; gameLoop == 1; i++)
    {
        break;
    }

}