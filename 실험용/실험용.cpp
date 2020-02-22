#include "pch.h"
#include "BGL/Tree.h"

void main()
{
	std::vector<MonsterType> vertex_p = {
		MonsterType("snail", nullptr), MonsterType("snail_blue", nullptr), MonsterType("snail_red", nullptr), 
		MonsterType("stump", nullptr), MonsterType("slime", nullptr)
	};
	std::vector<Evolution_Condition> edge_p = {
		Evolution_Condition(1, 2, 3, 4, 5), Evolution_Condition(1, 2, 3, 4, 5), Evolution_Condition(1, 2, 3, 4, 5),
		Evolution_Condition(1, 2, 3, 4, 5),	Evolution_Condition(1, 2, 3, 4, 5)
	};
	std::vector<std::pair<int, int>> edges = {
		std::pair(0, 1), std::pair(1, 2), std::pair(2, 3), std::pair(2, 4)
	};
	
	auto tree = new Tree<MonsterType, Evolution_Condition>();

	{
		tree->Init(vertex_p, edge_p, edges);
		tree->Print();
		for (auto& a : tree->GetAdjacentDatas(MonsterType("snail", nullptr)))
			std::cout << a.name << std::endl;
	}
	delete tree;
}