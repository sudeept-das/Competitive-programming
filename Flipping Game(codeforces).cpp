#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll n,i,j,m=0,c=0,;
	cin>>n;
	ll a[n],dp[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>=0)
			dp[i]=1;
		else
		{
			dp[i]=-1;
		}
	}
	ll f=dp[0],f1;
	for(i=1;i<n;i++)
		if(dp[i]!=p)
			c++;
	cout<<c;
	return 0;
}
