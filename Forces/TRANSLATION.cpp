http://codeforces.com/problemset/problem/41/A

#include<bits\stdc++.h>
using namespace std;
main(){string s,t;
  cin>>s>>t;
  reverse(s.begin(),s.end());
  cout<<(s==t?"YES":"NO");
}
