#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 301

using namespace std;

int arr[301] = { 0, };
int cnt = 0;
int add = 0;
bool visited[301] = { false, };
void DFS(int current, int count)
{
	if (count > cnt - 1)  return;
	for (int next = current + 1; next < cnt; next++)
	{
		if (visited[next]
			|| arr[next - 1] >= arr[next]) continue;
		visited[next] = true;
		if (arr[next + 1] > arr[next])
		{
			add += arr[next + 1];

		}
		else add += arr[next];
		DFS(next, count + 1);
	}
}


int main()
{

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
		cin >> arr[i];

	add += arr[0];
	visited[0] = true;
	DFS(0, 0);
	cout << add << endl;
	return 0;
}

