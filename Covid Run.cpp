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
		ll n,k,x,y,i,f=0;
		cin>>n>>k>>x>>y;
		ll in[n];
		for(i=0;i<n;i++)
			in[i]=0;
		i=x;
		while(in[i]==0)
		{
		
			//cout<<i<<" ";
			in[i]=1;
			if(y==i)
			{
				f=1;
				break;
			}
			i=i+k;
			if(i>n-1)
			{
				i=i%n;
			}
		}
		/*cout<<"\n";
		for(i=0;i<n;i++)
			cout<<in[i]<<" ";
		*/
		if(f==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
