http://codeforces.com/problemset/problem/278/B

#include <iostream>
using namespace std;
string s,a;
int main() {
    int n;cin>>n;
    for(int i=0;i<n;i++)
        cin>>a,s+=a+"#";

    cout<<s<<endl;
    for(int i='a';i<='z';i++)
        if(s.find(i)==-1)
            return cout<<(char)i, 0;
    for(int i='a';i<='z';i++)
        for(int j='a';j<='z';j++){
            a=i;a+=j;
            if(s.find(a)==-1)
                return cout<<a,0;

        }
    return 0;
}
