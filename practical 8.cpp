#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[5];
bool visited[5];

// DFS
void DFS(int node)
{
    visited[node] = true;
    cout << node << " ";

    for (int x : graph[node])
        if (!visited[x])
            DFS(x);
}

// BFS
void BFS(int start)
{
    bool visit[5] = {false};
    queue<int> q;

    q.push(start);
    visit[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int x : graph[node])
        {
            if (!visit[x])
            {
                visit[x] = true;
                q.push(x);
            }
        }
    }
}

int main()
{
    // Graph edges
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);

    cout << "DFS: ";
    DFS(0);

    cout << "\nBFS: ";
    BFS(0);

    return 0;
}
