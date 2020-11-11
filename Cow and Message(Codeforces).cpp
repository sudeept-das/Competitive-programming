#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n,i,j,m,dp2[27][27],dp1[27],c;
string s,s1,s2;
int main()
{
	m=0;
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		c=(int)(s[i]-'a');
		for(j=0;j<27;j++)
			dp2[j][c]=dp2[j][c]+dp1[j];
		dp1[c]++;
		m=max(m,dp1[c]);
	}
	for(i=0;i<27;i++)
	{
		for(j=0;j<27;j++)
		{
			m=max(m,dp2[i][j]);
			//cout<<dp2[i][j]<<"\t";
		}
		//cout<<"\n";
	}
	cout<<m;
	return 0;
}
