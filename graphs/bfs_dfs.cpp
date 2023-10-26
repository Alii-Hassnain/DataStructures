#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void DFS(int graph[][100], int visited[], int src, int dest, int V) {
    stack<int> s;
    s.push(src);
    visited[src] = 1;
    int flag = 0;

    while(!s.empty()) {
        int v = s.top();
        s.pop();
        if(v == dest) {
            cout << "Destination " << dest << " found from source " << src << " using DFS." << endl;
            flag = 1;
            break;
        }
        for(int i = 0; i < V; i++) {
            if(graph[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                s.push(i);
            }
        }
    }
    if(flag == 0)
        cout << "Destination " << dest << " not found from source " << src << " using DFS." << endl;
}

void BFS(int graph[][100], int visited[], int src, int dest, int V) {
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    int flag = 0;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        if(v == dest) {
            cout << "Destination " << dest << " found from source " << src << " using BFS." << endl;
            flag = 1;
            break;
        }
        for(int i = 0; i < V; i++) {
            if(graph[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    if(flag == 0)
        cout << "Destination " << dest << " not found from source " << src << " using BFS." << endl;
}

int main() {
    int V, src, dest;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    int graph[100][100];
    cout << "Enter the adjacency matrix of the graph:" << endl;
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int visited[V] = {0};
    cout << "Enter the source vertex: ";
    cin >> src;
    cout << "Enter the destination vertex: ";
    cin >> dest;

    DFS(graph, visited, src, dest, V);

    for(int i = 0; i < V; i++)
        visited[i] = 0;

    BFS(graph, visited, src, dest, V);

    return 0;
}
