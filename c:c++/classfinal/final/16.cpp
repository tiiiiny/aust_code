/*最大子矩阵
* 【输入样例】
4
1 0 1 1
1 1 1 1
1 1 1 1
0 1 -6 -8

4
0 -2 -7 0
9 2-6 2
-4 1 -4 1
-1 8 0 -2

7 7
1 3 4 7 3 5 3
3 -2 4 -4 0 3 -2
9 4 0 -3 4 3 0
3 2 8 -1 3 4 9
4 -1 9 -2 3 9 -4
0 3 9 6 7 -2 -3
4 8 6 8-2 -8 -4
* 【输出样例】
11

15

134
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

// 一维数组的最大子段和（Kadane算法）
int maxsub(int a[], int n) {
    int current_sum = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++) {
        current_sum = max(a[i], current_sum + a[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dp[i][j];

    int maxsubrec = INT_MIN;
    int arr[101]; 

    for (int i = 0; i < n; i++) {
        memset(arr, 0, sizeof(arr));
        for (int j = i; j < n; j++) {
            for (int k = 0; k < n; k++)
                arr[k] += dp[j][k];
            int maxsubarr = maxsub(arr, n);
            maxsubrec = max(maxsubrec, maxsubarr);
        }
    }

    cout << maxsubrec << endl;
    return 0;
}

