#include <iostream>
#include <vector>
using namespace std;



// 함수 원형 선언
int knapsack(int W, vector<int>& wt, vector<int>& val, int n);

// 최대값을 반환하는 함수
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Knapsack 문제를 해결하는 함수
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    // 기저 사례: 아이템이 없거나 최대 무게가 0
    if (n == 0 || W == 0)
        return 0;

    // 현재 아이템의 무게가 최대 무게를 초과하는 경우, 이 아이템을 선택할 수 없음
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);
    else
        // 현재 아이템을 선택하는 경우와 선택하지 않는 경우 중 최대 가치를 선택
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


