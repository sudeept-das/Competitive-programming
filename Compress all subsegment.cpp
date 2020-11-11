#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
// Declare a multimap 
multimap<int, string> MM; 
# define M_PI  3.14159265358979323846

const ll M= 998244353;
long long mod(long long x){
    return ((x%M + M)%M);
}

long long mul(long long a, long long b){
    return mod(mod(a)*mod(b));
}



void add(ll &a, ll b) {
	a+=b;
	if(a>=M)
		a-=M;
}

ll f(ll x)
{
	ll i;
	for(i=29;i>=0;i--)
	{
		if((x>>i)&1) {
			return (1<<i);
		}
	}
	return 0;
}

ll cost(vector<ll> b)
{
	if(b.size()==1) return b[0];
	else
	{
		ll ans=(1<<30),i,j;
		for(i=0;i<b.size();i++)
		{
			for(j=i+1;j<b.size();j++)
			{
				vector<ll> c=b;
				c[i]=f(b[i]^b[j]);
				c.erase(c.begin()+j);
				ans = min(ans,cost(c));
			}
		}
		return ans;
	}
	
}

ll ret(vector<ll> ok, ll x)
{
	vector<ll> ret(2);
	ll pref=0,s=0,i,j;
	ret[0]++;
	for(ll &y:ok) 
	{
		if((y>>x)&1)
			pref^=1;
		add(s,ret[pref^1]);
		ret[pref]++;
	}
	for(i=0;i<ok.size();i++)
	{
		ll cur=0;
		for(j=i;j<i+4 && j<ok.size();j++)
		{
			cur^=ok[j];
			if((cur>>x)&1)
				add(s,M-1);
		}
	}
	return (s*(1<<x))%M;
}

int main()
{
	ll n,i;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	ll sum=0,j;
	for(i=0;i<n;i++)
	{
		vector<ll> b;
		for(j=i;j<n && j<(i+4);j++)
		{
			b.push_back(a[j]);
			add(sum,cost(b));
		}
	}
	ll x;
	for(x=29;x>=0;x--)
	{
		vector<ll> ok;
		for(i=0;i<n;i++)
		{
			if(a[i]>=(1<<(x+1)))
			{
				add(sum,ret(ok,x));
				ok.clear();
			}
			else
				ok.push_back(a[i]);
		}
		add(sum,ret(ok,x));
	}
	cout<<sum<<"\n";
	return 0;
}
