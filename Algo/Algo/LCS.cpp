#include <iostream>
#include <malloc.h>
#include <cstring>
#include <queue>
#include <stack>
#define MAX(a, b) (a > b ? a : b)
#define M  6

using namespace std;

char str1[M] = "";
char  str2[M] = "";
int arr[6][6] = { 0, };
bool visited[M] = { false, };
int Count = 0;
int nextX = 0;
int nextY = 0;
int dx[2] = { 0, -1 };
int dy[2] = { -1, 0 };
int arr2[6] = { 0, };
bool flag = false;
int size1 = 0;
vector<char> stack1;
vector<char> stack2;
queue<char> q;
void Func(char* str1, char* str2, int y)
{
	int cnt = 0;
	q.push(str1[cnt]);

	while (!q.empty())
	{
		if (cnt > strlen(str2)) return;
		char cur = q.front();
		q.pop();
		for (int i = 0; i < strlen(str2); i++)
		{
			if (i - 1 >= 0)
				arr[cnt][i] = arr[cnt][i - 1];
			if (cur == str2[i])
			{
				arr[cnt][i] += 1;
			}
			if (cnt - 1 >= 0
				&& arr[cnt][i] < arr[cnt - 1][i])
				arr[cnt][i] = arr[cnt - 1][i];
		}
		q.push(str1[++cnt]);
	}
}

void DFS(int endX, int endY)
{
	//DFS -> nextDFS이렇게 타고오는 길도중 같은 값 발견!
	if (str1[endY] == str2[endX] && !flag)
	{
		stack1.push_back(str2[endX]);
	}
	//이건 for문에서 계속 타고 올테니 브레이크 하나 걸어주기!
	//DFS가 브레이크 안 걸어줘도 끝나긴 할 거임 왜냐 다음 DFS를 넘길 때 파라미터를 계속 최신화 시켜 주면서 넣어주기 떄문에
	//그런데 불안하니 걸어줘야지~
	if (endX < 0 || endY < 0)
	{
		flag = true;
		return;
	}

	//위 옆 확인!
	for (int i = 0; i < 2; i++)
	{
		int nx = endX + dx[i];
		int ny = endY + dy[i];
		if (nx < 0 || ny < 0) continue;
		if (arr[ny][nx] == arr[endY][endX])
		{
			//위 또는 옆에 같은 값을 확인했어!
			//그런데 DFS -> nextDFS 이렇게 타고 가다 다시 원점으로 오고
			//또 다시 길을 발견했을 경우!
			if (ny == size1 - 1 && nx == size1
				|| ny == size1 && nx == size1 - 1)
			{
				cout << "ny : " << ny << " nx : " << nx << endl;
				flag = false;
			}
			DFS(nx, ny);
		}
	}
	//위 옆 확인 하는데 여기 이 줄까지 왔다는 건 함수가 호출이 안 됐다는 것
	//그 뜻은 위 옆 같은 값이 없다는 것
	//그러니 대각선 ㄱㄱ
	DFS(endX - 1, endY - 1);
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	

	cin >> str1;
	cin >> str2;
	Func(str1, str2, 0);
	size1 = strlen(str2) - 1;
	DFS(strlen(str2) - 1, strlen(str2) -1);
	printf("%d\n", strlen(str2));
	for (int i = 0; i < strlen(str2); i++)
	{
		for (int j = 0; j < strlen(str2); j++)
		{
			printf("%ld ,", arr[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < stack1.size(); i++)
		cout << stack1[i] << endl;
	for (int i = 0; i < stack2.size(); i++)
		cout << stack2[i] << endl;

	return 0;
}