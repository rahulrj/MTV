#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100005;
typedef long long LL;
int n, k, sa[MAX_N], rk[MAX_N], lcp[MAX_N], tmp[MAX_N];

bool compare_sa(int i, int j) {
    if (rk[i] != rk[j]) return rk[i] < rk[j];
    int ri = i + k <= n ? rk[i + k] : -1;
    int rj = j + k <= n ? rk[j + k] : -1;
    return ri < rj;
}

void construct_sa(const string &S, int *sa) {
    n = S.length();
    for (int i = 0; i <= n; i++) {
        sa[i] = i;
        rk[i] = (i < n ? S[i] : -1);
    }

    for (k = 1; k <= n; k *= 2) {
        sort(sa, sa + n + 1, compare_sa);

        tmp[sa[0]] = 0;
        for (int i = 1; i <= n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i <= n; i++) rk[i] = tmp[i];
    }
}

void construct_lcp(const string &S, int *sa, int *lcp) {
    n = S.length();
    for (int i = 0; i <= n; i++) rk[sa[i]] = i;

    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; i++) {
        int j = sa[rk[i] - 1];

        if (h > 0) h--;
        for (; i + h < n && j + h < n; h++) if (S[i + h] != S[j + h]) break;

        lcp[rk[i] - 1] = h;
    }
}

string S;

void solve(LL k) {
    n = S.length();
    construct_sa(S, sa);
    construct_lcp(S, sa, lcp);

    //for(int i=1;i<=n;i++){
      //  cout<<sa[i]<<" ";
    //}
    //cout<<endl;
    //for(int i=1;i<=n;i++){
      //  cout<<lcp[i]<<" ";
    //}
    //cout<<endl;

    int flag=1,prev=0,res=0;
    int len=n-sa[1];
    res=(len*(len+1))/2;

    //cout<<"yo"<<res<<endl;

    if(res>=k){
    int cnt;
    int m=1;
    while(cnt<k){

        for(int i=0;i<m;i++){
            cnt+=1;
            if(cnt==k){
                cout<<S[sa[1]+i];
                break;
            }
        }
        m+=1;
    }
    }

    else{
    prev=res;
    //cout<<"prev"<<prev<<endl;
    int ii=0;

    for (int i = 1; i < n; i++) {
        ii=i;
        int len=n-sa[i+1];
        //cout<<"len"<<(lcp[i]*lcp[i]+1)/2<<endl;
        res=res+(len*(len+1))/2 - (lcp[i]*(lcp[i]+1))/2;
        //cout<<"Res1"<<res<<endl;
        if(res>=k){
            break;
        }
        prev=res;

    }


    int rem=k-prev;
   // cout<<"remmm"<<rem<<endl;

    //int lens=n-sa[i+1];
    int kk=0;
    int cnt;
    int m=1;
    while(cnt<rem){

        for(int i=0;i<lcp[ii]+m;i++){
            cnt+=1;
            if(cnt==rem){
                cout<<S[sa[ii+1]+i];
                break;
            }
        }
        m+=1;
    }

    }
    cout<<endl;


}
int main(void) {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        LL k;
        cin >> S >> k;
        solve(k);
    }
    return 0;
}
