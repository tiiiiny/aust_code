// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const int N = 1e9;

int n,m;
int x[N],y[N],r[N];
int X[N],Y[N],R[N];
// ll dp[N];

int lenn(int x1,int y1,int x2,int y2) {
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}


int main() {
	cin >> n>>m;
	for(int i=0;i<n;i++) cin >> x[i] >> y[i] >> r[i];
	for(int i=0;i<n;i++) {
		cin >> X[i] >> Y[i] >> R[i];
		for(int j=0;j<m;j++) {
			if(lenn(X[i],Y[i],x[j],y[j])<=R[i]**2) {
				while()
	}
	return 0;
}
