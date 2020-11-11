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
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--)
	{
		ll i,n,l,s,e,h;
		cin>>n>>e;
		ll a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		l=0;
		h=n-1;
		long double p1=0, p2=(float)e;
		ll s1=1;
		ll s2=1;
		long double time=0,t1,t2;
		while(l<=h)
		{
			if(abs(a[l]-p1)/s1<abs(a[h]-p2)/s2)
			{
				t2=abs(a[l]-p1)/s1;
				p2=p2-(t2*s2);
				p1=a[l];
				s1=s1+1;
				l++;
				time=time+t2;
			}
			else if(abs(a[l]-p1)/s1>abs(a[h]-p2)/s2)
			{
				t2=abs(a[h]-p2)/s2;
				p1=p1+(t2*s1);
				p2=a[h];
				s2=s2+1;
				h--;
				time=time+t2;
			}
			else if(abs(a[l]-p1)/s1==abs(a[h]-p2)/s2)
			{
				t2=abs(a[h]-p2)/s2;
				p2=a[h];
				s2=s2+1;
				p1=a[l];
				s1=s1+1;
				time=time+t2;
				l++;
				h--;
			}			
			//cout<<p1<<" ";
			//cout<<p2<<"\n";
			//cout<<fixed<<setprecision(15)<<time<<"\n";
		}
		if(p1!=p2)
			time=time+(p2-p1)/(s1+s2);
		cout<<fixed<<setprecision(15)<<time<<"\n";
		//cout<<"\n";
	}
	return 0;
}
