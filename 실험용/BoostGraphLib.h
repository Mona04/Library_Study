#pragma once
#include <../../boost/graph/graph_traits.hpp>
#include <../../boost/graph/adjacency_list.hpp>
#include <../../boost/graph/dijkstra_shortest_paths.hpp>

void User_Example();

struct MonsterType
{
	MonsterType() : name("monster"), code(-1) {}
	MonsterType(const std::string& name, const int& code) : name(name), code(code) {}
	std::string name;
	int code;
};

struct Evolution_Condition
{
	Evolution_Condition() : lv(-1), item(-1) {}
	Evolution_Condition(const int& lv, const int& item) : lv(lv), item(item) {}
	int lv;
	int item;
};

template <class Graph>
struct print_outedge {
	typedef typename boost::graph_traits<Graph>::vertex_descriptor Vertex;
	print_outedge(Graph& g_) : g(g_) {}
	void operator()(const Vertex& v) const
	{
		std::cout << "out-edges: " << v << " ";
		typename boost::graph_traits<Graph>::out_edge_iterator out_i, out_end;
		for (boost::tie(out_i, out_end) = boost::out_edges(v, g); out_i != out_end; ++out_i)
		{
			Vertex src = boost::source(*out_i, g), targ = boost::target(*out_i, g);
			std::cout << "(" << src << "," << targ << ") ";
		}
		std::cout << std::endl;
	}
	Graph& g;
};

template <class Graph>
struct print_inedge {
	typedef typename boost::graph_traits<Graph>::vertex_descriptor Vertex;
	print_inedge(Graph& g_) : g(g_) {}
	void operator()(const Vertex& v) const
	{
		std::cout << "in-edges: " << v << " ";
		typename boost::graph_traits<Graph>::in_edge_iterator in_i, in_end;
		for (boost::tie(in_i, in_end) = boost::in_edges(v, g); in_i != in_end; ++in_i)
		{
			Vertex src = boost::source(*in_i, g), targ = boost::target(*in_i, g);
			std::cout << "(" << src << "," << targ << ") ";
		}
		std::cout << std::endl;

	}
	Graph& g;
};


template <class Graph>
struct print_adjacency {
	typedef typename boost::graph_traits<Graph>::vertex_descriptor Vertex;
	print_adjacency(Graph& g_) : g(g_) {}
	void operator()(const Vertex& v) const
	{
		std::cout << "adjacent vertices: ";
		typename boost::graph_traits<Graph>::adjacency_iterator ai, ai_end;
		for (boost::tie(ai, ai_end) = boost::adjacent_vertices(v, g); ai != ai_end; ++ai)
			std::cout << *ai << " ";
		std::cout << std::endl;
	}
	//...
	Graph& g;
};