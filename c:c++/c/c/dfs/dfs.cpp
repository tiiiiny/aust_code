#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Graph{
public:
	vector<vector<int> > adj;	// 邻接表
	vector<bool> vis;		// 记录节点是否已经被遍历visit

	void dfs(int s){
		stack<int> st;		// stack
		st.push(s);
		vis[s] = true;

		while(!st.empty()){
			int u = st.top();
			st.pop();

			for (int v : adj[u]){
				if(!vis[v]) {
					vis[v] = true;		// 确保栈里没有重复元素
					st.push(v);	
				}
			}
		}
	}
};

class Graph2{
public:
	vector<vector<int> >  adj;	// 邻接表
	vector<bool> vis;		// 记录节点是否已经被遍历visit

	void dfs(const int u) {
		vis[u] = true;
		for (int v : adj[u]){
			if (!vis[v])	dfs(v);
	}
};



