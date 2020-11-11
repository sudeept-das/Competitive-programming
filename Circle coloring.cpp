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
		ll n,i;
		cin>>n;
		ll a[n],b[n],c[n];
		ll v,s;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			cin>>b[i];
		for(i=0;i<n;i++)
			cin>>c[i];
		for(i=0;i<n;i++)
		{
			if(i==0)
			{
				cout<<a[0]<<" ";
				v=a[0];	
				s=v;
			}
			else if(i==n-1)
			{
				if(v!=a[i] && a[i]!=s)
				{
					v=a[i];
					cout<<v<<" ";
				}
				else if(v!=b[i] && b[i]!=s)
				{
					v=b[i];
					cout<<v<<" ";
				}
				else if(v!=c[i] && c[i]!=s)
				{
					v=c[i];
					cout<<v<<" ";
				}		
			}
			else if(v!=a[i])
			{
				v=a[i];
				cout<<v<<" ";
			}
			else if(v!=b[i])
			{
				v=b[i];
				cout<<v<<" ";
			}
			else if(v!=c[i])
			{
				v=c[i];
				cout<<v<<" ";
			}	
		}
		cout<<"\n";
	}
	
	return 0;
	
	
}
