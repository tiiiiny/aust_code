#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int two(int x){
    while(x/2){
        
    }
}
int eight(int x){

}
int main(){
    int x;
    cin>>x;
    int a=x/100000;
    int b=(x-a*100000)/10000;
    int c=(x-b*10000-a*100000)/1000;
    int d=(x-c*1000-b*10000-a*100000)/100;
    int e=(x-d*100-c*1000-b*10000-a*100000)/10;
    int f=(x-e*10-d*100-c*1000-b*10000-a*100000)/1;
    cout<<a+b*100000+c*10000+d*1000+e*100+f*10<<endl;

    return 0;
}