#include <iostream>
#include <string>
using namespace std;

int f(int x,int y){
    while(y!=0)
    {
        int t;
        t=x%y;
        x=y;
        y=t;
    }
    return x>1?1:0;
}

int main(){
    int n,m,p,q;
    cin>>n>>m;
    int x[n][m],y[n*m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x[i][j];
            y[j+i*m]=0;
        }
    }
    cin>>p>>q;
    int a= x[p][q],count=0;
    if(p==0){
        if(f(a,x[0][q-1]))  y[q+m*p]=1;
        if(q>0&&f(a,x[0][q+1]))  y[q+m*p]=1;
        if(f(a,x[1][q]))  y[q+m*p]=1;
    }
    else if(p-1==n){
        if(q>0&&f(a,x[n][q-1]))  y[q+m*p]=1;
        if(q<n&&f(a,x[n][q+1]))  y[q+m*p]=1;
        if(f(a,x[n-1][q]))  y[q+m*p]=1;
    }
    else{
        if(q>0&&f(a,x[n][q-1]))  y[q+m*p]=1;
        if(q<n&&f(a,x[n][q+1]))  y[q+m*p]=1;
        if(f(a,x[n-1][q]))  y[q+m*p]=1;
        if(f(a,x[n+1][q]))  y[q+m*p]=1;
    }
    for(int i=0;i<n*m;i++){
        if(y[i]==1) count++;
    }
    cout<<count<<endl;
    return 0;
}