#include <iostream>
#include <algorithm>
enum class Item
{
	HEAL_POTION,
	ARROW,
	FIRE_STICK,
};
int countTotalItems(Item *arr, size_t size);
int main()
{
	Item inventory[21];
	int i{0};
	for(Item *ref{&inventory[0]}; ref < (&(inventory[0])) + 21; ++ref)
	{
		if(i < 3)	*ref = Item::HEAL_POTION;
		else if(i < 9)	*ref = Item::FIRE_STICK;
		else if(i < 21) *ref = Item::ARROW;
		++i;
	}
	std::cout << countTotalItems(inventory, 21) << std::endl;
	return 0;	
}
	int countTotalItems(Item *arr, size_t size)
	{
		auto con{[](Item &vl){return true;}};
		auto cnt{std::count_if(arr, arr + size, con)};
		return cnt;
	}


