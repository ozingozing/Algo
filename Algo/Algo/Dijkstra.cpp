#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;

int arr[6][6]{
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0},
};

vector<pair<int, int>> a[7];

bool v[6]; //방문한 노드
int d[7]; //최단 거리

void dijkstra(int start)
{
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty())
	{
		int currentPos = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();
		if (cost > d[currentPos]) continue;
		for (int i = 0; i < a[currentPos].size(); i++)
		{
			int nextPos = a[currentPos][i].first;
			int addCost = cost + a[currentPos][i].second;
			if (addCost < d[nextPos])
			{
				d[nextPos] = addCost;
				pq.push(make_pair(nextPos, -addCost));
			}
		}
	}
}





void Dijkstra(int start)
{
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));
	while (!pq.empty())
	{
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++)
		{
			int next = a[current][i].first;
			int nextDistance = distance + a[current][i].second;

			if (nextDistance < d[next])
			{
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int GetSmallIndex()
{
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++)
	{
		if (d[i] < min && !v[i])
		{
			min = d[i];
			index = i;
		}
	}
	return index;
}

void Dijstra1(int start)
{
	for (int i = 0; i < number; i++)
	{
		d[i] = arr[start][i];
	}
	v[start] = true;
	for (int i = 0; i < number - 2; i++)
	{
		int current = GetSmallIndex();
		v[current] = true;
		for (int j = 0; j < 6; j++)
		{
			if (!v[j])
			{
				if (d[current] + arr[current][j] < d[j])
				{
					d[j] = d[current] + arr[current][j];
				}
			}
		}
	}
}


int main()
{
	/*
	Dijstra1(0);

	for (int i = 0; i < number; i++)
	{
		printf("%d ", d[i]);
	}
	*/

	for (int i = 1; i <= number; i++)
	{
		d[i] = INF;
	}

	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	//Dijkstra(1);
	dijkstra(1);
	for (int i = 1; i <= number; i++)
		printf("%d ", d[i]);

	return 0;
}