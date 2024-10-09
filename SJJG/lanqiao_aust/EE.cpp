#include <iostream>
#include <string>
using namespace std;

int main(){
    int n,k;
    long sum=0,max=0;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n-k;i++){
        sum=0;
        for(int j=i;j<i+k;j++){
            sum+=a[j];
        }
        max=max>sum?max:sum;
    }
    cout<<max<<endl;
    return 0;
}