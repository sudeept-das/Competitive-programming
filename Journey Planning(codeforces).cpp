#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;


int main()
{
	ll x,t,i,j;
	
	ll m=0,p;
	cin>>n;
	ll a[n+1];
	map<ll,ll> fm,s;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(fm.find(a[i]-i)==fm.end())
		{
			fm[a[i]-i]=1;
			s[a[i]-i]=a[i];
		}
		else
		{
			fm[a[i]-i]++;
			s[a[i]-i]=s[a[i]-i]+a[i];
		}
		if(m<s[a[i]-i])
			m=s[a[i]-i];
	}
	
	cout<<m;
	return 0;
}
