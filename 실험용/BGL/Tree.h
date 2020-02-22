#pragma once
#include "pch.h"
#include <../../boost/graph/graph_traits.hpp>
#include <../../boost/graph/adjacency_list.hpp>

struct MonsterType
{
	MonsterType() : name("monster"), data(nullptr) {}
	MonsterType(const std::string& name, void* data) : name(name), data(data) {}
	
	bool operator==(const MonsterType& type) { return name == type.name; }

	std::string name;
	void* data;
};

struct Evolution_Condition
{
	Evolution_Condition() : lv(-1), item_fire(-1), item_water(-1), item_light(-1), item_dark(-1) {}
	Evolution_Condition(const int& lv, const int& fire, const int& water, const int& light, const int& dark) 
		: lv(lv), item_fire(fire), item_water(water), item_light(light), item_dark(dark) {}
	
	int lv;
	int item_fire;
	int item_water;
	int item_light;
	int item_dark;
};

template<typename V, typename E>
class Tree
{
private:
	typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, V, E> Graph;
	typedef typename boost::graph_traits<Graph>::vertex_descriptor Vertex;
	typedef typename boost::graph_traits<Graph>::vertex_iterator vertex_iter;
	typedef typename boost::graph_traits<Graph>::adjacency_iterator adjacency_iter;

public:
	Tree();
	~Tree();

	void Init(std::vector<V>& a_vertex_property, const std::vector<E> a_edge_property, const std::vector<std::pair<int, int>>& a_edge);
	void Clear();
	void Print();

	std::vector<V> GetAdjacentDatas(const V& v);
	int FindVertex(const V& v);

	Graph* GetTree() { return tree; }

private:
	Graph* tree;
	int nVertex;
};


#include "Tree.inl"