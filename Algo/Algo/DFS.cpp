#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool visited[9];
vector<int> graph[9];
stack<int> visit;
void DFS(int start)
{
    visited[start] = true;
    cout << start << " 방문했어!" << endl;
    for (int i = 0; i < graph[start].size(); i++)
    {
        if (!visited[graph[start][i]]) DFS(graph[start][i]);
    }
}

void DFS2(int start)
{
    int Count = 0;
    int current = 0;
    visit.push(start); //visit[1]
    visited[start] = true;

    while (!visit.empty())
    {
        current = visit.top(); // visit[1]
        visit.pop(); //visit[]
        cout << current << "방문함!!" << endl;
        //                              //graph[1] {2, 3, 5}
        for (int nextNode = 0; nextNode < graph[current].size(); nextNode++)
        {
            int  next = graph[current][nextNode];
            if (!visited[next])
            {
                visit.push(next); //graph[1] {[2], 3, 5}
                visited[next] = true; // visited[2] = true;
            }
        }
    }
}


int main()
{
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);

    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);

    //DFS(1);
    //cout << "=======================" << endl;
    //for (int i = 0; i < visit.size(); i++) visit.pop();
    DFS2(1);

	return 0;
}