#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef int ll;
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
		ll n,i,d=0;
		queue<ll> q;
		ll l=0,x,cnt=1,j=1;
		q.push(1);
		cin>>n;
		ll a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		while(!q.empty())
		{
			x=0;
			for(i=0;i<cnt;i++)
			{
				ll temp=q.front();
				q.pop();
				ll p=-1;
				while(j<n)
				{
					if(a[j]<p)
						break;
					p=a[j];
					q.push(a[j]);
					j++;
					x++;
				}
			}
			cnt=x;
			if(q.size()>0)
				d++;
		}
		cout<<d<<"\n";
	}
	return 0;
}
