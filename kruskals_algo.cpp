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
struct node
{
	ll u;
	ll v;
	ll wt;
	node(ll u1, ll v1, ll w1)
	{
		u = u1;
		v = v1;
		wt = w1;
	}
};
bool comp(node n1, node n2)
{
	if (n1.wt < n2.wt)return true;
	else return false;
}
ll findparent(ll u, vector<ll> &parent)
{
	if (u == parent[u])return u;
	else
		return parent[u] = findparent(parent[u], parent);
}
void unionn(ll u, ll v, vector<ll>&rank, vector<ll>&parent)
{
	u = findparent(u, parent);
	v = findparent(v, parent);
	if (rank[u] < rank[v])
		parent[u] = v;
	else if (rank[u] > rank[v])
		parent[v] = u;
	else
	{
		parent[v] = u;
		rank[u]++;
	}
}
int main()
{
	ll n, e, cost = 0;
	cin >> n >> e;
	vector<node> v1;
	for (int i = 1; i <= e; i++)
	{
		ll u, v, wt;
		cin >> u >> v >> wt;
		v1.pb(node(u, v, wt));
	}
	sort(v1.begin(), v1.end(), comp);
	vector<ll> parent(n + 1), rank(n + 1, 0);
	for (int i = 0; i <= n; i++)parent[i] = i;
	vector<pair<ll, ll>> mst;
	for (auto it : v1)
	{
		if (findparent(it.u, parent) != findparent(it.v, parent))
		{
			cost += it.wt;
			mst.pb({it.u, it.v});
			unionn(it.u, it.v, rank, parent);
			//cout << it.u << "_ok_ " << it.v << endl;
		}
	}
	cout << cost << endl;
	for (auto it : mst)cout << it.first << " " << it.second << endl;
}