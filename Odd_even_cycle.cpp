//To check if a graph has odd length cycle or even cycle ,then we will check wheather the graph can be coloured with two different colours
//If it cannot be coloured then it has odd length cycle else it will have even length cycle,i.e. we have to check wheather the graph is
//bipartite or not.

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
bool check(int n, vector<int>&color, int col, vector<int> adj[])
{
	color[n] = col;
	for (auto it : adj[n])
	{
		if (color[it] == -1)
		{
			if (check(it, color, 1 - col, adj) == false)return false;
		}
		else if (color[it] != (1 - col))return false;
	}
	return true;
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
		adj[v].push_back(u);
	}
	vector<int> color(n + 1, -1);
	if (check(1, color, 1, adj))
		cout << "Even Length Cycle";
	else cout << "Odd length Cycle";

	return 0;
}