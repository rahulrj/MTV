#include <iostream>
using namespace std;


//123434
int count=0;
void findc(int prev,string sparam,string res){
    for(int i=1;i<=sparam.length();i++){
	    string sub=sparam.substr(0,i);
	    int subint=stoi(sub);
	    if(subint<=prev || sub[0]=='0'){
	        continue;
	    }
	    string res2=res+"+"+sub;
	   // cout<<"sub"<<sub<<" "<<i<<" "<<prev<<" "<<res2<<endl;

	    if(i==sparam.length()){
	        count=count%1000000007;
            count+=1;
            //cout<<count<<" "<<res2<<endl;
            return;
        }
	    string sub2=sparam.substr(i);
	    findc(subint,sub2,res2);
	}
}

int main() {
	//code
	int n;
	cin>>n;
	string s;
	cin>>s;
	findc(0,s,"");
	cout<<count<<endl;


	return 0;
}
