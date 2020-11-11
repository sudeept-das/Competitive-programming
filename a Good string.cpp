#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll count(string s,char c)
{
	ll i,cnt=0;
	for(i=0;i<s.length();i++)
		if(s[i]==c)
			cnt++;
	return cnt;
}
ll solve(string s, char c)
{
	if(s.size()==1)
	{
		if(s[0]!=c)
			return 1;
		else
			return 0;	
	}		
	ll mid=s.size()/2;
	ll cntl= solve(string(s.begin(), s.begin()+mid),c+1);
	cntl+=mid-count(string(s.begin()+mid,s.end()),c);
	ll cntr=solve(string(s.begin()+mid,s.end()),c+1);
	cntr+=mid-count(string(s.begin(),s.begin()+mid),c);
	return min(cntr,cntl); 
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		string s;
		cin>>s;
		cout<<solve(s,'a')<<"\n";
	}
	return 0;
}
