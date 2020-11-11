#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<string> v;
ll tmc[1001],l[1001],h[1001],n;


int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll m,i,f=1,mn,mx,p=0;
		cin>>n>>m;
		mx=mn=m;
		for(i=1;i<=n;i++)
			cin>>tmc[i]>>l[i]>>h[i];
		for(i=1;i<=n;i++)
		{
			mx+=tmc[i]-p;
			mn-=tmc[i]-p;
			if(mn<=h[i] && mx>=l[i])
			{
				mn=max(mn,l[i]);
				mx=min(mx,h[i]);
			}
			else
			{
				f=0;
				break;
			}
			p=tmc[i];
		}
		if(f==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	
	return 0;
}
