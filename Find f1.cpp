#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
	ll n,i,m=0,pj,c=0,fn,j,f=1,d;
	cin>>n>>fn;
	ll a[n];
	for(i=n;i>1;)
	{
		
		else if(i>7 && fn%128==0)
		{
			fn=fn/128;
			i=i-7;
		}
		else if(i>6 && fn%64==0)
		{
			fn=fn/64;
			i=i-6;
		}
		else if(i>5 && fn%32==0)
		{
			fn=fn/32;
			i=i-5;
		}
		else if(i>4 && fn%16==0)
		{
			fn=fn/16;
			i=i-4;
		}
		else if(i>3 && fn%8==0)
		{
			fn=fn/8;
			i=i-3;
		}
		else if(i>2 && fn%4==0)
		{
			fn=fn/4;
			i=i-2;
		}
		else if(fn%2==0)
		{
			fn=fn/2;
			i--;
		}
		else
		{
			fn=fn+1000000007;
		}
	}
	cout<<fn;
	return 0;
}
