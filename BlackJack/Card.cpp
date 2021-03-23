#include "Card.h"

Card::Card(COLOR color, VALUE value): m_color{color},m_value{value}
{
	setValue();
}

int Card::getPoints() const
{
	return m_points;
}

void Card::setValue()
{
	switch (m_value) {
	
	case VALUE::TWO:
		m_points = 2;
		break;
	case VALUE::THREE:
		m_points = 3;
		break;
	case VALUE::FOUR:
		m_points = 4;
		break;
	case VALUE::FIVE:
		m_points = 5;
		break;
	case VALUE::SIX:
		m_points = 6;
		break;
	case VALUE::SEVEN:
		m_points = 7;
		break;
	case VALUE::EIGHT:
		m_points = 8;
		break;
	case VALUE::NINE:
		m_points = 9;
		break;
	case VALUE::TEN:
	case VALUE::JACK:
	case VALUE::QUIN:
	case VALUE::KING:
		m_points = 10;
		break;
	case VALUE::AS:
		m_points = 11;
		break;
	default:
		std::cerr << "ERROR";
		std::exit(0);
	}
}
