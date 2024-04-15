#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//parent[1] = 1 �̸� 1�� ��尡 1�� ��忡 ���� �ƴٴ� ��
//parent[1] = 2 �̸� 1�� ��尡 2�� ��忡 ���� �ƴٴ� ��
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

	//�������� ���� ���� 
	bool operator<(Edge& edge) {
		return this->distance < edge.distance;
	}
};

//�θ� Ž��
int FindParent(int node)
{
	if (parent[node] == node) return node;
	return FindParent(parent[node]);
}

//�� ��带 ���� ���� �������� ����
//node���� ū ������ ���� ������ ����
//v1 �� v3�� ���� �ƴٰ� �ϸ� parent[3] = 1 �̷� ������ ����
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
	//�ּҽ��� Ʈ���� �׸��� �˰����̳�
	//�׷��� ������ ���� �����ϳ�...
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

