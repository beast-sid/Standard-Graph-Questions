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

bool checkForCycle(int s, vector<int> adj[], vector<int>& visited)
{
	//vector<int> parent(V, -1);

	// Create a queue for BFS
	queue<pair<int, int>> q;

	visited[s] = 1;
	q.push({ -1, s});

	while (!q.empty()) {

		int par = q.front().first;
		int node = q.front().second;
		q.pop();

		for (auto it : adj[node]) {
			if (!visited[it]) {
				visited[it] = true;
				q.push({node, it});
			}
			else if (par != it)
				return true;
		}
	}
	return false;
}

int main()
{
	int V, E;
	cin >> V >> E;
	vector<int>adj[V + 1];
	for (int i = 1; i <= E; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> vis(V + 1, 0);
	ll f = 0;
	for (int i = 1; i <= V; i++)
	{
		if (!vis[i])
		{
			if (checkForCycle(i, adj, vis))
			{
				cout << "Yes there is cycle";
				f = 1;
				break;
			}
		}
	}
	if (!f)cout << "No cycle";
	return 0;
}  // } Driver Code Ends

