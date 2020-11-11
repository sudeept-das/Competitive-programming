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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
		ll n,k,i;
		cin>>n>>k;
		string s;
		cin>>s;
		ll w=0;
		for(i=0;i<s.length();i++)
			if(s[i]=='W')
				w++;
		if(w==0)
		{
			cout<<max((2*k)-1,0)<<"\n";
			continue;
		}
		w=w+k;
		if(w>=n)
		{
			cout<<(2*n)-1<<"\n";
			continue;
		}
		ll l=0;
		vector<ll> v;
		for(i=0;i<n;i++)
		{
			if(s[i]=='L')
				l++;
			else
			{
				v.push_back(l);
				l=0;
			}
		}
		if(l!=0)
			v.push_back(l);
		if(s[0]=='L')
			v.erase(v.begin());
		if(s[n-1]=='L')
			v.erase(v.begin()+v.size()-1);
		sort(v.begin(),v.end());
		l=0;
		for(i=0;i<v.size();i++)
		{
			if(l+v[i]>k)
				break;
			l=l+v[i];
		}
		l=v.size()-i;
		cout<<(2*w)-l-1<<"\n";
	}
	return 0;
}
