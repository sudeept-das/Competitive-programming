#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
// Declare a multimap 
multimap<int, string> MM; 
# define M_PI  3.14159265358979323846


const int M=1e9+7;
ll parent[200001];
vector<pair< ll, pair< ll , ll > > > gr;
ll n,d;
ll a[200001][5];

ll get(ll v)
{
	if(parent[v]==v)
		return v;
	else
		return parent[v]=get(parent[v]);
}

void uni(ll u,ll v)
{
	parent[get(u)]=get(v);
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	ll d,i,j,w=0,k,s,h,sw,hw,u,v,m,w1,w2;
	cin>>n>>d;
	for(i=0;i<n;i++)
		for(j=0;j<d;j++)
			cin>>a[i][j];
		
	
	for(m=0;m<=(1<<d)/2;m++)
	{
		vector <pair <ll,ll> > e;
		for(i=0;i<n;i++)
		{
			w=0;
			for(j=0;j<d;j++)
			{
				if((m>>j) & 1)
					w=w+a[i][j];
				else
					w=w-a[i][j];
			}
			e.push_back({w,i});	
		}
		
		s=min_element(e.begin(),e.end())->second;
		h=max_element(e.begin(),e.end())->second;
		for(i=0;i<n;i++)
		{
			w1=0;
			w2=0;
			for(j=0;j<d;j++)
			{
				w1=w1+abs(a[s][j]-a[i][j]);
				w2=w2+abs(a[h][j]-a[i][j]);
			}
			//cout<<s<<" "<<i<<" "<<w1<<"\n";
			//cout<<h<<" "<<i<<" "<<w2<<"\n";
			gr.push_back({w1,{s,i}});
			gr.push_back({w2,{h,i}});
		}
		
	}
	sort(gr.rbegin(),gr.rend());
	
	for(i=0;i<n;i++)
		parent[i]=i;
	w=0;

	for(i=0;i<gr.size();i++)
	{
		u=gr[i].second.first;
		v=gr[i].second.second;
		if(get(u)!=get(v))
		{
			uni(u,v);
			w=w+gr[i].first;
			//cout<<u<<" "<<v<<" "<<gr[i].first<<"\n";
		}
	}
	cout<<w<<"\n";
	
	return 0;
}
