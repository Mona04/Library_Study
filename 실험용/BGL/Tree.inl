#include "Tree.h"

template<typename V, typename E>
inline Tree<V, E>::Tree()
	: tree(nullptr)
{
}

template<typename V, typename E>
inline Tree<V, E>::~Tree()
{
	Clear();
	SAFE_DELETE(tree);
}

template<typename V, typename E>
inline void Tree<V, E>::Init(std::vector<V>& a_vertex_property, const std::vector<E> a_edge_property, const std::vector<std::pair<int, int>>& a_edge)
{
	tree = new Graph(a_edge.begin()._Ptr, a_edge.end()._Ptr, a_edge_property.begin()._Ptr, a_vertex_property.size());
	for (int i = 0; i < a_vertex_property.size(); i++)
		(*tree)[i] = a_vertex_property[i];
}

template<typename V, typename E>
inline void Tree<V, E>::Clear()
{
	if(tree) tree->clear();
}

template<typename V, typename E>
inline void Tree<V, E>::Print()
{
	if (!tree || tree->m_vertices.size() <= 0) return;

	std::stack<std::pair<Vertex, int>> _stack; 
	std::pair<Vertex, int> _before, _cur = std::make_pair(0, 0);
	_before = std::make_pair( 0, -1 );
	_stack.push(_cur);
	
	adjacency_iter ai, ai_end;
	while (_stack.size() > 0)
	{
		_before = _cur;
		_cur = _stack.top(); _stack.pop();
		if (_before.second >= _cur.second)
		{
			std::cout << std::endl;
			for (int i = 0; i < _cur.second; i++)
				std::cout << " ";
		}
		std::cout << " --- " << (*tree)[_cur.first].name;


		for (boost::tie(ai, ai_end) = boost::adjacent_vertices(_cur.first, *tree); ai != ai_end;)
		{
			ai_end--;
			auto a = _cur.second + (*tree)[_before.first].name.size();
			_stack.push(std::make_pair(*ai_end, _cur.second + (*tree)[_cur.first].name.size() + 5));
		}
	}
	std::cout << std::endl;
}

template<typename V, typename E>
inline std::vector<void*> Tree<V, E>::GetAdjacentDatas(const Vertex& v)
{
	adjacency_iter ai, ai_end;
	std::vector<void*> result;
	for (boost::tie(ai, ai_end) = boost::adjacent_vertices(v, *tree); ai != ai_end; ai++)
	{
		result.emplace_back((*tree)[*ai].data);
	}
	return result;
}