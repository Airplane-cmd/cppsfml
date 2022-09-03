#include <iostream>
#include <array>
#include <cstdlib>
enum class Rank
{
	R2,
	R3,
	R4,
	R5,
	R6,
	R7,
	R8,
	R9,
	R10,
	VALLET,
	LADY,
	KING,
	TYZ,
	LENGHT
};
enum class Suit
{
	TREFY,
	BOOBA,
	CHERVE,
	PICK,
	LENGHT
};
struct Card
{
	Rank rnk;
	Suit st;
};
void printCard(const Card &ref);
void printDeck(std::array<Card, 52> &deck);
void swapCard(Card &a, Card &b);
void shuffleDeck(std::array<Card, 52> &deck);
int getCardValue(const Card &crd);
int main()
{
	srand(time(0));
	std::array<Card, 52> deck;
	int a{0};
	for(Card &vl: deck)
	{
		vl.rnk = static_cast<Rank>(a % static_cast<int>(Rank::LENGHT));
		vl.st = static_cast<Suit>(a / static_cast<int>(Rank::LENGHT));
		++a;	
	}
	printDeck(deck);
	shuffleDeck(deck);
	printDeck(deck);
	std::cout << getCardValue(deck[0]) << std::endl;	
	return 0;
}
int getCardValue(const Card &crd)
{
	int vl{static_cast<int>(crd.rnk)};
	if (vl < 9)		return vl + 2;
	else if(vl < 12)	return 10;
	else 			return 11;
}
void shuffleDeck(std::array<Card, 52> &deck)
{
	for(int i{0}; i < 52; ++i)	swapCard(deck[i], deck[rand() % 53]);
}
void swapCard(Card &a, Card &b)
{
	Card c{a.rnk, a.st};
	a = b;
	b = c;

}
void printDeck(std::array<Card, 52> &deck)
{
	for(Card &vl: deck)	
	{
		printCard(vl);
		std::cout << "  ";
	}
	std::cout << std::endl;
}
void printCard(const Card &ref)
{
	if (static_cast<int>(ref.rnk) < 9)	std::cout << static_cast<int>(ref.rnk) + 2;
	else
	{
		switch(ref.rnk)
		{
			case Rank::VALLET:	std::cout << 'V'; break;
			case Rank::LADY:	std::cout << 'L'; break;
			case Rank::KING:	std::cout << 'K'; break;
			case Rank::TYZ:		std::cout << 'T'; break;
		}
	}
	switch(ref.st)
	{
		case Suit::TREFY:	std::cout << 'T'; break;
		case Suit::BOOBA:	std::cout << 'B'; break;
		case Suit::CHERVE:	std::cout << 'C'; break;
		case Suit::PICK:	std::cout << 'P'; break;
	}
	
}






