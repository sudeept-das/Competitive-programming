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

void findFactore(vector<ll>&v,ll q)
{
	v.push_back(q);
	ll i;
	for(i=2;i<=sqrt(q);i++)
	{
		if(q%i==0)
		{
			v.push_back(i);
			if(q/i!=i)
				v.push_back(q/i);
		}
	}
}
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll p,q,i,ans=0,tt;
		cin>>p>>q;
		if(p%q!=0)
			cout<<p<<"\n";
		else
		{
			vector<ll> vect;
			findFactore(vect,q);
			for(i=0;i<vect.size();i++)
			{
				tt=p;
				while(p%vect[i]==0)
				{
					p=p/vect[i];
					if(p%q!=0)
					{
						ans=max(ans,p);
						break;
					}
				}
				p=tt;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
