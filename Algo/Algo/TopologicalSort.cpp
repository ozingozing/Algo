#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<vector<int> > adj;


vector<bool> visited;
vector<int> order;
void dfs(int here) {

	
	for (int next = 0; next < adj.size(); next++)
	{
		visited[here] = true;
		if (!visited[next] && adj[here][next])
		{
			dfs(next);
		}
	}
	order.push_back(here);
}


void topologicalSort() {
	int n = adj.size();
	visited = vector<bool>(N, false);
	order.clear();
	for (int i = 0; i < N; i++)
	{
		if (!visited[i]) dfs(i);
	}
	reverse(order.begin(), order.end());
}

void printOrder() {
	for (int i = 0; i < order.size(); i++)
		printf("%c ", order[i] + 'A');
	printf("\n");
}
int main() {
	printf("정점의 갯수 : ");
	cin >> N;

	printf("간선의 갯수 : ");
	cin >> M;

	visited = vector<bool>(N, false);
	adj = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < M; i++) {
		char from, to;
		printf("정점1 -> 정점2 : ");
		cin >> from >> to;
		adj[from - 'A'][to - 'A'] = 1;
	}

	topologicalSort();
	printOrder();
}