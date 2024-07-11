#include <iostream>

#define MAX_NODES 1000

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct AdjList {
    Node* head;
};

AdjList graph[MAX_NODES];
bool visited[MAX_NODES];

void addEdge(int u, int v) {
    Node* newNode = new Node();
    newNode->data = v;
    newNode->next = graph[u].head;
    graph[u].head = newNode;

    newNode = new Node();
    newNode->data = u;
    newNode->next = graph[v].head;
    graph[v].head = newNode;
}

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    Node* temp = graph[node].head;
    while (temp != nullptr) {
        if (!visited[temp->data]) {
            dfs(temp->data);
        }
        temp = temp->next;
    }
}

void dfsTraversal(int start, int numNodes) {
    for (int i = 0; i < numNodes; ++i) {
        visited[i] = false;
    }

    cout << "DFS Traversal: ";
    dfs(start);
    cout << "\n";
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    int start;
    cin >> start;

    dfsTraversal(start, numNodes);

    return 0;
}
