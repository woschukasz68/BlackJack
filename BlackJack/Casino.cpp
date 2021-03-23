#include "Casino.h"
class Bot;
class Player;

Casino::Casino() : m_takenCards{ 0 }, m_number_players{ 0 }, m_play{ true }, m_notTheEnd{true}
{
	setDeck();
}

Casino::~Casino()
{
	m_cleanPlayers();
	m_cleanCards();
}

void Casino::setDeck()
{
	int counter{ 0 };
	for (int i{ 0 }; i < static_cast<int>(COLOR::MAX_COLOR); ++i) {
		for (int j{ 0 }; j < static_cast<int>(VALUE::MAX_VALUE); ++j) {
			m_deck[counter] = new Card(static_cast<COLOR>(i), static_cast<VALUE>(j));
			++counter;
		}
	}
}

void Casino::shuffle()
{
	std::shuffle(m_deck.begin(), m_deck.end(), std::default_random_engine(seed));
}

void Casino::showDeck()
{
	for (auto card : m_deck) {
		std::cout << card->getPoints();
	}
}

void Casino::setPlayers()
{
	bool isGood{ true };
	while (isGood) {
		std::cout << "How many players? [1-3] : ";
		std::string numbers{};
		std::cin >> numbers;
		if (numbers.size() > 1) {
			system("CLS");
			continue;
		}
		switch (numbers[0]) {
		case '1':
				for (int i{ 0 }; i < 1; ++i) {
					m_players.push_back(new Player(this));
					m_players[m_number_players]->setName();
					m_number_players++;
				}
				isGood = false;
				break;
		case '2':
			for (int i{ 0 }; i < 2; ++i) {
				m_players.push_back(new Player(this));
				m_players[m_number_players]->setName();
				m_number_players++;
			}
			isGood = false;
			break;
		case '3':
			for (int i{ 0 }; i <3; ++i) {
				m_players.push_back(new Player(this));
				m_players[m_number_players]->setName();
				m_number_players++;
			}
			isGood = false;
			break;
		default:
			system("CLS");
			continue;
		}	
	}
	system("CLS");
	isGood = true;
	while (isGood) {
		std::cout << "How many boots? [1-3] : ";
		std::string numbers{};
		std::cin >> numbers;
		if (numbers.size() > 1) {
			system("CLS");
			continue;
		}
		switch (numbers[0]) {
		case '1':
			for (int i{ 0 }; i < 1; ++i) {
				m_players.push_back(new Bot(this));
				m_players[m_number_players]->setName();
				m_number_players++;
			}
			isGood = false;
			break;
		case '2':
			for (int i{ 0 }; i < 2; ++i) {
				m_players.push_back(new Bot(this));
				m_players[m_number_players]->setName();
				m_number_players++;
			}
			isGood = false;
			break;
		case '3':
			for (int i{ 0 }; i < 3; ++i) {
				m_players.push_back(new Bot(this));
				m_players[m_number_players]->setName();
				m_number_players++;
			}
			isGood = false;
			break;
		default:
			system("CLS");
			continue;
		}
	}
	system("CLS");
}



Card* Casino::getCard()
{
	return m_deck[m_takenCards++];
	
}

void Casino::game()
{
	shuffle();
	setPlayers();
	while (m_play) {
		int counter{ 0 };
		for (auto player : m_players) {
			if (!player->getOverPoints()) {
				if (player->getWantToPlay()) {
					player->giveCard();
				}
				else
					++counter;
			}
			else
				++counter;

		}
		if (counter == m_number_players) {
			whoWin();
			m_play = play();
		}
		else {
			std::cout << "\n";
			for (auto*player : m_players) {
				std::cout << *player;
			}
			std::cout << "\n";
			std::cout << "\n";
		}
	}
}

void Casino::whoWin()
{
	int max{ 0 };
	for (auto* player : m_players) {
		if (player->getPoints() <= 21&& player->getPoints()>max) {
			max = player->getPoints();
		}
	}
	auto numberOfMaxResult{ std::count_if(m_players.begin(),m_players.end(),[&max](const Player* player) {
		return (player->getPoints() == max);
}) };
	std::sort(m_players.begin(), m_players.end(), [](const Player* player1, const Player* player2) {
		return (player1->getPoints() > player2->getPoints());
		});
	
	if (max == 0) {
		std::cout << "Everyone lose!\n";
	}
	else  {
		std::cout << "The winner is : ";
		for (auto* player : m_players) {
			if (player->getPoints() == max)
				std::cout << player->getName()<<" ";
		}
	}
	
}

bool Casino::play()
{
	char choice{};
	std::cout << "\n\nDo you wanna play ? [y/n] : ";
	std::cin >> choice;
	switch (choice) {
	case 'y':
		reset();
		shuffle();
		setPlayers();
		return true;
		break;
	case 'n':
		return false;
		break;
	default:
		std::cerr << "ERROR";
		std::exit(0);
	}

}

void Casino::reset()
{
	for (auto* player : m_players) {
		player->reset();
	}
	m_cleanPlayers();
	m_cleanCards();
	m_players.clear();
	m_number_players = 0;
	m_takenCards = 0;
	m_play = true;
	setDeck();
}

void Casino::menu()
{

	std::cout << " Welcome in BlackJack game !!!";
	while (m_notTheEnd) {
		std::cout<< "\n\nChoice\n - p : play\n - i : information\n - q : quit\n";
		std::string choice{};
		std::cin >> choice;
		if (choice.size() > 1) {
			system("CLS");
			continue;
		}
			
		switch (choice[0]) {
		case'p':
			system("CLS");
			game();
			m_notTheEnd = false;
			break;
		case 'i':
			system("CLS");
			showInfo();
			break;
		case 'q':
			m_notTheEnd = false;
			break;
		default:
			system("CLS");
			break;
		}
	}
	
}

void Casino::showInfo()
{
	std::cout << "The North American game of Blackjack, also known as 21, has been one of the most popular casino games of the last hundred ";
	std::cout << "years and has spread throughout the world. In the 21st century it has been overtaken in popularity by Slots (slot machine games),";
	std::cout << "but it remains one of the most popular casino card games and is available in almost all casinos both on and offline.";

	std::cout << "Blackjack is a casino banked game, meaning that players compete against the house rather than each other.The objective ";
	std::cout << "is to get a hand total of closer to 21 than the dealer without going over 21";
}

void Casino::m_cleanPlayers()
{
	for (auto& i : m_players) {
		delete i;
	}
}

void Casino::m_cleanCards()
{
	for (int i{ m_takenCards }; i < std::size(m_deck); ++i) {
		delete m_deck[i];
	}
}
