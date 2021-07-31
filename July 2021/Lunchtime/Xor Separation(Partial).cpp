#include <bits/stdc++.h>
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int
#define peque priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>

#define srt(x) sort(x.begin(),x.end())
#define rsrt(x) sort(x.begin(),x.end(),greater<int>)
#define rev(x) reverse(x.begin(),x.end());
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rept(c,s) for(auto c:s)
#define inp(v,n) for(int i=0;i<n;i++) cin>>v[i];
#define disp(v) for(auto i:v) cout<<i<<" ";cout<<"\n";
#define all(x) x.begin(),x.end();


const int mod = 1e9+7;
const int N = 1e6;

vect<vector<ll>> dp;
vect<ll> xr,p;

int solve(int x,int y,int n,ll prev=0){
    if(x==n)
        return 1;

    if(dp[x][y]!=-1) return dp[x][y];
    dp[x][y] = 0;

    for(int i=x;i<n;i++){
        ll d = p[y];
        if((xr[i]^prev)%d==0)
            dp[x][y] += solve(i+1,y+1,n,xr[i]);
    }

    return dp[x][y];
}

int main() 
{ 
  ios_base::sync_with_stdio(false);cin.tie(NULL);   
  #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin); 
  freopen("error.txt", "w", stderr); 
  freopen("output.txt", "w", stdout); 
  #endif  
  int t=1;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vect<ll> v(n);
    inp(v,n);
    dp.assign(n,vector<ll>(n,-1));
    xr = v;
    for(int i=1;i<n;i++)
        xr[i] = xr[i-1]^xr[i];
    p.assign(n,0);
    p[0] = 1;
    for(int i=1;i<n;i++)
        p[i] = (2*p[i-1])%mod;
    solve(0,0,n); 
    cout<<dp[0][0]<<"\n";   
  }      
  return 0; 
}