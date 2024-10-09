#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

int two(int x){
    stack<int> s ;
    while(x){
        s.push(x%2);
        x=x/2;
    }
    int i= 0;
    while(s.empty()!=true){
        i+= s.top();
        s.pop();
    }
    return i;
}
int eight(int x){
    stack<int> s;
    while(x){
        s.push(x%8);
        x=x/8;
    }
    int i= 0;
    while(s.empty()!=true){
        i+= s.top();
        s.pop();
    }
    return i;
}
int main(){
    // long x= pow(2,2023);
    int count =0;
    for(int i =1;i<5000;i++){
        if(two(i) == eight(i)){
            count++;
            cout<<count<<":";
            cout<<i<<endl;
        }
    }
    // cout<<x/1000<<endl;
    // cout<<x%1000<<endl;

    return 0;
}