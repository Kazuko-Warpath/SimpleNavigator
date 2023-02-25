#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
#include <list>

struct Vertex;

struct Edge {
	Vertex	*pVrtx;	// ptr to vertex
	int		weight;	// weight this Edges
};

typedef std::list<Edge> ListEdge;

struct Vertex {
	int			key;	   // number vertex
	bool		used;	   // status visit
	int			sizeEdges; // number edges this vertex
	ListEdge	edges;

	Vertex(int num) :
		key(num),
		used(false),
		sizeEdges(0) {}
};

typedef std::list<Vertex *> ListPtrVertex;

class Graph {
public:
	Graph() :
		_sizeVertexes(0),
		_isDirectedGraph(false) {};

	~Graph() {
		for (ListPtrVertex::iterator it = _vertexes.begin(); it != _vertexes.end(); it++)
			delete *it;		
	};

	void loadGraphFromFile(std::string filename) {};

private:
	ListPtrVertex	_vertexes;			//список вершин с ребрами
	int				_sizeVertexes;		//кол-во вершин
	bool			_isDirectedGraph;	//граф орентированный true иначе false

	//========================================================//
	//=======================METODS===========================//
	//========================================================//
 
	void	addVertex(int key) {
		_vertexes.push_back(new Vertex(key));
		_sizeVertexes++;
	}

	void	addEdges(int v1, int v2, int weight) {
		//сделать проверку на существование элементов

		Vertex* pV1 = getVertex(v1);
		Vertex* pV2 = getVertex(v2);
		Edge edge;

		edge.pVrtx = pV2;
		edge.weight = weight;
		pV1->edges.push_back(edge);
		pV1->sizeEdges++;
	}
	
	Vertex*	getVertex(const int n) {
		//сделать проверку на существование элементов
		ListPtrVertex::iterator it = _vertexes.begin();
		std::advance(it, n);
		return *it;
	}

};

#endif