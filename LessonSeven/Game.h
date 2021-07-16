#ifndef _GAME_H_
#define _GAME_H_

class Game
{
public:
    Game(const vector<string>& names);

    ~Game();

    // проводит игру в Blackjack
    void Play();

private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
};

#endif //_GAME_H_
