#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,val[500],sz;
    cin >> n;
    val[0] = 1;
    sz = 1;
    for(int i = 11; i <= n; i++){
        int cary = 0;
        for(int j = 0; j < sz; j++){
            int pod = val[j]*i+cary;
            //cout<<"Pod"<<i<<" "<<pod<<endl;
            val[j] = pod%10;
            cary = pod/10;
        }
        //cout<<"Carry"<<cary<<" "<<sz<<endl;
        while(cary){
            val[sz] = cary%10;
            cary/=10;
            sz++;
        }
    }
    for(int i = sz-1; i>= 0; i--)cout << val[i];
    cout << endl;
    return 0;
}
