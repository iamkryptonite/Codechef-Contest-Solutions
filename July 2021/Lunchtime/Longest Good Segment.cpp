#include <bits/stdc++.h>
using namespace std;
#define vect vector
#define ll long long int

int main() 
{ 
  ios_base::sync_with_stdio(false);cin.tie(NULL);   
  #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin); 
  freopen("error.txt", "w", stderr); 
  freopen("output.txt", "w", stdout); 
  #endif  
  
  int t=1;cin>>t;

  while(t--){
    ll n,k,s;
    cin >> n >> k >> s;

    vect<ll> v(n+1);
    vect<ll> ans(n + 2),go(n + 2);


    // taking the array as input and simultaneously calculating the prefix sum 
    for(int i=1;i <= n;i++){
        cin >> v[i];
        v[i] += v[i-1];        
    }


    // for each index i storing the maximum index upto which sum is less than "S"
    // [ i , go(i) ) is largest the valid segment possible from index i
    for(int i=1;i<=n+1;i++){
        go[i] = upper_bound(v.begin(),v.end(), v[i-1] + s) - v.begin();
        ans[i] = i;
    }

    //**************************Binary lifting*********************
    // instead of making k jumps(segments) we break it into jumps of power of 2.
    // for each set bit we update our ans[i] with go[i]
    for(int b = 0;b<20;b++){
        if((k>>b)&1){
            // updating to new index for current set bit
            for(int i=1;i<=n+1;i++)
                ans[i] = ans[go[i]];
        }

        // main binary lifting code
        for(int i=1;i<=n+1;i++)
            go[i] = go[go[i]];
    }

    ll maxx = 0;
    // finally computing the maximum answer
    for(int i=1;i<=n;i++)
        maxx = max(maxx,ans[i]-i);
    cout<<maxx<<"\n";
    
    
  }      
  return 0; 
}