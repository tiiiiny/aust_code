#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string x;
    cin>>x;
    stack<char> s;
    auto it = x.begin();
    while(it!=x.end()){
        if(*it=='a'||*it=='e'||*it=='i'||*it=='o'||*it=='u'){
            s.push(*it);
        }
        it++;
    }
    cout<<s.top()<<endl;
    return 0;
}