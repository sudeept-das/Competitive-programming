#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
// Declare a multimap 
multimap<int, string> MM; 
# define M_PI  3.14159265358979323846


const int M=1e9+7;
long long mod(long long x){
    return ((x%M + M)%M);
}
long long add(long long a, long long b){
    return mod(mod(a)+mod(b));
}
long long mul(long long a, long long b){
    return mod(mod(a)*mod(b));
}
vector<ll> edge[100001];
ll c[2];
ll vis[100001];
void dfsc(ll cur,ll par, ll col)
{
	if(vis[cur]==0)
	{
		c[col]++;
		vis[cur]=1;
	}
	for(ll i=0;i<edge[cur].size();i++)
	{
		if(edge[cur][i]!=par)
			dfsc(edge[cur][i],cur,!col);
	}
}
int main()
{
	ll n,i,u,v;
	
	cin>>n;
	memset(vis,0,sizeof(vis));
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	c[0]=0;
	c[1]=0;
	dfsc(1,0,0);
	/*for(i=0;i<a.size();i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	for(i=0;i<b.size();i++)
		cout<<b[i]<<" ";
	cout<<"\n";*/
	cout<<(c[0]*c[1])-(n-1);
	return 0;
}
