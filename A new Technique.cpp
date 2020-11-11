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
	ll t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ll mat1[n][m],mat2[m][n],p[n],i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				cin>>mat1[i][j];
		}
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				cin>>mat2[i][j];
		ll f=0,k;
		for(k=0;k<n;k++)
		{
			f=0;
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					if(mat1[k][0]==mat2[i][j])
					{
						f=1;
						p[j]=k;
						break;
					}
				}
				if(f==1)
					break;
			}
			
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cout<<mat1[p[i]][j]<<" ";
			}
			cout<<"\n";
		}
	}

	return 0;
}
