/*
*   author: kartik8800
*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int ll
using namespace std;

ll prefix[100001], suffix[100001];
vector<ll> vals;

void preprocess(int w, int n){
    prefix[0] = vals[0] - 1;
    for(int i = 1; i < w; i++){
        prefix[i] = prefix[i-1] + (vals[i] - 1);
    }
    suffix[w-1] = n - vals[w-1];
    for(int i = w-2; i >= 0; i--){
        suffix[i] = suffix[i+1] + (n - vals[i]);
    }
}

ll backCost(int i, int j, int loc, int n){
    if(i > j)return 0;
    if(vals[j] <= loc){
        int total = j - i + 1;
        ll cost = prefix[j] - ((i == 0)? 0 : prefix[i-1]);
        cost += total * (n - loc + 1);
        return cost;
    }
    else{
        int total = j - i + 1;
        ll cost = prefix[j] - ((i == 0)? 0 : prefix[i-1]);
        cost -= total*(loc - 1);
        return cost;
    }
}

int getFwdLoc1(int st, int ed, int loc, int n){

    while(st < ed){
        int mid = (st + ed) / 2;
        int op1 = vals[mid] - loc;
        int op2 = n - vals[mid] + loc;
        if(op1 < op2){
            st = mid + 1;
        }
        else ed = mid;
    }
    return st;
}

int getFwdLoc2(int st, int ed, int loc, int n){

    while(st < ed){
        int mid = (st + ed) / 2;
        int op1 = loc - vals[mid];
        int op2 = vals[mid] + (n - loc);
        if(op2 < op1){
            st = mid + 1;
        }
        else ed = mid;
    }
    return st;
}

ll fwdCost(int i, int j, int loc, int n){
    if(i > j)return 0;
    if(vals[j] <= loc){
        int total = j - i + 1;
        ll cost = suffix[i] - ((j + 1 == vals.size())? 0 : suffix[j+1]);
        cost -= total*(n - loc);
        return cost;
    }
    else{
        int total = j - i + 1;
        ll cost = suffix[i];
        cost += total*loc;
        return cost;
    }
}

signed main() {
   fast_io;
   ll t,n,m,x,i,j,k,q,p;
   cin >> t;
   //t = 1;
   for(int t_no = 0; t_no < t; t_no++){
        goog(t_no + 1); int w;
        cin >> w >> n;
        vals = vector<ll>(w);
        fr(0,w)cin >> vals[i];
        sort(all(vals));

        preprocess(w,n);

        ll answer = inf;

        for(int i = 0; i < w; i++){
            int x = getFwdLoc1(i+1, w - 1, vals[i], n);

            if(x == w-1){
                int op1 = vals[x] - vals[i];
                int op2 = n - vals[x] + vals[i];
                if(op1 < op2){
                    x++;
                }
            }

            ll temp = 0;

            if(i != w-1){
                temp = backCost(i+1, x-1, vals[i], n);
                temp += fwdCost(x, w-1, vals[i], n);
            }

            int y = getFwdLoc2(0, i-1, vals[i], n);

            if(y == i-1){
                int op1 = vals[y] + (n - vals[i]);
                int op2 = vals[i] - vals[y];
                if(op1 < op2){
                    y++;
                }
            }

            if(i != 0){
                temp += fwdCost(y, i-1, vals[i], n);
                temp += backCost(0, y-1, vals[i], n);
            }

            answer = min(answer, temp);
        }

        cout << answer << '\n';

   }
   return 0;
}
