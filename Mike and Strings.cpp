#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;
string s[512];
ll dp[512][512];
int main()
{
	ll i,j,k,n;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>s[i];
	k=s[1].length();
	for(i=1;i<=n;i++)
		for(j=0;j<k;j++)
			dp[i][j]=1000000000;
	for(i=1;i<=n;i++)
		s[i]=s[i]+s[i];
	for(i=0;i<k;i++)
		dp[1][i]=i;
	for(i=2;i<=n;i++)
	{
		for(j=0;j<k;j++)
			for(ll prev=0;prev<k;prev++)
				if(s[i].substr(j,k)==s[i-1].substr(prev,k))
					dp[i][j]=min(dp[i][j],dp[i-1][prev]+j);
	}
	ll ans=1000000000;
	for(i=0;i<k;i++)
		ans=min(ans,dp[n][i]);
	if(ans==1000000000)
		cout<<"-1";
	else
		cout<<ans<<"\n";
	return 0;
}
