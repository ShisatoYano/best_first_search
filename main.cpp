#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<vector<pi>> graph;

// function for adding edges to graph
void add_edge(int x, int y, int cost)
{
    graph[x].push_back(make_pair(cost, y));
    graph[y].push_back(make_pair(cost, x));
}

// function for best first search
// gives output path having lowest cost
void best_first_search(int source, int target, int n)
{
    vector<bool> visited(n, false);

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push(make_pair(0, source));
    visited[0] = true;

    while (!pq.empty())
    {
        int x = pq.top().second;
        cout << x << " ";
        pq.pop();

        // goal
        if (x == target) break;

        for (int i = 0; i < graph[x].size(); ++i) {
            if (!visited[graph[x][i].second])
            {
                visited[graph[x][i].second] = true;
                pq.push(graph[x][i]);
            }
        }
    }
}

int main() {
    // number of nodes
    int v = 14;
    graph.resize(v);

    add_edge(0, 1, 3);
    add_edge(0, 2, 6);
    add_edge(0, 3, 5);
    add_edge(1, 4, 9);
    add_edge(1, 5, 8);
    add_edge(2, 6, 12);
    add_edge(2, 7, 14);
    add_edge(3, 8, 7);
    add_edge(8, 9, 5);
    add_edge(8, 10, 6);
    add_edge(9, 11, 1);
    add_edge(9, 12, 10);
    add_edge(9, 13, 2);

    int source = 0;
    int target = 9;

    best_first_search(source, target, v);

    return 0;
}
