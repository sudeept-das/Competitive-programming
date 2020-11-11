#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll a[200001],n;
ll dp[200002][2];
ll solve(ll i, ll turn)
{
	ll m=1000000000;
	if(i>=n)
	{
		dp[i][turn]=0;
		return 0;
	}
	if(dp[i][turn]!=-1)
		return dp[i][turn];
	if(turn==1)
	{
		
		if(a[i]==1 && i+1<n)
		{
			m=min(m,1+solve(i+1,0));
			if(a[i+1]==1 && i+2<n)
				m=min(m,2+solve(i+2,0));
			else if(a[i+1]==0 && i+2)
				m=min(m,1+solve(i+2,0));
		}
		else if(a[i]==0 && i+1<n)
		{
			m=0+min(m,solve(i+1,0));
			if(a[i+1]==1)
				m=min(m,1+solve(i+2,0));
			else if(a[i+1]==0)
				m=min(m,0+solve(i+2,0));
		}
		else if(a[i]==0)
			return 0;
		else if(a[i]==1)
			return 1;
	}
	else
	{
		if(i+1<n)
		{
			m=min(m,0+solve(i+1,1));
			m=min(m,0+solve(i+2,1));
		}
		else
			return 0;
	}
	dp[i][turn]=m;
	return dp[i][turn];
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll i,j;
		for(i=0;i<n;i++)
			cin>>a[i];
		memset(dp,-1,sizeof(dp));
		dp[0][1]=solve(0,1);
		cout<<dp[0][1]<<"\n";
	}
	return 0;
}
