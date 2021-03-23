#ifndef CASINO_H
#define CASINO_H

#include "Card.h"
#include "Bot.h"
#include "Player.h"

#include<iostream>
#include<array>
#include<vector>

#include <random>       
#include <chrono> 
#include <algorithm>

class Card;
class Player;

class Casino
{
public:
	
	Casino();
	virtual~Casino();
	void setDeck();
	void shuffle();
	void showDeck();
	void setPlayers();

	Card* getCard();
	void game();
	void whoWin();
	bool play();
	void reset();
	void menu();
	void showInfo();

private:
	
	std::array<Card*, 52> m_deck;
	std::vector<Player*> m_players{};
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	int m_takenCards{};
	int m_number_players{};
	bool m_play{};
	bool m_notTheEnd{};
	void m_cleanPlayers();
	void m_cleanCards();
};

#endif
