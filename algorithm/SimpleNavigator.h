#ifndef _SIMPLE_NAVIGATOR_H
#define _SIMPLE_NAVIGATOR_H

#include "Graph.h"
#include "BreadthFirstSearch.h"

bool	printEmptyFun(void) {
	std::cout << "Function in development)" << std::endl;
	return false;
}


class SimpleNavigator {
private:
	GraphAlgorithms algorithms;
    Graph graph;

	void printLogo(void);
	void printMenuAlgo(void);

	bool printDFS(void) {return printEmptyFun(); }; //in development

	bool printBFS(void)  {
			int num;
			std::cout << "Enter start vertex: \n => ";
			std::cin >> num;
			std::vector<int> routs = algorithms.breadthFirstSearch(graph, num - 1);
			for (size_t i = 0; i < routs.size(); i++)
				std::cout << routs[i] << " ";
			std::cout << std::endl;
			return true;
	};

	//from this line to 32 in development
	bool printSPBV(void)  {return printEmptyFun(); };
	bool printSPBAV(void)  {return printEmptyFun(); };
	bool printLST(void)  {return printEmptyFun(); };
	bool printSTSP(void)  {return printEmptyFun(); };
	bool printSTSPv1(void)  {return printEmptyFun(); };
	bool printSTSPv2(void)  {return printEmptyFun(); };

	void printError(void)  {std::cout << "ERROR" << std::endl; };
	void Fun21(void);
	
public:
    SimpleNavigator(std::string filename) {
		graph.loadGraphFromFile(filename); // in process
		graph.initGraph();
	}
    ~SimpleNavigator() {};

	void StartMenu(void) {
		printLogo();
		printMenuAlgo();
		
		bool(SimpleNavigator::*getPrint[])(void) = {
			&SimpleNavigator::printDFS,
			&SimpleNavigator::printBFS,
			&SimpleNavigator::printSPBV,
			&SimpleNavigator::printSPBAV,
			&SimpleNavigator::printLST,
			&SimpleNavigator::printSTSP,
			&SimpleNavigator::printSTSPv1,
			&SimpleNavigator::printSTSPv2
		};
		int choseAlgo;

		std::cout << "\nChose how to algo which the Graph:\n => ";
		std::cin >> choseAlgo;

		if (choseAlgo == 21) Fun21();
		if (choseAlgo >= 8) return;
		if (choseAlgo < 0) return printError();

		(this->*getPrint[choseAlgo])();
	}
};

void SimpleNavigator::printLogo(void) {
std::cout	<< "\n  _____  _                 _       _   _               _             _"
			<< "\n /  ___|(_)               | |     | \\ | |             (_)           | |"
			<< "\n \\ `--.  _ _ __ ___  _ __ | | ___ |  \\| | __ _ __   __ _  __ _  __ _| |_  ___  _ __"
			<< "\n  `--. \\| | '_ ` _ \\| '_ \\| |/ _ \\| . ` |/ _` |\\ \\ / /| |/ _` |/ _` | __|/ _ \\| '__|"
			<< "\n /\\__/ /| | | | | | | |_) | |  __/| |\\  | (_| | \\ V / | | (_| | (_| | |_| (_) | |"
			<< "\n \\____/ |_|_| |_| |_| .__/|_|\\___||_| \\_|\\__,_|  \\_/  |_|\\__, |\\__,_|\\__|\\___/|_|"
			<< "\n                    | |                                   __/ |"
			<< "\n                    |_|                                  |___/"
			<< std::endl;
}

void SimpleNavigator::printMenuAlgo() {
		std::cout 
		<< "|==================================================================|\n"
		<< "|=====================| Algorithms with Graph |====================|\n"
		<< "|==================================================================|\n"
		<< "|0| graph traversal in depth                                       |\n"
		<< "|==================================================================|\n"
		<< "|1| graph traversal in breadth                                     |\n"
		<< "|==================================================================|\n"
		<< "|2| finding the shortest path between two vertices                 |\n"
		<< "|==================================================================|\n"
		<< "|3| searching for the shortest paths between all pairs of vertices |\n"
		<< "|==================================================================|\n"
		<< "|4| searching for the minimal spanning tree                        |\n"
		<< "|==================================================================|\n"
		<< "|5| solving the salesman problem                                   |\n"
		<< "|==================================================================|\n"
		<< "|6| solving the salesman problem v1                                |\n"
		<< "|==================================================================|\n"
		<< "|7| solving the salesman problem v2                                |\n"
		<< "|==================================================================|\n"
		<< "|8| Exit                                                           |\n" 
		<< "|==================================================================|\n"
		<< std::endl;
}

void SimpleNavigator::Fun21() {
	std::cout << "Project worked : \n ltacos \n echrysta \n kwarpath" << std::endl;
}

#endif