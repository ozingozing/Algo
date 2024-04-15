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
	//DFS -> nextDFS�̷��� Ÿ����� �浵�� ���� �� �߰�!
	if (str1[endY] == str2[endX] && !flag)
	{
		stack1.push_back(str2[endX]);
	}
	//�̰� for������ ��� Ÿ�� ���״� �극��ũ �ϳ� �ɾ��ֱ�!
	//DFS�� �극��ũ �� �ɾ��൵ ������ �� ���� �ֳ� ���� DFS�� �ѱ� �� �Ķ���͸� ��� �ֽ�ȭ ���� �ָ鼭 �־��ֱ� ������
	//�׷��� �Ҿ��ϴ� �ɾ������~
	if (endX < 0 || endY < 0)
	{
		flag = true;
		return;
	}

	//�� �� Ȯ��!
	for (int i = 0; i < 2; i++)
	{
		int nx = endX + dx[i];
		int ny = endY + dy[i];
		if (nx < 0 || ny < 0) continue;
		if (arr[ny][nx] == arr[endY][endX])
		{
			//�� �Ǵ� ���� ���� ���� Ȯ���߾�!
			//�׷��� DFS -> nextDFS �̷��� Ÿ�� ���� �ٽ� �������� ����
			//�� �ٽ� ���� �߰����� ���!
			if (ny == size1 - 1 && nx == size1
				|| ny == size1 && nx == size1 - 1)
			{
				cout << "ny : " << ny << " nx : " << nx << endl;
				flag = false;
			}
			DFS(nx, ny);
		}
	}
	//�� �� Ȯ�� �ϴµ� ���� �� �ٱ��� �Դٴ� �� �Լ��� ȣ���� �� �ƴٴ� ��
	//�� ���� �� �� ���� ���� ���ٴ� ��
	//�׷��� �밢�� ����
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