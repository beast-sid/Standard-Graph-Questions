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
ll parent[100005];
ll rank1[100005] = {0};
ll findparent(ll node)
{
	if (node == parent[node])return node;
	else
		return parent[node] = findparent(parent[node]); // parent[node]=findparent(parent[node]) for path compression
}
void union1(ll u, ll v)
{
	u = findparent(u);
	v = findparent(v);
	if (rank1[u] > rank1[v])
		parent[v] = u;

	else if (rank1[u] < rank1[v])
		parent[u] = v;

	else
	{
		parent[v] = u;
		rank1[u]++;
	}
}
int main()
{
	//initially every node is its own parent;
	for (int i = 0; i <= 100000; i++)parent[i] = i;

	ll m;
	cin >> m;
	while (m--)
	{
		ll u, v;
		cin >> u >> v;
		union1(u, v);
	}
	// check if 2 and 3 are in same component
	if (findparent(2) != findparent(3))cout << "They are in different component" << endl;
	else cout << "They are in same component" << endl;

	return 0;
}