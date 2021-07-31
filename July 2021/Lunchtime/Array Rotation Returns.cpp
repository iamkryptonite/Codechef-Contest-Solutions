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

ll power(ll x,int y,int p = mod)
{
  ll res = 1;
  while(y > 0)
  {
    if(y & 1)
      res = res * x %p; 
    y = y>>1;
    x = x * x % p;
  }
  return res;
}

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
void solve(){
  
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
    vect<int> a(n),b(n);
    inp(a,n);inp(b,n);
    vector<int> c(n);
    vect<int> p(n);
    iota(p.begin(),p.end(),0);
    for(int i=0;i<n;i++){
        int m = n;
        vector<int> tmp;
        for(int j = 0;j < p.size();j++){
            int x = (a[i]+b[p[j]])%n;
            if(x<m){
                m = x;
                tmp.clear();
                tmp.push_back((p[j]+1)%n);
            }else if(x==m)
                tmp.push_back((p[j]+1)%n);
        }
        c[i] = m;
        p = tmp;        
    }
    for(int i:c)
        cout<<i<<" ";
    cout<<"\n";


    
  }      
  return 0; 
}