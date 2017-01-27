#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,freq[4];
string s,ch = "ATCG";
ll pos(ll j){
    for(ll i=0;i<4;i++){
        if(s[j] == ch[i]) return i;
    }
    return 0;
}
bool is_ok(){
    for(int i=0;i<4;i++){
        if(freq[i] > n/4) return false;
    }
    return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin>>n>>s;
    memset(freq,0,sizeof(freq));
    for(ll i=0;i<n;i++){
        ++freq[pos(i)];
    } 
    if(is_ok()) {
        cout<<0<<endl;
        return 0;
    }
    ll ans = n,j = 0;
    for(ll i=0;i<n;i++){
        while(j<n&&!is_ok()){
            --freq[pos(j++)];
        }
        if(is_ok()) ans = min(ans,j-i) ;
        ++freq[pos(i)];
    }
    cout<<ans<<endl;
    return 0;
}
