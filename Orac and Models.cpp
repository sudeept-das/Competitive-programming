#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;


int main()
{
	ll x,t,i,j;
	cin>>t;
	while(t--)
	{
		ll m=0,p;
		cin>>n;
		ll a[n+1],pre[n+1];
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			pre[i]=1;
		}
		for(i=1;i<=n;i++)
		{
			for(j=2;i*j<=n;j++)
			{
				if(a[i]<a[i*j])
					pre[i*j]=max(pre[i*j],pre[i]+1);
			}
		}
		for(i=1;i<=n;i++)
		{
			//cout<<pre[i]<<" ";
			if(pre[i]>m)
				m=pre[i];
		}
		cout<<m<<"\n";
	}
	return 0;
}
