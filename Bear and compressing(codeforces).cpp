#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<string> v;
void printAllKLengthRec(char set[], string prefix, ll n, ll k)
{
	if(k==0)
	{
		v.push_back(prefix);
		return;
	}
	for(ll i=0;i<n;i++)
	{
		string newPrefix;
		
		newPrefix = prefix +set[i];
		
		printAllKLengthRec(set,newPrefix,n,k-1);
	}
}
int main()
{
	ll n,q,i,j,c=0,k;
	string s1,s2;
	char s[]={'a','b','c','d','e','f'};
	map<string,string> m;
	
	cin>>n>>q;
	printAllKLengthRec(s,"",6,n);
	while(q--)
	{
		cin>>s1>>s2;
		m[s1]=s2;
	}
	for(i=0;i<v.size();i++)
	{
		while(v[i].size()>=2 && m.find(v[i].substr(0,2))!=m.end())
			v[i]=m[ v[i].substr(0,2) ]+v[i].substr(2,v[i].length()-2);
	}
	for(i=0;i<v.size();i++)
	{
		if(v[i]=="a")
			c++;
	}
	cout<<c;
	return 0;
}
