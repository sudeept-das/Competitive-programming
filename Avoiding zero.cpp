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
ll SubArraySum( vector<ll> arr , ll n ) 
{ 
    ll result = 0,i; 
  
    for (i=0; i<n; i++) 
    {
        result += (arr[i] * (i+1) * (n-i));
		cout<<arr[i]<<" "; 
  	}
    return result ; 
} 
ll hBit(ll n) 
{ 
   
    n |= n >> 1; 
  
    n |= n >> 2; 
  
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
  
    n = n + 1;  
    return (n >> 1); 
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
		ll n;
		cin>>n;
		ll i,j,p=0,nn=0,cn=0,cp=0,s=0;
		ll a;
		vector<ll> v;
		for(i=0;i<n;i++)
		{
			cin>>a;
			if(a<0)
			{
				nn=nn+abs(a);
				cn++;
			}
			else
			{
				p=p+a;
				cp++;
			}
			v.push_back(a);
		}
		if(p==nn)
			cout<<"NO\n";
		else if(p<nn)
		{
			cout<<"YES\n";
			sort(v.begin(),v.end());
			for(i=0;i<cn;i++)
			{
				cout<<v[i]<<" ";
				s=s+(v[i]);
			}
			while(i<v.size())
			{
				if(s+v[i]!=0)
				{
					cout<<v[i]<<" ";
					v.erase(v.begin()+i);
				}
				else
					i++;
			}
			for(i=cn;i<v.size();i++)
			{
				cout<<v[i]<<" ";
			}
			cout<<"\n";
		}
		else if(p>nn)
		{
			cout<<"YES\n";
			sort(v.begin(),v.end(),greater<ll>());
			for(i=0;i<cp;i++)
			{
				cout<<v[i]<<" ";
				s=s+v[i];
			}
			while(i<v.size())
			{
				if(s+v[i]!=0)
				{
					cout<<v[i]<<" ";
					v.erase(v.begin()+i);
				}
				else
					i++;
			}
			for(i=cp;i<v.size();i++)
			{
				cout<<v[i]<<" ";
			}
			cout<<"\n";
		}
			
	}
	return 0;
}
