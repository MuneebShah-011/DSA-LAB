#include<iostream>
#include<list>
#include<queue>
using namespace std;

const int V = 6;
list<int> adj[V];
bool visited[V];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // for undirected graph
}

void bfs(int start) {
    for(int i=0; i<V; i++) visited[i] = false;

    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        list<int>::iterator it;
        for(it = adj[node].begin(); it != adj[node].end(); ++it) {
            if(!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
    cout << endl;
}

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    list<int>::iterator it;
    for(it = adj[node].begin(); it != adj[node].end(); ++it) {
        if(!visited[*it]) dfs(*it);
    }
}

int main() {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);

    bfs(0);

    for(int i=0; i<V; i++) visited[i] = false;

    cout << "DFS: ";
    dfs(0);
    cout << endl;

    return 0;
}

