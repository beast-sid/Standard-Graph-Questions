//To find topological sort using bfs we use Kahns algo.In this algo we will find indegrees of all nodes and the node with smaller indegree
//will come before the node with higher  indegree.Here we will use queue.
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
void kahns(int n, vector<int> adj[])
{
	vector<int> indegree(n + 1, 0);
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		for (auto it : adj[i])
		{
			indegree[it]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)q.push(i);
	}
	while (!q.empty())
	{
		cout << q.front() << " ";
		int n = q.front();
		q.pop();
		for (auto it : adj[n])
		{
			indegree[it]--;
			if (indegree[it] == 0)q.push(it);
		}
	}
}
int main()
{
	ll n, e;
	cin >> n >> e;
	vector<int> adj[n + 1];
	for (int i = 0; i < e; i++)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	kahns(n, adj);
	return 0;
}