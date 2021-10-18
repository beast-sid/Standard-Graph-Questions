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
void bfs(vector<ll> adj[], int node, int n)
{
	queue<ll> q;
	vector<ll> dist(n, INT_MAX);
	dist[node] = 0;
	q.push(node);
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		for (auto it : adj[k])
		{
			if (dist[it] > dist[k] + 1)
			{
				q.push(it);
				dist[it] = dist[k] + 1;
			}
		}
	}
	for (auto it : dist)cout << it << " ";
}
int main()
{
	ll n, e;
	cin >> n >> e;
	vector<ll> adj[n + 1];
	loop(0, e, i)
	{
		ll a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	bfs(adj, 8, n);
}