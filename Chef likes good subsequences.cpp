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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,q,i,ans=1,x,y,p;
		cin>>n>>q;
		ll a[n+2];
		a[0]=-1;
		a[n+1]=-1;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i==1)
				p=a[1];
			else if(p!=a[i])
			{
				p=a[i];
				ans++;
			}
				
		}
		
		while(q--)
		{
			cin>>x>>y;
			if(a[x]==y)
				cout<<ans<<"\n";
			else
			{
				if(x-1>0 && x+1<=n && a[x]==a[x-1] && a[x]==a[x+1])
				{
					if(y!=a[x])
						ans+=2;
				}
				else if(x-1>0 && x+1<=n && a[x]==a[x-1] && a[x]!=a[x+1])
				{
					if(y!=a[x])
						ans+=1;
					if(y==a[x+1])
						ans--;
				}
				else if(x-1>0 && x+1<=n && a[x]!=a[x-1] && a[x]==a[x+1])
				{
					if(y!=a[x])
						ans+=1;
					if(y==a[x-1])
						ans--;
				}
				else if(x-1>0 && x+1<=n && a[x]!=a[x-1] && a[x]!=a[x+1])
				{
					if(y==a[x-1] && y==a[x+1])
						ans-=2;
					else if(y==a[x-1] && y!=a[x+1])
						ans-=1;
					else if(y!=a[x-1] && y==a[x+1])
						ans-=1;
				}
				else if(x-1==0 && x+1<=n && a[x]==a[x+1])
				{
					if(y!=a[x-1])
						ans+=1;
				}
				else if(x-1==0 && x+1<=n && a[x]!=a[x+1])
				{
					if(y==a[x+1])
						ans-=1;
				}
				else if(x-1>0 && x==n && a[x]==a[x-1])
				{
					if(y!=a[x-1])
						ans+=1;
				}
				else if(x-1>0 && x==n  && a[x]!=a[x-1])
				{
					if(y==a[x-1])
						ans-=1;
				}
				cout<<ans<<"\n";
				a[x]=y;
			}
		}
	}
	return 0;
}
