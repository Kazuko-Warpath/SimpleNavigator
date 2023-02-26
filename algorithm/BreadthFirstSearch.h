#ifndef S21_GRAPH_ALGORITHMS_H
# define S21_GRAPH_ALGORITHMS_H

#include <iostream>
#include <queue>
#include <stack>
#include "Graph.h"

class GraphAlgorithms {
	public:
		GraphAlgorithms() {};
		//GraphAlgorithms(const GraphAlgorithms &obj) {};
		virtual	~GraphAlgorithms() {};

		//поиск в ширину в графе от заданной вершины
		std::vector<int> breadthFirstSearch(Graph &graph, int startVertex) {
			Vertex* v = graph.getVertex(startVertex);
			v->used = 1;
			std::vector<int> route;
			route.push_back(v->key + 1);
			std::queue<Vertex *> queue;
			queue.push(v);
			while (!queue.empty()) {
				Vertex *to = queue.front();
				for (Edge edge : to->edges){
					if (!edge.pVrtx->used) {
						edge.pVrtx->used = 1;
						route.push_back(edge.pVrtx->key + 1);
						queue.push(edge.pVrtx);
					}
				}
				queue.pop();
			}
			return route;
		}

		ListPtrVertex dfs(Graph &graph, int startVertex){
			Vertex* v = graph.getVertex(startVertex);

			if (v) return _dfs(v);
			return ListPtrVertex();
		}

		std::list<Vertex *> _dfs(Vertex *v) {
			std::list<Vertex *> list;
			v->used = true;
			list.push_back(v);

			for(Edge edge : v->edges) {
				if (!edge.pVrtx->used) {
					std::list<Vertex *> tmp = _dfs(edge.pVrtx);	
					for (std::list<Vertex *>::iterator it = tmp.begin(); it != tmp.end(); it++){
						list.push_back(*it);
					}			
				}
			}
			return list;
		}
};

#endif