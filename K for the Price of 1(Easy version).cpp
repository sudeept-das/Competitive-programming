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
		ll i,m,n,p,k,c=0,odds=0,evens=0,v;
		cin>>n>>p>>k;
		ll a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		for(i=1;i<=n;i++)
		{
			v=a[i-1];
			if(i%2==0)
			{
				evens+=v;
				if(evens<=p){
					c=max(c,i);
				}
			}
			else
			{
				odds+=v;
				if(odds<=p){
					c=max(c,i);
				}
			}
		}
		
		cout<<c<<"\n";
	}
}
