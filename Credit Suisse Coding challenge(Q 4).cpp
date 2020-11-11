#include<bits/stdc++.h>
using namespace std;
double maximumExpectedMoney(int n, int m, double p[], double x[], double y[] )
{
    //Complete the maximumExpectedMoney function.
    int i,pos,v[n];
    double a[n],ans,mv=0.00;
    for(i = 0; i < n; i++)
    {
        //a[i]=float(float(float(p[i])*float(x[i]))-float(float(float(one)-float(p[i]))*float(y[i])));
        a[i]=(p[i]*x[i])-((1.00-p[i])*y[i]);
        v[i]=0;
    }
    ans=0.00;
    while(m--)
    {
    	pos=-1;
    	mv=0.00;
    	for(i=0;i<n;i++)
	    {
	        if(a[i]>mv && v[i]==0)
	        {
	        	pos=i;
	        	mv=a[i];
			}
	    }
	    //cout<<pos<<"\n";
	    if(pos==-1)
	    	break;
	    v[pos]=1;
	    if(a[pos]<=0.00)
	    	break;
	    else
	    	ans=ans+a[pos];
	}
	cout<<fixed<<setprecision(2);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;

    cin >> n >> m;
    double p[n], x[n], y[n];

    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < n; i++)
        cin >> y[i];

    double result=maximumExpectedMoney(n,m,p,x,y);

    // Do not remove below line
    cout << result << endl;
    // Do not print anything after this line

    return 0;
}
