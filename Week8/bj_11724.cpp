#include <iostream>
#include <vector>
using namespace std;

vector<int> vect[1001]; 
int visited[1001];      
int N, M;

void dfs(int vertex)
{
    visited[vertex] = 1;
    for (int i = 0; i < vect[vertex].size(); i++) 
    {
        int idx = vect[vertex][i];
        if (visited[idx] == 0)
        {
            dfs(idx);
        }
    }
}

int main()
{
    int u, v;
    int cnt = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        vect[u].push_back(v);
        vect[v].push_back(u); 
    }

    for (int i = 1; i <= N; i++) 
    {
        if (visited[i] == 0)
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << "\n";
}