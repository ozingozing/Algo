#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[9];
vector<int> graph[9];
queue<int> visit;

void BFS(int start)
{
    visit.push(start); //visit[1]
    visited[start] = true; // visited[1] = true;
    int current = 0;
    
    while (!visit.empty())
    {
        current = visit.front();
        visit.pop();                // visit[]
        cout << current << "나는 방문을 했다!" << endl;
        //                                graph[1] = {2, 5, 8}
        for (int nextNode = 0; nextNode < graph[current].size(); nextNode++)
        {
            int Next = graph[current][nextNode];
            if (!visited[Next])
            {
                visit.push(Next);
                visited[Next] = true;
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

    BFS(1);
    

    return 0;
}