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
ll a[100001],b[100001],n;
ll dp[100001][2];
ll solve(ll p,ll c)
{
	if(p>=n)
		return 0;
	else
	{
		if(dp[p][c]!=-1)
			return dp[p][c];
		else if(c==0)
			return dp[p][c]=max(a[p]+solve(p+1,1),a[p]+solve(p+2,1));
		else
			return dp[p][c]=max(b[p]+solve(p+1,0),b[p]+solve(p+2,0));
	}
		
}
int main() 
{
	ll i;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	cout<<max(solve(0,0),solve(0,1));
	return 0;
}
