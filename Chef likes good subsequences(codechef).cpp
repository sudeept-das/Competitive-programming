#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long int ll;
// Declare a multimap 
multimap<int, string> MM; 
# define M_PI  3.14159265358979323846


const int M=1e9+7;
long long mod(long long x){
    return ((x%M + M)%M);
}
long long add(long long a, long long b){
    return mod(mod(a)+mod(b));
}
long long mul(long long a, long long b){
    return mod(mod(a)*mod(b));
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		ll a[n+1],i;
		for(i=1;i<=n;i++)
			cin>>a[i];
		ll ans=0,p=-1,v,pp=-1;
		map<ll,ll> rm;
		for(i=1;i<=n;i++)
		{
			if(p!=a[i])
			{
				p=a[i];
				if(pp!=-1)
					rm[pp]=p;
				ans++;
				pp=i;
			}
		}
		while(q--)
		{
			cin>>p>>v;
			if(mp.find())
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}
