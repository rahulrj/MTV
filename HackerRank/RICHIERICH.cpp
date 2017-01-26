https://www.hackerrank.com/challenges/richie-rich

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int s;
    int k;
    string n;
    cin>>s>>k;
    cin>>n;

    int a[100001]={0};

    int i=0,kcount=0;
    if(s==1){
        cout<<9<<endl;

    }
    else{
    while(i<s/2 && kcount<k){
        int j=n[i]-'0';
        int k=n[s-1-i]-'0';

        if(j!=k){
        int max=j>k?j:k;

            if(max==j){
                n[s-i-1]=max+'0';
                a[s-i-1]=1;
            }
            else{
                n[i]=max+'0';
                a[i]=1;
            }
            kcount+=1;
        }
        //cout<<n<<endl;

        i+=1;
    }

    i=0;

        //cout<<kcount<<" "<<n<<endl;
    while(i<s/2 && kcount<k){

       if(n[i]!='9'){
       if(a[i]==1 || a[s-i-1]==1){
            n[s-i-1]=9+'0';
            n[i]=9+'0';
            kcount+=1;
           //cout<<kcount<<"he"<<i<<endl;
       }
           else if(kcount+2<=k){
               n[s-i-1]=9+'0';
               n[i]=9+'0';
               kcount+=2;

           }

       }

       //cout<<kcount<<" "<<i<<" "<<s-i-1<<endl;

        i+=1;
    }





        if(s%2!=0 && kcount<k){
         n[s/2]='9';
         kcount+=1;
     }

    string n2=n;
    reverse(n.begin(),n.end());
    if(n==n2){
        cout<<n<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
    }



    return 0;
}
