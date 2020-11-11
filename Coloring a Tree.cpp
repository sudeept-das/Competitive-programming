#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
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
ll a[10001],c[10001],n;
ll trav(ll cc,ll i)
{
	ll j;
	for(j=i;j<=n;j++)
	{
		if(a[j]==i)
		{
			if(cc!=c[j])
			{
				//cout<<j<<" : "<<cc<<"->"<<c[j]<<"\n";
				return 1+trav(c[j],j);
			}
			else if(cc==c[j])
				return trav(c[j],j);
		}
	}
	return 0;
}
int main()
{
	ll i;
	cin>>n;
	ll cc,s=1;
	vector<ll> r;
	for(i=1;i<=n;i++)
		r.push_back(i);
	a[1]=0;
	for(i=2;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		cin>>c[i];
	for(i=2;i<=n;i++)
	{
		if(c[a[i]]!=c[i])
			s++;
	}
	cout<<s<<"\n";
	return 0;
}
