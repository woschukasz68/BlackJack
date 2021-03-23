#ifndef BOT_H
#define BOT_H

#include "Player.h"
#include <sstream>

class Casino;

class Bot: public Player
{
public:
	Bot() = default;
	Bot(Casino* casino);
	~Bot();
	virtual void setName()override;
	virtual bool getWantToPlay() override;
	virtual void reset() override;
	

private:
	static int m_id;
	int m_level{};
	void setLevel();
};

#endif 



