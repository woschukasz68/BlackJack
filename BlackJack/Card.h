#ifndef CARD_H
#define CARD_H
#include<iostream>
enum class COLOR {
	HEART,
	SPADES,
	CLUBS,DIAMONDS,
	MAX_COLOR
};

enum class VALUE {
	TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUIN,KING,AS,MAX_VALUE
};
class Card
{
public:
	Card() = default;
	Card(COLOR color,VALUE value);
	int getPoints() const;
	void setValue();


private:
	COLOR m_color{};
	VALUE m_value{};
	int m_points{};
};


#endif // !CARD_H


