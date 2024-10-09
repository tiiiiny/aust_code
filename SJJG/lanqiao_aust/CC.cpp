#include <iostream>
#include <string>
using namespace std;

long f(long x){
    long res=1;
    int y=0;
    while(x){
        y= x-x/10*10;
        if(y!=0)    res=res*y;
        x = x/10;
    }
    return res;
}

int main(){
    long n;
    cin>>n;

    while(n>=10){
        n=f(n);
        cout<<n<<endl;
    }
    return 0;
}