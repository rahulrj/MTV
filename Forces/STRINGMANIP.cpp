http://codeforces.com/problemset/problem/159/C

#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000];
int n,i,k,m,x;
char c;
string s,a;
int main()
{
    cin>>k>>a;
    for(i=0;i<k;i++)s+=a;
    m=s.size();
    for(i=0;i<m;i++)
    {
        v[s[i]].push_back(i);
    }
    cin>>n;
    while(n--)
    {
        cin>>x>>c;
        s[v[c][x-1]]=0;
        v[c].erase(v[c].begin()+x-1);
    }
    for(i=0;i<m;i++)if(s[i])cout<<s[i];
    //cout<<ans<<endl;
    return 0;
}
