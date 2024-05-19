// 315481721
// kabhao47@gmail.com

// Graph.hpp

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace ariel {

    class Graph {

    private:
        vector<vector<int>> Matrix; // Adjacency matrix
        vector<vector<int>> adjList; // Adjacency list
        int numVertices; // Number of vertices
        int numEdges; // Number of edges

    public:
        // Constructor
        Graph();

        // Load a graph from an adjacency matrix
        void loadGraph(const vector<vector<int>>& matrix);

        // Print the graph
        void printGraph() const;

        // Get the adjacency list
        const vector<vector<int>>& getAdjList() const;

        // Get the adjacency matrix
        const vector<vector<int>> &getMatrix() const;

        // Get the number of vertices
        int getNumVertices() const;

        // Arithmetic operators
        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);
        Graph operator-() const;
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);

        // Comparison operators
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;

        // Increment/Decrement operators
        Graph& operator++(); // Prefix increment
        Graph operator++(int); // Postfix increment
        Graph& operator--(); // Prefix decrement
        Graph operator--(int); // Postfix decrement

        // Scalar multiplication
        Graph operator*(int scalar) const;

        // Graph multiplication
        Graph operator*(const Graph& other) const;

        // Output operator
        friend ostream& operator<<(ostream& os, const Graph& graph);
    };

}  // namespace ariel

#endif
