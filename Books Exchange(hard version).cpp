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
	ll n,m,i,j,c=0,mi=0,mj=0,f=0,k,l;
	cin>>n>>m;
	string s[501];
	vector<vector<bool> > pl(n, vector<bool> (m,false));
	for(i=0;i<n;i++)
		cin>>s[i];
	
	for(i=1;i<(n-1);i++)
	{
		for(j=1;j<(m-1);j++)
		{
			if(s[i][j]=='*' && s[i-1][j]=='*' && s[i+1][j]=='*' && s[i][j-1]=='*' && s[i][j+1]=='*')
			{
				mi=i;
				mj=j;
				for(k=mi;k>=0;k--)
				{
					if(s[k][mj]=='.')
						break;
					else
						pl[k][mj]=true;
				}
				for(k=mi;k<n;k++)
				{
					if(s[k][mj]=='.')
						break;
					else
						pl[k][mj]=true;
				}
				for(k=mj;k>=0;k--)
				{
					if(s[mi][k]=='.')
						break;
					else
						pl[mi][k]=true;
				}
				for(k=mj;k<n;k++)
				{
					if(s[mi][k]=='.')
						break;
					else
						pl[mi][k]=true;	
				}
				for(k=0;k<n;k++)
				{
					for(l=0;l<m;l++)
					{
						if(pl[k][l]!=(s[k][l]=='*'))
						{
		    				cout<<"NO\n";
		    				return 0;
						}
					}
				}
				cout<<"YES\n";
				return 0;
			}
		}
	}
	
	cout<<"NO\n";
	return 0;
}


