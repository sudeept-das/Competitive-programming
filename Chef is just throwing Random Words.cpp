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
	/*
	ll c=0,i;
	for(i=1;i<=100001;c++)
		i=i*2;
	cout<<c<<"\n";*/
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll i,a[n],b,dp[60],j,ans=0;
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			b=a[i];
			j=0;
			while(b>0)
			{
				if(b%2==1)
					dp[j]++;
				b=b/2;
				j++;
			}
		}
		for(i=0;i<60;i++)
		{
			if(i==0)
			{
				j=1;
				if(dp[0]>0)
					ans=ans+j;
				j=2*j;
			}
			else   
			{
				dp[i]=dp[i]+floor(dp[i-1]/2);
				if(dp[i]>0)
					ans=ans+j;
				j=2*j;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
