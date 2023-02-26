#include <iostream>
#include <vector>

#include "Graph.h"
#include "BreadthFirstSearch.h"

int main()
{
	int num = 1;
	while(std::cout << "num: " &&  std::cin >> num){
		if (!num) break;
		{ //Реализовать глубокое копирование для класса граф
			Graph g;
			GraphAlgorithms ga;
			g.initGraph();
			
			std::vector<int> routs = ga.breadthFirstSearch(g, num - 1);
			for (size_t i = 0; i < routs.size(); i++)
				std::cout << routs[i] << std::endl;
		}		
	}
}