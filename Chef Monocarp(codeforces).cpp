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
ll a[201],n;
ll dp[201][401];
ll solve(ll idx,ll t)
{
	if(idx==n)
		return 0;
	if(dp[idx][t]!=-1)
		return dp[idx][t];
	ll mn=INT_MAX;
	for(ll i=t;i<=max(t,a[idx]);i++)
		mn=min(mn,abs(a[idx]-i)+solve(idx+1,i+1));
	return dp[idx][t]=mn;
}
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		cin>>n;
		ll i;
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		cout<<solve(0,1)<<"\n";
	}
	return 0;
}
