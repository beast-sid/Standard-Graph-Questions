#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
//#define mp make_pair
#define loop(a,b,i) for(ll i=a;i<b;i++)
#define loop1(a,b,i) for(ll i=a;i>=b;i--)
#define nn cout<<"NO"<<endl
#define yy cout<<"YES"<<endl
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
void check(int node, vector<int>&vis, vector<int> adj[], stack<int>&st)
{
	vis[node] = 1;
	for (auto it : adj[node])
	{
		if (!vis[it])
		{
			check(it, vis, adj, st);
		}
	}
	st.push(node);
}
int main()
{
	int V, E, f = 0;
	cin >> V >> E;
	vector<int>adj[V + 1];
	vector<int> vis(V + 1, 0);
	stack<int> st;
	for (int i = 0; i < E; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 0; i < V; i++)
	{
		if (!vis[i])
		{
			check(i, vis, adj, st);

		}
	}
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}