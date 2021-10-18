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
bool dfs(ll node, vector<ll> adj[], vector<ll>&vis)
{
	if (vis[node] == -1)vis[node] = 1;
	for (auto it : adj[node])
	{
		if (vis[it] == -1)
		{
			vis[it] = 1 - vis[node];
			if (dfs(it, adj, vis) == false)
				return false;
		}
		else if (vis[it] == vis[node])return false;
	}
	return true;
}
bool check(vector<ll> adj[], int n)
{
	vector<ll> vis(n + 1, -1);
	for (ll i = 1; i <= n; i++)
	{
		if (vis[i] == -1)
		{
			if (dfs(i, adj, vis) == false)
				return false;
		}
	}
	return true;

}
int main()
{
	ll n, m;
	cin >> n >> m;
	vector<ll> adj[n + 1];
	for (ll i = 1; i <= m; i++)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if (check(adj, n))
		yy;
	else
		nn;
}