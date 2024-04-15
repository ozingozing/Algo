#include <iostream>
#include <vector>
using namespace std;



// �Լ� ���� ����
int knapsack(int W, vector<int>& wt, vector<int>& val, int n);

// �ִ밪�� ��ȯ�ϴ� �Լ�
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Knapsack ������ �ذ��ϴ� �Լ�
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    // ���� ���: �������� ���ų� �ִ� ���԰� 0
    if (n == 0 || W == 0)
        return 0;

    // ���� �������� ���԰� �ִ� ���Ը� �ʰ��ϴ� ���, �� �������� ������ �� ����
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);
    else
        // ���� �������� �����ϴ� ���� �������� �ʴ� ��� �� �ִ� ��ġ�� ����
        return max(
            val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
            knapsack(W, wt, val, n - 1)
        );
}

int main() {
    vector<int> values = { 60, 100, 120 };
    vector<int> weights = { 10, 20, 30 };
    int max_weight = 50;
    int n = values.size();

    cout << "Maximum value in Knapsack = " << knapsack(max_weight, weights, values, n);
    return 0;
}


