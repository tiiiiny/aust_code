#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 定义一个结构体 point
struct point {
    int l;
    int other_data;  // 其他数据成员
};
int main() {
    // 创建一个 point 类型的 vector
    vector<point> points = {{5, 10}, {3, 20}, {8, 30}, {1, 40}};

    // 使用 Lambda 表达式作为比较函数
    sort(points.begin(), points.end(), [](const point &x, const point &y) {
        return x.l < y.l;
    });

    // 输出排序后的结果
    for (const auto &p : points) {
        cout << p.l << " " << p.other_data << endl;
    }

    return 0;
}
