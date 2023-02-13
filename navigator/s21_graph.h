#pragma once

#include <fstream>
#include <iostream>

#include "s21_matrix_oop.h" // расписать 

class Graph {
 public:
  Graph(){
    matrix_ = nullptr;
    isDirectedGraph_ = false;
    isWeightedGraph_ = false;
    size_ = 0;
  }
  Graph(const Graph& other){
    *this = other;
  }
  Graph(Graph&& other){
    *this = std::move(other);
  }
  ~Graph(){
    if (matrix_ != nullptr) {
    delete matrix_;
    matrix_ = nullptr;
    }
  }

  Graph& operator=(const Graph& other){
    if (this != &other) {
    size_ = other.size_;
    isWeightedGraph_ = other.isWeightedGraph_;
    isDirectedGraph_ = other.isDirectedGraph_;
    matrix_ = other.matrix_;
    }
    return *this;
  }
  Graph& operator=(Graph&& other){
    if (this != &other) {
    size_ = 0;
    isWeightedGraph_ = false;
    isDirectedGraph_ = false;
    std::swap(size_, other.size_);
    std::swap(isWeightedGraph_, other.isWeightedGraph_);
    std::swap(isDirectedGraph_, other.isDirectedGraph_);
    matrix_ = std::move(other.matrix_);
    }
    return *this;
  }
  double& operator()(int row, int column) {
    return matrix_->operator()(row, column);
  }

  void loadGraphFromFile(const std::string& filename);
  void exportGraphToDot(const std::string& filename);
  int getSize() { return size_; }
  S21Matrix<double>* getMatrix() { return matrix_; }

 private:
  S21Matrix<double>* matrix_;
  int size_;
  bool isWeightedGraph_;  //  Взвешенный граф
  bool isDirectedGraph_;  //  Ориентированный граф
};
