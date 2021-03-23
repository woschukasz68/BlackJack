#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include<string>
#include<vector>

class Casino;
class Card;

class Player
{
public:
	Player() = default;
	virtual ~Player();
	Player(Casino* casino);
	void giveCard();
	void showCards();
	bool getOverPoints();
	std::string getName() const;
	int getPoints()const;
	virtual void setName();
	virtual bool getWantToPlay();
	virtual void reset();

	friend std::ostream& operator <<(std::ostream& out, Player& player);

protected:
	std::vector<Card*> m_cards{};
	Casino* m_casino;
	std::string m_name{};
	bool m_wantToPlay{};
	int m_points{};
	bool m_overPoints{};
	virtual void m_cleanCards();
};

#endif


