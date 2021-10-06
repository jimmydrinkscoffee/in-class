#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

//  Connectivity

bool IsConnected(int **&graph, int &n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; ++i)
        visited[i] = false;
    queue<int> heap;
    heap.push(0);
    while (!heap.empty())
    {
        int u = heap.front();
        heap.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (int v = 0; v < n; ++v)
            if (graph[u][v] > 0)
                heap.push(v);
    }
    for (int i = 0; i < n; ++i)
        if (!visited[i])
        {
            delete[] visited;
            return false;
        }
    delete[] visited;
    return true;
}

//  Print all Connected Sub-graphs

void Traversal(int **&graph, bool *&visited, int &n, int index)
{
    cout << index + 1 << " ";
    for (int v = 0; v < n; ++v)
        if (graph[index][v] > 0 && !visited[v])
        {
            visited[v] = true;
            Traversal(graph, visited, n, v);
        }
}

void PrintAllCSG(int **&graph, int &n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; ++i)
        visited[i] = false;
    for (int i = 0; i < n; ++i)
        if (!visited[i])
        {
            visited[i] = true;
            Traversal(graph, visited, n, i);
            cout << endl;
        }
    delete[] visited;
}

//  Shortest Path

int *DijkstraSP(int **&graph, int &n, int index)
{
    bool *visited = new bool[n];
    int *distance = new int[n];
    int *parent = new int[n];
    for (int i = 0; i < n; ++i)
    {
        visited[i] = false;
        distance[i] = INT32_MAX;
        parent[i] = -1;
    }
    distance[index] = 0;
    queue<int> heap;
    heap.push(index);
    while (!heap.empty())
    {
        int u = heap.front();
        heap.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (int v = 0; v < n; ++v)
        {
            int weight = graph[u][v];
            if (weight < 0)
                continue;
            if (!visited[weight] && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                heap.push(v);
            }
        }
    }
    delete[] visited;
    delete[] parent;
    return distance;
}

//  Minimum Spanning Tree

int *PrimMST(int **&graph, int &n, int index)
{
    bool *visited = new bool[n];
    int *distance = new int[n];
    int *parent = new int[n];
    for (int i = 0; i < n; ++i)
    {
        visited[i] = false;
        distance[i] = INT32_MAX;
        parent[i] = -1;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push(make_pair(0, index));
    while (!heap.empty())
    {
        int u = heap.top().second;
        heap.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (int v = 0; v < n; ++v)
        {
            int weight = graph[u][v];
            if (weight < 0)
                continue;
            if (!visited[v] && weight < distance[v])
            {
                distance[v] = weight;
                parent[v] = u;
                heap.push(make_pair(weight, v));
            }
        }
    }
    delete[] visited;
    delete[] distance;
    return parent;
}

int main()
{
    int n, **graph;
    ifstream fin("Graph.txt");
    if (fin.is_open())
    {
        fin >> n;
        graph = new int *[n];
        for (int i = 0; i < n; ++i)
        {
            graph[i] = new int[n];
            for (int j = 0; j < n; ++j)
                fin >> graph[i][j];
        }
    }
    fin.close();

    cout << IsConnected(graph, n) << endl;

    PrintAllCSG(graph, n);

    int *distance = DijkstraSP(graph, n, 0);
    for (int i = 0; i < n; ++i)
        cout << i << " - " << distance[i] << endl;
    delete[] distance;

    int *parent = PrimMST(graph, n, 0);
    for (int i = 0; i < n; ++i)
        cout << i << " - " << parent[i] << endl;
    delete[] parent;

    for (int i = 0; i < n; ++i)
        delete[] graph[i];
    delete[] graph;
    return 0;
}