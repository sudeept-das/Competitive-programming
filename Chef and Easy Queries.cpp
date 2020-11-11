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
		ll n,k,i,s=0,c=0,s1=0;
		cin>>n>>k;
		ll a[n+1];
		for(i=1;i<=n;i++)
			cin>>a[i];
		for(i=1;i<=n;i++)
		{
			s=s+a[i];
			s=s-k;
			c++;
			if(s<0)
				break;
		}
		if(s>0)
			c=c+(s/k)+1;
		cout<<c<<"\n";  
	}
	return 0;
}
