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
		cin>>n>>x;
		ll a[n+1],pre[n+1],p,c=0,m=0,d;
		for(i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1,greater<ll>());
		memset(pre,0,sizeof(pre));
		for(i=1;i<=n;i++)
		{
			
			if(x%a[i]==0)
				d=x/a[i];
			else
			{
				d=x/a[i];
				d++;
			}
			c=0;
			if(d<=i)
			{
				c++;
				if(i-d>0)
					c=c+pre[i-d];
				pre[i]=c;
			}
		}
		for(i=1;i<=n;i++)
		{
			//cout<<pre[i]<<" ";
			if(pre[i]>m)
				m=pre[i];
		}
		//cout<<"\n";
		cout<<m<<"\n";
	}
	return 0;
}
