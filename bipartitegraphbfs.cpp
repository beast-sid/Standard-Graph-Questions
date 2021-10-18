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
bool bfs(int node, vector<ll> adj[], ll color[])
{
	queue<ll> q;
	color[node] = 0;
	q.push(node);

	while (!q.empty())
	{
		ll c = q.front();
		q.pop();
		for (auto it : adj[c])
		{
			if (color[it] == -1)
			{
				color[it] = 1 - color[c];
				q.push(it);
			}
			else if (color[it] == color[c])
				return false;
		}
	}
	return true;
}
bool check(vector<ll> adj[], int n)
{
	ll color[n + 1];
	memset(color, -1, sizeof color);
	loop(1, n + 1, i)
	{
		if (color[i] == -1)
		{
			if (!bfs(i, adj, color))return false;
		}
	}
	return true;
}
int main()
{
	ll n, m;
	cin >> n >> m;
	vector<ll> adj[n + 1];
	loop(1, m + 1, i)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if (check(adj, n))
		yy;
	else nn;
}