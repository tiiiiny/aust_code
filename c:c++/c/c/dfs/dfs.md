```
DFS(v)	// v 可以是图中的一个顶点，也可以是抽象的概念，like dp 状态 etc.
	在v上打标记
	for u in v 的相邻节点
		if u 没有打过访问标记 then
			DFS(u)
		end
	end
end
```

    ,

    ,

  ,	,

  .  .

```cpp

vector<vector<int>> adj;	// 邻接表
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
				vis[v] = true;
				st.push(v)
			}
		}
	}
}

```

```cpp

vector<vector<int>> adj;	// 邻接表
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
				vis[v] = true;
				st.push(v)
			}
		}
	}
}


```
