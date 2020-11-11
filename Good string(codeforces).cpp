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
		string s;
		cin>>s;
		ll i,j,n;
		n=s.length();
		ll a[n],dc[10],d,m=0,f=0,c=0,k=0;
		memset(dc,0,sizeof(dc));
		
		for(i=0;i<n;i++)
		{
			d=(int)(s[i]-'0');
			dc[d]++;
		}
		for(i=0;i<10;i++)
		{
			for(k=0;k<10;k++)
			{
				c=0;
				f=0;
				//cout<<s[i-1]<<s[i];
				for(j=0;j<n;j++)
				{
					d=(int)(s[j]-'0');
					if(f==0 && d==i)
					{
						f=1;
						//cout<<s[j];
					}
					else if(f==1 && d==k)
					{
						c=c+2;
						f=0;
						//cout<<s[j];
					}
				}
				if(m<c)
				{
					m=c;
					//cout<<s[i-1]<<s[i]<<"\n";
				}
			}
		}
		//cout<<m<<"\n";
		for(i=0;i<10;i++)
		{
			if(dc[i]>m)
				m=dc[i];
			//cout<<dc[i]<<" ";
		}
		//cout<<"\n";
		//cout<<m<<"\n";
		//cout<<n<<"\n";
		
		cout<<n-m<<"\n";
	}
	return 0;
}
