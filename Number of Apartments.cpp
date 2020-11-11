#include<bits/stdc++.h>
using namespace std;
typedef int ll;

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n;
		m=n%3;
		if(m==0)
			cout<<(ll)n/3<<" 0 0\n";
		else if(m==1)
		{
			if(n<=7)
			{
				if(n%7!=0)
					cout<<"-1\n";
				else if(n%7==0)
					cout<<"0 0 1\n";
			}
			else
			{
				m=n-1;
				m=m/3;
				m=m-3;
				cout<<m<<" 2 0\n";
			}	
		}	
		else if(m==2)
		{
			if(n<=7)
			{
				if(n%5!=0)
					cout<<"-1\n";
				else if(n%5==0)
					cout<<"0 1 0\n";
			}
			else
			{
				m=n-2;
				m=m/3;
				m=m-1;
				cout<<m<<" 1 0\n";
			}	
		}	
	}
	return 0;
}
