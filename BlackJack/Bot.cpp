#include "Bot.h"

int Bot::m_id{ 49 };
Bot::Bot(Casino* casino):Player(casino)

{
	setLevel();
}

Bot::~Bot()
{
	
}

void Bot::setName() 
{
	char c{ static_cast<char>(m_id) };
	std::string s;
	std::stringstream ss;
	ss << c;
	ss >> s;
	m_name = "BOT"+s;
	m_id++;
}

bool Bot::getWantToPlay()
{
	switch (m_level){

	case 1:
		if (m_points > 14) 
			m_wantToPlay = false;
		else
			m_wantToPlay = true;
		break;
	case 2:
		if(m_points>16)
			m_wantToPlay = false;
		else
			m_wantToPlay = true;
		break;
	case 3:
		if (m_points > 18)
			m_wantToPlay = false;
		else
			m_wantToPlay = true;
		break;
	default:
		std::cerr << "ERROR";
		return -1;
	}
	return m_wantToPlay;
}

void Bot::reset()
{
	Player::reset();
	m_id = 49;
}

void Bot::setLevel()
{
	bool isGood{ true };
	while (isGood) {
		std::cout << " Choice bot level: 1 2 3: ";
		std::string level;
		std::cin >> level;
		if (level.size() > 1) {
			system("CLS");
			continue;
		}
		switch (level[0]) {
		case '1':
			m_level = 1;
			isGood = false;
			break;
		case '2':
			m_level = 2;
			isGood = false;
			break;
		case '3':
			m_level = 3;
			isGood = false;
			break;
		default:
			system("CLS");
			continue;
		}
	}
	
}
