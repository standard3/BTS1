#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Player
{
    string  username;
    int     position = 0;
    int     dices[2];
} Player;

int main()
{
    vector  <Player> playerList;
    int     totalPlayers;
    int     totalDices;
    int     maxPosition = 40;
    string  dice;
    string  boardline;
    

    // Retrieving total players
    cin >> totalPlayers; cin.ignore();
    for (int i = 0; i < totalPlayers; i++)
    {
        string username;
        int    position;

        cin >> username >> position;

        Player tmp = { username, position};
        playerList.push_back(tmp);
    }

    // Retrieving number of dices rolls in playing order
    cin >> totalDices; cin.ignore();
    for (int i = 0; i < totalDices; i++)
    {
        string dice;
        getline(cin, dice);
    }

    for (int i = 0; i < maxPosition; i++)
    {
        string boardline;
        getline(cin, boardline);
    }

    

    for (int i = 0; i < totalPlayers; i ++)
        cout << playerList[i].username << " " << playerList[i].position << endl;

}