#include <iostream>
#include <vector>
using namespace std;
int main(){
	std::vector<int> vec{1,2,3,4,5};

	for(std::vector<int>::iterator iter=vec.begin(); iter!=vec.end();++iter){
		std::cout << "old element:" << *iter;
		// std::cout << "old element:" ;


		(*iter) += 1;
		std::cout << " new element:" << *iter << std::endl;
	}
	
	vector<int> vec;
	vector<int>::iterator it = vec.begin();		
	// it的类型就是vector<int>::iterator---迭代器

	sort(vec.begin(),vec.end());
	for(auto& i : vec)						// 增强for循环
		cout << i << “ ”;					// 正序打印

	sort(vec.rbegin(),vec.rend());
	for(auto& i:vec)
		cout << i << “ ”;					// 逆序打印

	// 进阶用法：for(char &c : s)
	// 可以实际地改变字符串s中的字符。
	// 更快。

	for (char c : s)
	// 会复制一个s字符串再进行遍历操作，
	for (char& c : s)
	// 直接引用原字符串进行遍历操作。所以快。


	// 增强型for循环  容器，字符串，数组 etc



}
