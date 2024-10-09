#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    stack<int> s ;
    int x=10;
    
    while(x){
        s.push(x%8);
        x=x/8;
    }
        int i= 0;
    while(s.empty()!=true){
        i+= s.top();
        cout<<s.top()<<" ";
        s.pop();
    }
    
        // cout<<i<<" ";
    return 0;
}