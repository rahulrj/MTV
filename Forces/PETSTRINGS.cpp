http://codeforces.com/problemset/problem/112/A

#include <iostream>
using namespace std;

main(){
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.length();i++){
        a[i]=tolower(a[i]);
        b[i]=tolower(b[i]);
    }
    cout<<a.compare(b);
}
