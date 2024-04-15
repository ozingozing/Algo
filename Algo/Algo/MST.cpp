#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//parent[1] = 1 이면 1번 노드가 1번 노드에 연결 됐다는 뜻
//parent[1] = 2 이면 1번 노드가 2번 노드에 연결 됐다는 거
int parent[5];

class Edge
{
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	//오름차순 정렬 기준 
	bool operator<(Edge& edge) {
		return this->distance < edge.distance;
	}
};

//부모 탐색
int FindParent(int node)
{
	if (parent[node] == node) return node;
	return FindParent(parent[node]);
}

//두 노드를 작은 값을 기준으로 연결
//node값이 큰 갑에서 작은 값으로 연결
//v1 과 v3가 연결 됐다고 하면 parent[3] = 1 이런 식으로 연결
void UnionParent(int node1, int node2)
{
	node1 = FindParent(node1); //3 // 2 => 2 // 1
	node2 = FindParent(node2); //4 // 4 => 3 // 3 => 2
	if (node1 < node2) parent[node2] = node1;//parent[4] = 3 // parent[3] = 2 // parent[1] = 2
	else parent[node1] = node2;
}

bool IsCycle(int node1, int node2)
{
	node1 = FindParent(node1); //2 
	node2 = FindParent(node2); //4 => 3
	if (node1 == node2) return true;
	else return false;
}

int main()
{
	//최소신장 트리가 그리디 알고리즘이네
	//그래서 정렬이 들어가고 시작하네...
	vector<Edge> v;
	v.push_back(Edge(0, 1, 10));
	v.push_back(Edge(0, 2, 5));
	v.push_back(Edge(1, 2, 7));
	v.push_back(Edge(1, 3, 4));
	v.push_back(Edge(2, 3, 3));
	v.push_back(Edge(2, 4, 2));
	v.push_back(Edge(3, 4, 1));

	sort(v.begin(), v.end());

	for (int i = 1; i <= 5; i++) parent[i] = i;

	int sum = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (!IsCycle(v[i].node[0], v[i].node[1]))
		{
			sum += v[i].distance;
			UnionParent(v[i].node[0], v[i].node[1]);
		}
	}
	for (int i = 0; i < 5; i++)
		cout << parent[i] << endl;
	cout << sum << endl;

	return 0;
}

