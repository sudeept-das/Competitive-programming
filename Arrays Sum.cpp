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
	
	ll t;
	cin>>t;
	while(t--)
	{
		ll i,n,k,c=1,l,nz=0,f=0;
		cin>>n>>k;
		ll a[n];
		set<ll> s;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			s.insert(a[i]);
			if(a[i]==0)
				f=1;
		}
		//cout<<c<<"\n";
		c=s.size();
		if(c==1 && k==1)
			cout<<"1";
		else if(c>1 && k==1)
			cout<<"-1";
		else 
		{
			c=c-1;
			l=c/(k-1);
			if(c%(k-1)==0)
			{
				if(l==0)
					l=1;
				cout<<l;
			}
			else
				cout<<l+1;
		}
		
		cout<<"\n";
	}
	
	return 0;
	
	
}
