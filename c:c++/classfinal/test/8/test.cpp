#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

// 获取随机数
int getRandom(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// 分治查找第 k 小元素
int findKthSmallest(vector<int>& nums, int k) {
    int n = nums.size();
    if (k < 1 || k > n) {
        return -1; // 如果 k 不在合法范围内，返回 -1
    }
    
    int left = 0, right = n - 1;
    while (left <= right) {
        // 随机选择一个基准元素
        // int pivotIndex = getRandom(left, right);
        int pivotIndex = rand() % (right - left + 1) + left;
        int pivot = nums[pivotIndex];
        
        // 将数组分为两部分，小于等于基准元素的放在左边，大于基准元素的放在右边
        int i = left - 1, j = right + 1;
        while (i < j) {
            do {
                i++;
            } while (nums[i] < pivot);
            do {
                j--;
            } while (nums[j] > pivot);
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        
        // 如果基准元素的位置恰好是第 k 小的位置，则返回基准元素
        if (j + 1 == k) {
            return pivot;
        }
        // 如果基准元素的位置大于第 k 小的位置，则在左边继续查找
        else if (j + 1 > k) {
            right = j;
        }
        // 如果基准元素的位置小于第 k 小的位置，则在右边继续查找
        else {
            left = j + 1;
        }
    }
    return -1; // 出错时返回 -1
}

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cin >> k;
    
    int kthSmallest = findKthSmallest(nums, k);
    if (kthSmallest != -1) {
        cout << kthSmallest << endl;
    } 
	// else {
    //     cout << "Invalid input! " << endl;
    // }
    return 0;
}
