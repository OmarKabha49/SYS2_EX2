// 315481721
// kabhao47@gmail.com
// Graph.cpp


#include "Graph.hpp"

using namespace ariel;
using namespace std;

// Constructor
Graph::Graph() : numVertices(0), numEdges(0) {}

// Load a graph from an adjacency matrix
void Graph::loadGraph(const vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix.size() != matrix[0].size()) {
        throw invalid_argument("Invalid graph: The graph is not a square matrix.");
    }
    numVertices = matrix.size();
    numEdges = 0;
    Matrix = matrix;
    adjList.resize(numVertices);  // Changed from reserve to resize for direct indexing

    for (size_t i = 0; i < numVertices; ++i) {
        adjList[i].clear();
        for (size_t j = 0; j < numVertices; ++j) {
            if (Matrix[i][j] > 0) {
                numEdges += 1;
                adjList[i].push_back(j);
            }
        }
    }
}

// Print the graph
void Graph::printGraph() const {
    cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges.\n";
}


// Get the adjacency matrix
const vector<vector<int>>& Graph::getMatrix() const {
    return Matrix;
}

// Get the number of vertices
int Graph::getNumVertices() const {
    return numVertices;
}

// Get the adjacency list
const vector<vector<int>>& Graph::getAdjList() const {
    return adjList;
}

// Arithmetic operators

// Addition operator
Graph Graph::operator+(const Graph& other) const {
    if (numVertices != other.numVertices) {
        throw invalid_argument("Cannot add graphs of different sizes.");
    }
    Graph result = *this;
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t j = 0; j < numVertices; ++j) {
            result.Matrix[i][j] += other.Matrix[i][j];
        }
    }
    result.loadGraph(result.Matrix);
    return result;
}

// Addition assignment operator
Graph& Graph::operator+=(const Graph& other) {
    *this = *this + other;
    return *this;
}

// Subtraction operator
Graph Graph::operator-(const Graph& other) const {
    if (numVertices != other.numVertices) {
        throw invalid_argument("Cannot subtract graphs of different sizes.");
    }
    Graph result = *this;
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t j = 0; j < numVertices; ++j) {
            result.Matrix[i][j] -= other.Matrix[i][j];
        }
    }
    result.loadGraph(result.Matrix);
    return result;
}

// Subtraction assignment operator
Graph& Graph::operator-=(const Graph& other) {
    *this = *this - other;
    return *this;
}

// Multiplication operator (element-wise)
Graph Graph::operator*(const Graph& other) const {
    if (numVertices != other.numVertices) {
        throw invalid_argument("Cannot multiply graphs of different sizes.");
    }
    vector<vector<int>> resultMatrix(numVertices, vector<int>(numVertices, 0));
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t j = 0; j < numVertices; ++j) {
            for (size_t k = 0; k < numVertices; ++k) {
                resultMatrix[i][j] += Matrix[i][k] * other.Matrix[k][j];
            }
        }
    }
    Graph result;
    result.loadGraph(resultMatrix);
    return result;
}

// Scalar multiplication assignment operator
Graph& Graph::operator*=(int scalar) {
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t j = 0; j < numVertices; ++j) {
            Matrix[i][j] *= scalar;
        }
    }
    loadGraph(Matrix);
    return *this;
}

// Scalar division assignment operator
Graph& Graph::operator/=(int scalar) {
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t j = 0; j < numVertices; ++j) {
            Matrix[i][j] /= scalar;
        }
    }
    loadGraph(Matrix);
    return *this;
}

// Scalar multiplication operator
Graph Graph::operator*(int scalar) const {
    Graph result = *this;
    result *= scalar;
    return result;
}

// Scalar division operator
Graph Graph::operator/(int scalar) const {
    Graph result = *this;
    result /= scalar;
    return result;
}

// Unary minus operator
Graph Graph::operator-() const {
    Graph result = *this;
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t j = 0; j < numVertices; ++j) {
            result.Matrix[i][j] = -result.Matrix[i][j];
        }
    }
    result.loadGraph(result.Matrix);
    return result;
}

// Comparison operators
bool Graph::operator==(const Graph& other) const {
    return numVertices == other.numVertices && Matrix == other.Matrix;
}

bool Graph::operator!=(const Graph& other) const {
    return !(*this == other);
}

bool Graph::operator<(const Graph& other) const {
    if (numVertices != other.numVertices) return false;
    return numEdges < other.numEdges;
}

bool Graph::operator<=(const Graph& other) const {
    return *this < other || *this == other;
}

bool Graph::operator>(const Graph& other) const {
    if (numVertices != other.numVertices) return false;
    return numEdges > other.numEdges;
}

bool Graph::operator>=(const Graph& other) const {
    return *this > other || *this == other;
}

// Increment/Decrement operators
Graph& Graph::operator++() {
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t j = 0; j < numVertices; ++j) {
            if (Matrix[i][j] > 0) {
                Matrix[i][j]++;
            }
        }
    }
    loadGraph(Matrix);
    return *this;
}

Graph Graph::operator++(int) {
    Graph temp = *this;
    ++(*this);
    return temp;
}

Graph& Graph::operator--() {
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t j = 0; j < numVertices; ++j) {
            if (Matrix[i][j] > 0) {
                Matrix[i][j]--;
            }
        }
    }
    loadGraph(Matrix);
    return *this;
}

Graph Graph::operator--(int) {
    Graph temp = *this;
    --(*this);
    return temp;
}

