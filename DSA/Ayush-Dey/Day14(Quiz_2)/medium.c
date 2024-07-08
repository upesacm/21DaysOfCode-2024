// Stable Sorting Challenge

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

// Graph structure
typedef struct
{
    ListNode *adj[MAXN];
    int indegree[MAXN];
    int n;
} Graph;

Graph *createGraph(int n)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->n = n;
    for (int i = 0; i < n; ++i)
    {
        graph->adj[i] = NULL;
        graph->indegree[i] = 0;
    }
    return graph;
}

void addEdge(Graph *graph, int u, int v)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = v;
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
    graph->indegree[v]++;
}

typedef struct
{
    int *heap;
    int size;
    int capacity;
} MinHeap;

MinHeap *createMinHeap(int capacity)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->heap = (int *)malloc((capacity + 1) * sizeof(int)); // +1 for 1-based indexing
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx;
    int right = 2 * idx + 1;

    if (left <= minHeap->size && minHeap->heap[left] < minHeap->heap[smallest])
    {
        smallest = left;
    }
    if (right <= minHeap->size && minHeap->heap[right] < minHeap->heap[smallest])
    {
        smallest = right;
    }

    if (smallest != idx)
    {
        swap(&minHeap->heap[idx], &minHeap->heap[smallest]);
        heapify(minHeap, smallest);
    }
}

// min. ele
int extractMin(MinHeap *minHeap)
{
    if (minHeap->size == 0)
        return -1; // no elements

    int minElement = minHeap->heap[1];
    minHeap->heap[1] = minHeap->heap[minHeap->size--];
    heapify(minHeap, 1);

    return minElement;
}

void insert(MinHeap *minHeap, int element)
{
    if (minHeap->size >= minHeap->capacity)
        return; // heap full

    minHeap->heap[++minHeap->size] = element;
    int i = minHeap->size;

    while (i > 1 && minHeap->heap[i] < minHeap->heap[i / 2])
    {
        swap(&minHeap->heap[i], &minHeap->heap[i / 2]);
        i /= 2;
    }
}

// topo_Kahn's algo_min-heap
int *topologicalSort(int n, int m, int data[][2])
{

    Graph *graph = createGraph(n);

    // Build adjacency list and indegree
    for (int i = 0; i < m; ++i)
    {
        int horse_a = data[i][0];
        int horse_b = data[i][1];
        addEdge(graph, horse_b, horse_a);
    }

    MinHeap *minHeap = createMinHeap(n);
    int *result = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
    {
        if (graph->indegree[i] == 0)
        {
            insert(minHeap, i);
        }
    }

    int index = 0;

    // topo sort
    while (minHeap->size > 0)
    {
        int horse = extractMin(minHeap);
        result[index++] = horse;

        // Decrease indegree of all neighbors
        ListNode *current = graph->adj[horse];
        while (current != NULL)
        {
            int neighbor = current->val;
            graph->indegree[neighbor]--;
            if (graph->indegree[neighbor] == 0)
            {
                insert(minHeap, neighbor);
            }
            current = current->next;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        ListNode *current = graph->adj[i];
        while (current != NULL)
        {
            ListNode *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph);
    free(minHeap->heap);
    free(minHeap);

    // chking for cycle
    if (index != n)
    {
        free(result);
        return NULL;
    }

    return result;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int data[m][2];
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d", &data[i][0], &data[i][1]);
    }

    // topo sort
    int *sorted = topologicalSort(n, m, data);

    if (sorted == NULL)
    {
        printf("-1\n");
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", sorted[i]);
        }
        printf("\n");
        free(sorted);
    }
    return 0;
}