#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long int ll;
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
ll ch[100001],a[100001];
ll dp[100001];
ll n;
ll ltor(ll u)
{
	if(u==1)
		return n;
	else if(dp[u]!=-1)
		return dp[u];
	else 
	{
		dp[u]=ch[u]+ltor(a[u]);
		return dp[u];
	}
}
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		
		ll i,v,ans=0;
		cin>>n;
		vector<ll> leaf;
		
		memset(ch,0,sizeof(ch));
		memset(dp,-1,sizeof(dp));
		a[0]=-1;
		a[1]=1;
		for(i=2;i<=n;i++)
		{
			cin>>a[i];
			ch[a[i]]++;
		}
		for(i=1;i<=n;i++)
		{
			//cout<<ch[i]<<" ";
			if(ch[i]==0)
				leaf.push_back(i);
			ch[i]++;
		}
		for(i=0;i<leaf.size();i++)
		{
			ans=max(ans,ltor(leaf[i]));
			//cout<<ans<<" ";
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
