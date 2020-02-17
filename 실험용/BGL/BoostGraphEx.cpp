#include "pch.h"
#include <iostream>                  // for std::cout
#include <utility>                   // for std::pair
#include <algorithm>                 // for std::for_each
#include <../../boost/graph/graph_traits.hpp>
#include <../../boost/graph/adjacency_list.hpp>
#include <../../boost/graph/dijkstra_shortest_paths.hpp>
#include "BoostGraphEx.h"


void User_Example()
{
	typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS,
		MonsterType, Evolution_Condition> Graph;

	{
		typedef std::pair<int, int> Pair;
		Pair edge_array[6] = {
			Pair(0,1), Pair(0,2),
			Pair(1,0), Pair(1,2),
			Pair(2,0), Pair(2,3),
		};

		MonsterType vertex_property_array[4] = {
			MonsterType("Slime", 5), MonsterType("Slime", 4),
			MonsterType("Slime", 1), MonsterType("Slime", 2)
		};

		Evolution_Condition edge_property_array[6] = {
			Evolution_Condition(1, 11), Evolution_Condition(1, 132),
			Evolution_Condition(3, 22), Evolution_Condition(11, 152),
			Evolution_Condition(5, 321), Evolution_Condition(21, 637)
		};

		Graph tree(edge_array, edge_array + sizeof(edge_array) / sizeof(Pair),
			edge_property_array, sizeof(vertex_property_array) / sizeof(MonsterType)); // default intialize

		for (int i = 0; i < sizeof(vertex_property_array) / sizeof(MonsterType); i++)
			tree[i] = vertex_property_array[i];


		typedef boost::graph_traits<Graph>::vertex_iterator vertex_iter;
		typedef boost::graph_traits<Graph>::edge_iterator edge_iter;

		std::pair<vertex_iter, vertex_iter> vp;
		std::cout << "vertices = \n";
		for (vp = boost::vertices(tree); vp.first != vp.second; ++vp.first)  // first 는 그래프 첫번째, second 는 끝부분
			std::cout << *vp.first << " " << tree[*vp.first].code << " " << tree[*vp.first].name << std::endl;

		std::cout << "edges = \n";
		edge_iter ei, ei_end;
		for (boost::tie(ei, ei_end) = boost::edges(tree); ei != ei_end; ++ei)
			std::cout << "(" << boost::source(*ei, tree) << "," << boost::target(*ei, tree) << ") " <<
			"property " << tree[*ei].lv << std::endl;

		std::for_each(boost::vertices(tree).first, boost::vertices(tree).second, print_outedge<Graph>(tree));
		//std::for_each(boost::vertices(tree).first, boost::vertices(tree).second, print_inedge<Graph>(tree));
		//std::for_each(boost::vertices(tree).first, boost::vertices(tree).second, print_adjacency<Graph>(tree));

		std::vector<int> d(boost::num_vertices(tree));

		// invoke variant 2 of Dijkstra's algorithm
		boost::dijkstra_shortest_paths(tree, *(boost::vertices(tree).first), boost::no_named_parameters().weight_map(boost::get(&Evolution_Condition::lv, tree)).distance_map(&d[0]));
		std::cout << "distances from start vertex:" << std::endl;
		boost::graph_traits<Graph>::vertex_iterator vi;
		for (vi = vertices(tree).first; vi != vertices(tree).second; ++vi)
			std::cout << "distance(" << *vi << ") = " << d[*vi] << std::endl;
		std::cout << std::endl;
	}
}

