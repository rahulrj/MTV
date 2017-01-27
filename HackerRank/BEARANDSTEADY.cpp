#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    string s;
    cin>>s;
    int freq[26]={0};
    int steady=n/4;
    int sum=0;

    for(int i=0;i<n;i++){
        freq[s[i]]++;
    }

    freq['A']=freq['A']-steady; sum+=freq['A']>0?freq['A']:0;
    freq['T']=freq['T']-steady; sum+=freq['T']>0?freq['T']:0;
    freq['G']=freq['G']-steady; sum+=freq['G']>0?freq['G']:0;
    freq['C']=freq['C']-steady; sum+=freq['C']>0?freq['C']:0;

    for(int i=0;i<n;i++){
        string sub="";
        for(int j=sum;j<=n;j++){
            if(sub!=""){
                sub+=s[j];
            }
            else{
                sub=s.substr(i,j);
            }
        }
    }


    return 0;
}
