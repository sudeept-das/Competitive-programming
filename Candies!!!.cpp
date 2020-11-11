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

int main() 
{
	ll i,n,q,l,r;
	cin>>n;
	ll a[n+1],psum[n+1];
	memset(psum,0,sizeof(psum));
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		psum[i]=psum[i-1]+a[i];
	}
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		cout<<(psum[r]-psum[l-1])/10<<"\n";
	}
	return 0;
}
