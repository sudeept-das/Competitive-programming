#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pi;

vector<pi> pr;

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
	ll t,j,i,c=0;
	cin>>t;
	c=1ll*t*t;
	for(j=1;j<=t;j++)
	{
		ll n;
		cin>>n;
		vector<int> v(n);
		for(i=0;i<n;i++)
			cin>>v[i];
		reverse(v.begin(),v.end());
		if(is_sorted(v.begin(),v.end())){
			pr.emplace_back(v[0],v[n-1]);
		}
	}
	sort(pr.begin(),pr.end());
	for(i=0;i<pr.size();i++)
	{
		c-=pr.end()-lower_bound(pr.begin(),pr.end(),pi(pr[i].second,-1));
	}
	cout<<c;
	return 0;
}
