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
	
		string s;
		cin>>s;
		ll i,n;
		n=s.length();
		ll dp[n];
		dp[0]=dp[1]=1;
		for(i=0;i<n;i++)
		{
			if(s[i]=='w' || s[i]=='m')
			{
				cout<<0;
				return 0;
			}
		}
		for(i=2;i<=n;i++)
		{
			if(i>=2 && (s[i-1]=='u' || s[i-1]=='n') && s[i-1]==s[i-2])
				dp[i]=(dp[i-1]+dp[i-2])%1000000007;
			else
				dp[i]=dp[i-1];
			if(s[i-1]=='w' || s[i-1]=='m')
			{
				dp[n]=0;
				break;
			}
		}
		cout<<dp[n];
	return 0;
	
	
}
