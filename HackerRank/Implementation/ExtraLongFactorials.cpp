https://www.hackerrank.com/challenges/extra-long-factorials
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string addd(string prev,string res){
    string resnew=res;
    string ans="";

    int len1=prev.length();
    int reslen=resnew.length();
    int minlen=len1<reslen?len1:reslen;

    int carry=0;

    //cout<<minlen<<endl;

    for(int i=0;i<minlen;i++){
        int sum=carry+(prev[i]-'0')+(resnew[i]-'0');
        int rem=sum%10;
        carry=sum/10;
        ans+=std::to_string(rem);
    }

    //cout<<ans<<endl;

    for(int i=minlen;i<len1;i++){
        int sum=carry+(prev[i]-'0');
        cout<<"S1"<<sum<<endl;
        int rem=sum%10;
        carry=sum/10;
        ans+=std::to_string(rem);

    }

    for(int i=minlen;i<reslen;i++){
        int sum=carry+(resnew[i]-'0');
        //cout<<"S2"<<sum<<endl;
        int rem=sum%10;
        carry=sum/10;
        ans+=std::to_string(rem);
        cout<<"S"<<ans<<endl;
    }
    if(carry>0){
    	ans+=std::to_string(carry);
    }

    std::reverse(ans.begin(),ans.end());
    return ans;

    //cout<<ans<<endl;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    cin>>n;
    int n2=n-1;

    string s1 = std::to_string(n);
    string res=s1;

    while(n2!=1){

        string s2 = std::to_string(n2);
        int len1=s1.length();
        int len2=s2.length();
        string prev="";
        int carry=0;
        for(int i=len2-1;i>=0;i--){
            res="";
            for(int j=len1-1;j>=0;j--){
                res = std::string( len1-j, '0').append(res);
                int m1=s2[i]-'0';
                int m2=s1[j]-'0';
                int mul=carry+(m1*m2);
                int quo=mul;
                if(j!=0){
                    carry=mul/10;
                    quo=mul%10;
                }
                string quos=std::to_string(quo);
                std::reverse(quos.begin(), quos.end());
                res+=quos;
            }

            if(prev.length()>0){
                res=addd(prev,res);
            }
            prev=res;
        }

        s1=res;
        n2=n2-1;
    }


    cout<<res<<endl;




    return 0;
}
