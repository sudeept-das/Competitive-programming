#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll i,m,n,p,k,c=0,ans=0,s=0,pref=0,j;
		cin>>n>>p>>k;
		ll a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		for(i=0;i<=k;i++)
		{
			s=pref;
			if(s>p)
				break;
			c=i;
			for(j=i+k-1;j<n;j+=k)
			{
				if(s+a[j]<=p)
				{
					s=s+a[j];
					c=c+k;
				}
				else
					break;
			}
			pref=pref+a[i];
			ans=max(ans,c);
		}
		
		cout<<ans<<"\n";
	}
}
