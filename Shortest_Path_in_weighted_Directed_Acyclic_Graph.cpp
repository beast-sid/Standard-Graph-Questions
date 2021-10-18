//Dijkstras algo wprks for both directed and undire. graphs.

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
void bfs(int src, int n, vector<pair<ll, ll>> adj[])
{
	vector<ll> dist(n + 1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[src] = 0;
	pq.push(make_pair(0, src));
	while (!pq.empty())
	{
		int d = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		for (auto it : adj[node])
		{
			if (dist[it.first] > dist[node] + it.second)
			{
				dist[it.first] = dist[node] + it.second;
				pq.push(make_pair(dist[it.first], it.first));
			}
		}

	}
	for (auto it : dist)cout << it << " ";
}
int main()
{
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> adj[n + 1];
	loop(0, m, i)
	{
		ll a, b, wt; // undirected graph;
		cin >> a >> b >> wt;
		adj[a].pb(make_pair(b, wt));
		adj[b].pb(make_pair(a, wt));
	}
	bfs(5, n, adj);
}