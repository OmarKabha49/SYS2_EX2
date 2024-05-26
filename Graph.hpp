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
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph operator*(const Graph& other) const;
        Graph& operator*=(int scalar);
        Graph& operator/=(int scalar);
        Graph operator*(int scalar) const;
        Graph operator/(int scalar) const;
        Graph operator-() const;

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

        // Output operator
        friend ostream& operator<<(ostream& os, const Graph& graph){
            for (const auto& row : graph.Matrix) {
                os << "[";
                for (size_t j = 0; j < row.size(); ++j) {
                    os << row[j];
                    if (j < row.size() - 1) {
                        os << ", ";
                    }
                }
            os << "]\n";
            }
            return os<<"\n";
        }
    };

}  // namespace ariel

#endif
