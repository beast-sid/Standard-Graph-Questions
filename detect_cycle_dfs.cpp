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
bool checkForcycle(ll par, ll node, vector<ll> adj[], vector<ll>&vis)
{
	vis[node] = 1;
	for (auto it : adj[node])
	{
		if (!vis[it])
		{
			if (checkForcycle(node, it, adj, vis))return true;
		}
		else
		{
			if (it != par)return true;
		}
	}
	return false;
}
int main()
{
	int V, E;
	cin >> V >> E;
	vector<ll>adj[V + 1];
	for (int i = 1; i <= E; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<ll> vis(V + 1, 0);
	ll f = 0;
	for (int i = 1; i <= V; i++)
	{
		if (!vis[i])
		{
			if (checkForcycle(-1, i, adj, vis))
			{
				cout << "Yes there is cycle";
				f = 1;
				break;
			}
		}
	}
	if (!f)cout << "No cycle";
	return 0;
}