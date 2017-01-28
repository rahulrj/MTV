https://www.hackerrank.com/challenges/sherlock-and-valid-string

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin>>s;

    int freq[26];
    int freq2[100005]={0};
    int len=s.length();
    for(int i=0;i<len;i++){
        freq[s[i]-'a']++;
    }



    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            freq2[freq[i]]++;
        }
    }

    int flag=0;
    int first=0;
    int second=0;
    int secondfreq=0,firstfreq=0;
    for(int i=0;i<100005;i++){
        if(flag==0 && freq2[i]!=0){
            first=i;
            flag+=1;
            firstfreq=freq2[i];
            continue;
        }

        if(flag==1 && freq2[i]!=0){
            flag+=1;
            second=i;
            secondfreq=freq2[i];
            continue;
        }

        if(freq2[i]!=0){
            flag+=1;
        }
    }

    if(flag==0 || flag==1){
        cout<<"YES"<<endl;
    }

    if(flag==2){


        if(first>1 && second>1){
            cout<<"NO"<<endl;
        }
        else if((first==1 && firstfreq>1) || (second==1 && secondfreq>1)){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }

    if(flag>2){
        cout<<"NO"<<endl;
    }


    return 0;
}
