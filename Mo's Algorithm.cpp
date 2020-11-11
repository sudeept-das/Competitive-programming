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
	ll n,i;
	cin>>n>>q;
	ll a[n];
	map<ll,ll> fc;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(fc.find(a[i])==fc.end())
			fc[a[i]]=0;
		fc[a[i]]++;
	}
	
	return 0;
}
