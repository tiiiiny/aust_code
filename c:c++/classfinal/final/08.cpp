/*
* 分治查找第 k 小元素
*input:
5
1 2 3 4 5
3

6
20 5 -6 9 0 7
3

14
20 18 16 14 12 10 8 6 4 2 0 -2 -4 -6
4

8
3 8 10 2 9 38 2 -9
6
*output:
3

7

0

9
*/


#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int findKthSmallest(vector<int>& nums, int k) {
    int n = nums.size();
    if (k < 1 || k > n) {
        return -1;
    }
    
    int left = 0, right = n - 1;
    while (left <= right) {
        int pivotIndex = rand() % (right - left + 1) + left;
        int pivot = nums[pivotIndex];
        
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
        if (j + 1 == k) {
            return pivot;
        }
        else if (j + 1 > k) {
            right = j;
        }
        else {
            left = j + 1;
        }
    }
    return -1;
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
