#include <iostream>
#include <memory>

using namespace std;	
int main()
{
	std::unique_ptr<int> p(new int(10));
	cout << *p << endl;

	return 0;
}