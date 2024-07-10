#include <iostream>
#include <vector>
#include <queue>

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
int distance[MAX_NODES];

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

void bfs(int start) {
    fill(begin(visited), end(visited), false);
    fill(begin(distance), end(distance), -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        Node* temp = graph[curr].head;
        while (temp != nullptr) {
            if (!visited[temp->data]) {
                q.push(temp->data);
                visited[temp->data] = true;
                distance[temp->data] = distance[curr] + 1;
            }
            temp = temp->next;
        }
    }
}

void printShortestReach(int start, int numNodes) {
    cout << "Shortest reach from node " << start << ":\n";
    for (int i = 0; i < numNodes; ++i) {
        if (i != start) {
            cout << "Node " << i << ": " << distance[i] << "\n";
        }
    }
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

    bfs(start);
    printShortestReach(start, numNodes);

    return 0;
}
