#include "pch.h"



void whyTemplate()
{
	std::list<int, std::allocator<int>> list;

	for (int i = 0; i < 100; i++)
		list.emplace_back(i);

	auto i = list.begin();
	for (auto n = 0; n < list.size() - 1; n++)
	{
		std::cout << *i << std::endl;
		i++;
	}
}
