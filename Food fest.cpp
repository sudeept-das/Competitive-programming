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
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,j,k,m=-100000000000,n,r,c,p;
	cin>>n;
	ll arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
    vector<vector<ll> > dp(n,vector<ll> (n,0));
    for(i=0;i<n;i++)
    {
    	for(j=i+1;j<n;j++)
    	{
    		dp[i][j]=arr[i]*arr[j];
		}
	}
	for(j=n-2;j>=0;j--)
	{
		r=j;
		c=n-1;
		ll max_so_far = dp[r][c]; 
   		ll curr_max = dp[r][c];
   		r++;
   		c--;
		while(r<c)
		{
			curr_max = max(dp[r][c], curr_max+dp[r][c]); 
        	max_so_far = max(max_so_far, curr_max); 
			r++;
			c--;
		}
		m=max(m,max_so_far);
	}
	for(j=n-1;j>=1;j--)
	{
		p=0;
		r=0;
		c=j;
		ll max_so_far = dp[r][c]; 
   		ll curr_max = dp[r][c];
   		r++;
   		c--;
		while(r<c)
		{
			curr_max = max(dp[r][c], curr_max+dp[r][c]); 
        	max_so_far = max(max_so_far, curr_max); 
			r++;
			c--;
		}
		m=max(m,max_so_far);
	}
    cout<<m;
	return 0;
}
