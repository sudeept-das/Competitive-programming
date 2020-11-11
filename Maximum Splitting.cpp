#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i,j,maxn=16;
	vector<ll> ans(maxn,-1);
	vector<ll> v{4 , 6, 9};
	for(i=0;i<maxn;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i>=v[j] && ans[ i-v[j] ]!=-1){
				ans[i] = max(ans[i], ans[i - j] + 1);
			}
		}
	}
	ll q;
	cin>>q;
	while(q--)
	{
		ll n;
		cin>>n;
		if(n<maxn){
			cout<<ans[n]<<"\n";
		}
		else
		{
			ll k=(n-maxn)/4+1;
			cout<<k+ans[n-(4*k)]<<"\n";
		}
	}
	return 0;
}
