#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k,i,s=0;
		cin>>n>>k;
		ll a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n,greater<ll>());
		s=a[0];
		for(i=1;i<=k;i++)
			s=s+a[i];
		cout<<s<<"\n";
	}
	return 0;
}
