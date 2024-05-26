// 315481721
// kabhao47@gmail.com
#include <vector>
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

using namespace ariel;


TEST_CASE("Test addition Operator") {
    Graph g1, g2, g3;

    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };

    vector<vector<int>> graph2 = {
        {1, 1},
        {1, 1}
    };

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    g3 = g1 + g2;

    CHECK(g3.getMatrix() == vector<vector<int>>{{1, 2}, {2, 1}});
}

TEST_CASE("Test addition assignment Operator") {
    Graph g1, g2;

    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };

    vector<vector<int>> graph2 = {
        {1, 1},
        {1, 1}
    };

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    g1 += g2;

    CHECK(g1.getMatrix() == vector<vector<int>>{{1, 2}, {2, 1}});
}

TEST_CASE("Test unary negation Operator") {
    Graph g1;

    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };

    g1.loadGraph(graph1);

    Graph g2 = -g1;

    CHECK(g2.getMatrix() == vector<vector<int>>{{0, -1}, {-1, 0}});
}

TEST_CASE("Test subtraction Operator") {
    Graph g1, g2;

    vector<vector<int>> graph1 = {
        {2, 3},
        {3, 2}
    };

    vector<vector<int>> graph2 = {
        {1, 1},
        {1, 1}
    };

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    Graph g3 = g1 - g2;

    CHECK(g3.getMatrix() == vector<vector<int>>{{1, 2}, {2, 1}});
}


TEST_CASE("Test subtraction assignment Operator") {
    Graph g1, g2;

    vector<vector<int>> graph1 = {
        {2, 3},
        {3, 2}
    };

    vector<vector<int>> graph2 = {
        {1, 1},
        {1, 1}
    };

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    g1 -= g2;

    CHECK(g1.getMatrix() == vector<vector<int>>{{1, 2}, {2, 1}});
}

TEST_CASE("Test equality Operator") {
    Graph g1, g2;

    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };

    vector<vector<int>> graph2 = {
        {0, 1},
        {1, 0}
    };

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    bool expected = g1 == g2;

    CHECK(expected);
}

TEST_CASE("Test inequality Operator") {
    Graph g1, g2;

    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };

    vector<vector<int>> graph2 = {
        {1, 0},
        {0, 1}
    };

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    bool expected = g1 != g2;

    CHECK(expected);
}

TEST_CASE("Test scalar multiplication Operator") {
    Graph g1;

    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };

    g1.loadGraph(graph1);

    Graph g2 = g1 * 2;

    CHECK(g2.getMatrix() == vector<vector<int>>{{0, 2}, {2, 0}});
}

TEST_CASE("Test graph multiplication Operator") {
    Graph g1, g2;

    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };

    vector<vector<int>> graph2 = {
        {1, 1},
        {1, 1}
    };

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    Graph g3 = g1 * g2;

    CHECK(g3.getMatrix() == vector<vector<int>>{{1, 1}, {1, 1}});
}

TEST_CASE("Test prefix increment Operator") {
    Graph g1;

    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };

    g1.loadGraph(graph1);

    ++g1;

    CHECK(g1.getMatrix() == vector<vector<int>>{{0, 2}, {2, 0}});
}

TEST_CASE("Test postfix increment Operator") {
    Graph g1;

    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };

    g1.loadGraph(graph1);

    Graph g2 = g1++;

    CHECK(g1.getMatrix() == vector<vector<int>>{{0, 2}, {2, 0}});
    CHECK(g2.getMatrix() == vector<vector<int>>{{0, 1}, {1, 0}});
}


TEST_CASE("Test prefix decrement Operator") {
    Graph g1;

    vector<vector<int>> graph1 = {
        {0, 2},
        {2, 0}
    };

    g1.loadGraph(graph1);

    --g1;

    CHECK(g1.getMatrix() == vector<vector<int>>{{0, 1}, {1, 0}});
}

TEST_CASE("Test postfix decrement Operator") {
    Graph g1;

    vector<vector<int>> graph1 = {
        {0, 2},
        {2, 0}
    };

    g1.loadGraph(graph1);

    Graph g2 = g1--;

    CHECK(g1.getMatrix() == vector<vector<int>>{{0, 1}, {1, 0}});
    CHECK(g2.getMatrix() == vector<vector<int>>{{0, 2}, {2, 0}});
}

TEST_CASE("Test greater than Operator") {
    Graph g1, g2;

    vector<vector<int>> graph1 = {
        {0, 1},
        {0, 0}
    };

    vector<vector<int>> graph2 = {
        {0, 1},
        {1, 0}
    };

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    bool expected = g2 > g1;

    CHECK(expected);
}

TEST_CASE("Test greater than or equal Operator") {
    Graph g1, g2, g3;

    vector<vector<int>> graph1 = {
        {0, 1},
        {0, 0}
    };

    vector<vector<int>> graph2 = {
        {0, 1},
        {1, 0}
    };

    vector<vector<int>> graph3 = {
        {0, 1},
        {1, 0}
    };

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    g3.loadGraph(graph3);
    
    bool expected1 = g2 >= g1;
    bool expected2 = g2 >= g3;

    CHECK(expected1);
    CHECK(expected2);
}

TEST_CASE("Test less than Operator") {
    Graph g1, g2;

    vector<vector<int>> graph1 = {
        {0, 1},
        {0, 0}
    };

    vector<vector<int>> graph2 = {
        {0, 1},
        {1, 0}
    };

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    
    bool expected = g1 < g2;

    CHECK(expected);
}

TEST_CASE("Test less than or equal Operator") {
    Graph g1, g2, g3;

    vector<vector<int>> graph1 = {
        {0, 1},
        {0, 0}
    };

    vector<vector<int>> graph2 = {
        {0, 1},
        {1, 0}
    };

    vector<vector<int>> graph3 = {
        {0, 1},
        {1, 0}
    };

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    g3.loadGraph(graph3);
    
    bool expected1 = g1 <= g2;
    bool expected2 = g2 <= g3;

    CHECK(expected1);
    CHECK(expected2);
}
