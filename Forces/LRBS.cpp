http://codeforces.com/contest/5/problem/C

#include <iostream>
using namespace std;

int main() {

    string s;
    cin>>s;

    int sum=0;
    int res[1000001]={0};
    int max=0,supermax=0;
    int freq[1000001]={0};
    for(int i=0;i<s.length();i++){
        char c=s.at(i);
        if(c=='('){
            res[i]=-1;
            sum=sum+1;
            //cout<<res[i]<<endl;
        }

        if(c==')'){
            if(sum>0){
                sum=sum-1;
                res[i]=2;
                //cout<<res[i]<<" "<<sum<<endl;
            }else{
                res[i]=0;
                //cout<<res[i]<<" "<<sum<<endl;

            }
        }
    }

    // for(int i=0;i<s.length();i++)
    // cout<<res[i]<<endl;

    for(int i=0;i<1000001;i++){
        if(res[i]==2){
            max=max+2;
            supermax=(max>supermax?max:supermax);
            freq[max]++;
        }
        if(res[i]==0){
            max=0;
        }

    }

    if(supermax==0){
        freq[supermax]=1;
    }
    cout<<supermax<<" "<<freq[supermax]<<endl;


	return 0;
}
