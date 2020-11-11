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
ll v[10001],n;
ll x[10001],y[10001];
void dfs(ll u)
{
	for(ll i=0;i<n;i++)
	{
		if(v[i]==0)
		{
			if(x[i]==x[u] || y[i]==y[u])
			{
				v[i]=1;
				dfs(i);
			}
		}
	}
}
int main()
{
	ll i,c=0,f=0;
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];	
	}	
	memset(v,0,sizeof(v));
	for(i=0;i<n;i++)
	{
		if(v[i]==0)
		{
			c++;
			dfs(i);
		}
	}
	cout<<(c-1);
	return 0;
}

