# Graph Library

## Author Information

- **Name**: Omar Kabha
- **Email**: kabhao47@gmail.com
- **ID**: 315481721

## Overview

This project implements a `Graph` class in C++, which allows for the representation of graphs using adjacency matrices. The class includes a variety of graph algorithms and supports various operators for graph manipulation and comparison. Additionally, the project includes a suite of tests to verify the correctness of the implemented features.

## Files

- **Graph.hpp**: Header file containing the declaration of the `Graph` class and its member functions.
- **Graph.cpp**: Implementation file containing the definitions of the member functions of the `Graph` class.
- **tests.cpp**: Test file containing unit tests for the `Graph` class using the `doctest` framework.

## Class: `Graph`

### Private Members

- `vector<vector<int>> Matrix`: The adjacency matrix representation of the graph.
- `vector<vector<int>> adjList`: The adjacency list representation of the graph.
- `int numVertices`: The number of vertices in the graph.
- `int numEdges`: The number of edges in the graph.

### Public Members

#### Constructor

- `Graph()`: Default constructor.

#### Graph Manipulation Functions

- `void loadGraph(const vector<vector<int>>& matrix)`: Loads a graph from an adjacency matrix.
- `void printGraph() const`: Prints the graph in the format `[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]`.
- `const vector<vector<int>>& getMatrix() const`: Returns the adjacency matrix.
- `const vector<vector<int>>& getAdjList() const`: Returns the adjacency list.
- `int getNumVertices() const`: Returns the number of vertices.

#### Arithmetic Operators

- `Graph operator+(const Graph& other) const`: Adds two graphs.
- `Graph& operator+=(const Graph& other)`: Adds another graph to this graph.
- `Graph operator-(const Graph& other) const`: Subtracts another graph from this graph.
- `Graph& operator-=(const Graph& other)`: Subtracts another graph from this graph.
- `Graph operator*(const Graph& other) const`: Multiplies two graphs element-wise.
- `Graph& operator*=(int scalar)`: Multiplies the graph by a scalar.
- `Graph& operator/=(int scalar)`: Divides the graph by a scalar.
- `Graph operator*(int scalar) const`: Returns a graph multiplied by a scalar.
- `Graph operator/(int scalar) const`: Returns a graph divided by a scalar.
- `Graph operator-() const`: Returns the negation of the graph.

#### Comparison Operators

- `bool operator==(const Graph& other) const`: Checks if two graphs are equal.
- `bool operator!=(const Graph& other) const`: Checks if two graphs are not equal.
- `bool operator<(const Graph& other) const`: Checks if this graph is less than another graph.
- `bool operator<=(const Graph& other) const`: Checks if this graph is less than or equal to another graph.
- `bool operator>(const Graph& other) const`: Checks if this graph is greater than another graph.
- `bool operator>=(const Graph& other) const`: Checks if this graph is greater than or equal to another graph.

#### Increment/Decrement Operators

- `Graph& operator++()`: Prefix increment.
- `Graph operator++(int)`: Postfix increment.
- `Graph& operator--()`: Prefix decrement.
- `Graph operator--(int)`: Postfix decrement.

#### Output Operator

- `friend ostream& operator<<(ostream& os, const Graph& graph)`: Outputs the graph in the format `[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]`.
