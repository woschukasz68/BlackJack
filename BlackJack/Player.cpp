#include "Player.h"
#include "Casino.h"

Player::~Player()
{
	m_cleanCards();
}

Player::Player(Casino* casino) : m_casino{ casino }, m_wantToPlay{ true }, m_points{0}, m_overPoints{ false }
{

}

void Player::giveCard()
{
	m_cards.push_back(m_casino->getCard());
	m_points += m_cards[m_cards.size() - 1]->getPoints();
}

void Player::showCards()
{
	for (auto card : m_cards) {
		std::cout<<card->getPoints();
	}
}

void Player::setName()
{
	std::string name;
	std::cout << " Give name: ";
	std::cin >> name;
	m_name = name;
}

bool Player::getWantToPlay()
{
	if (m_wantToPlay == true) {
		bool isGood{ true };
		while (isGood) {
			std::cout << m_name << " do you want to play? y/n : ";
			std::string choice;
			std::cin >> choice;
			if (choice.size() > 1) {
				system("CLS");
				continue;
			}
			switch (choice[0]) {
			case 'y':
				m_wantToPlay = true;
				isGood = false;
				break;
			case 'n':
				m_wantToPlay = false;
				isGood = false;
				break;
			default:
				system("CLS");
				continue;
			}
			return m_wantToPlay;
		}


	}
	else {
		return m_wantToPlay;
	}
}

bool Player::getOverPoints() 
{
	if (m_points < 21) {
		m_overPoints = false;
	}
	else {
		m_overPoints = true;
	}
		

	return m_overPoints;
}

std::string Player::getName() const
{
	return m_name;;
}

int Player::getPoints() const
{
	return m_points;
}

void Player::reset()
{
	m_cleanCards();
	m_cards.clear();
	m_points = 0;
	m_wantToPlay = true;
	m_overPoints = false;
	
}

void Player::m_cleanCards()
{
	for (auto& card : m_cards) {
		delete card;
	}
}

std::ostream& operator<<(std::ostream& out, Player& player)
{
	out << player.getName() << " have " << player.getPoints() << "\t";
	return out;
}
