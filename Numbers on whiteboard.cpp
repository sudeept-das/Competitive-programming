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
		ll n,k,i,s=0,a,b,f=0;
		cin>>n;
		vector<ll> av,bv;
		ll v[n+1];
		memset(v,false,sizeof(v));
		//cout<<"\n";
		if(n==1)
			cout<<"1\n";
		else if(n==2)
			cout<<"2\n1 2\n";
		else
		{
			a=n;
			b=n-2;
			av.push_back(a);
			bv.push_back(b);
			v[a]=true;
			v[b]=true;
			cout<<a<<" "<<b<<"\n";
			while(a>0)
			{
				cout<<a<<" "<<b<<"\n";
				
				
				if(f==1)
				{
					while(!v[a])
						a=a-1;
					v[a]=true;
					f=0;
				}
				else
				{
					b=(a+b)/2;
					while(!v[a])
						a=a-1;
					v[a]=true;
					f=1;
				}
				av.push_back(a);
				bv.push_back(b);
				
				if(a<=1 || b<=1)
					break;
				
			}
			b=(a+b)/2;
			cout<<b<<"\n";
			for(i=0;i<n-1;i++)
				cout<<av[i]<<" "<<bv[i]<<"\n";
		}
		
		
	}
	return 0;
}
