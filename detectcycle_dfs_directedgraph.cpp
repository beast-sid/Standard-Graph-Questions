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
bool check(int node, vector<int>&vis, vector<int>&dfsvis, vector<int> adj[])
{
	vis[node] = 1;
	dfsvis[node] = 1;
	for (auto it : adj[node])
	{
		if (!vis[it])
		{
			if (check(it, vis, dfsvis, adj))return true;
		}
		else if (dfsvis[it])
		{
			return true;
		}
	}
	dfsvis[node] = 0;
	return false;
}
int main()
{
	int V, E, f = 0;
	cin >> V >> E;
	vector<int>adj[V + 1];
	vector<int> vis(V + 1, 0), dfsvis(V + 1, 0);
	for (int i = 0; i < E; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= V; i++)
	{
		if (!vis[i])
		{
			if (check(i, vis, dfsvis, adj))f = 1, cout << "Cycle is there";

		}
	}
	if (f == 0)cout << "Cycle is not there";
	return 0;
}