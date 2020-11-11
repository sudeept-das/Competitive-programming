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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll n,q,i;
	cin>>n;
	ll a;
	map<ll, vector<ll> > tr;
	for(i=2;i<=n;i++)
	{
		cin>>a;
		if(tr.find(a)==tr.end())
		{
			vector<ll> vect;
			vect.push_back(i);
			tr[a]=vect;
		}
		else
		{
			tr[a].push_back(i);
		}
	}
	map<ll, vector<ll> >::iterator itr;
	ll f=1,c=0;
	for(itr=tr.begin();itr!=tr.end();itr++)
	{
		vector<ll> vect = itr->second;
		c=0;
		for(i=0;i<vect.size();i++)
		{
			if(tr.find(vect[i])==tr.end())
				c++;
			if(c==3)
				break;
		}
		if(c<=2)
		{
			f=0;
			break;
		}
	}
	if(f==0)
		cout<<"NO\n";
	else
		cout<<"YES\n";
	return 0;
}
