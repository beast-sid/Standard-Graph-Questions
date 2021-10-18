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
void prims(vector<pair<int, int>> adj[], int n)
{
	vector<int> parent(n, -1), key(n, INT_MAX), mst(n, 0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	key[0] = 0;
	pq.push({0, 0}); //pq ka first=value of key , pq ka second=index;
	while (!pq.empty())
	{
		int ind = pq.top().second;
		pq.pop();
		mst[ind] = 1;
		for (auto it : adj[ind])
		{
			int v = it.first;
			int wt = it.second;
			if (mst[v] == 0 && key[v] > wt)
			{
				key[v] = wt;
				parent[v] = ind;
				pq.push({wt, v});
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << parent[i] << endl;
	}
}
int main()
{
	ll n, e;
	cin >> n >> e;
	vector<pair<int, int>> adj[n];
	loop(0, e, i)
	{
		ll u, v, wt;
		cin >> u >> v >> wt;
		adj[u].pb(make_pair(v, wt));
		adj[v].pb(make_pair(u, wt));
	}
	prims(adj, n);
}