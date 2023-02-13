#include "s21_graph.h"

void Graph::loadGraphFromFile(const std::string& filename) {
  std::ifstream fs(filename);
  if (!fs.is_open()) {
    throw std::runtime_error("Can`t open file");
  }

  if (fs.eof() == true) {
    throw std::runtime_error("Empty file");
  }

  int fileSize = 0;
  fs >> fileSize;

  if (fs.fail() == true) {
    throw std::runtime_error("Bad data on file");
  }

  size_ = fileSize;
  matrix_ = new S21Matrix<double>(fileSize, fileSize);

  for (int i = 0; i < size_; i++) {
    for (int j = 0; j < size_; j++) {
      fs >> matrix_->operator()(i, j);
      if (fs.fail() == true) {
        throw std::runtime_error("Bad data on file");
      }
    }
  }

  fs.close();
  for (int i = 0; i < size_; i++) {
    for (int j = 0; j < size_; j++) {
      if (!isWeightedGraph_ && matrix_->operator()(i, j) > 1) {
        isWeightedGraph_ = true;
      }
      if (!isDirectedGraph_ &&
          matrix_->operator()(i, j) != matrix_->operator()(j, i)) {
        isDirectedGraph_ = true;
      }
    }
  }
}

void Graph::exportGraphToDot(const std::string& filename) {
  std::ofstream outfile(filename + ".dot");
  if (!outfile.is_open()) {
    throw std::runtime_error("Can`t write file");
  }

  std::string dotSeparator;
  std::string dotGraphType;

  if (isDirectedGraph_) {
    dotSeparator = " -> ";
    dotGraphType = "digraph ";
  } else {
    dotSeparator = " -- ";
    dotGraphType = "graph ";
  }

  outfile << dotGraphType << "graphname"
          << " {" << std::endl;

  for (int i = 0; i < size_; i++) {
    int node = i + 1;
    outfile << node << ";" << std::endl;
  }

  for (int i = 0; i < size_; i++) {
    for (int j = 0; j < size_; j++) {
      if (matrix_->operator()(i, j) > 0) {
        int firstNode = i + 1;
        int secondNode = j + 1;

        if (matrix_->operator()(i, j) == 1) {
          outfile << firstNode << dotSeparator << secondNode << ";"
                  << std::endl;
        } else {
          outfile << firstNode << dotSeparator << secondNode
                  << " [label=" << matrix_->operator()(i, j) << "];"
                  << std::endl;
        }
      }
    }
  }

  outfile << "}";
  outfile.close();
}
