#include <iostream>
using namespace std;


//123434
int count=0;
void findc(int prev,string sparam,string res){
    for(int i=1;i<=sparam.length();i++){
        //cout<<"sp"<<sparam<<endl;
        if(i==sparam.length()){
            count+=1;
            cout<<count<<" "<<res<<endl;
        }
	    string sub=sparam.substr(0,i);
	    int subint=stoi(sub);
	    if(subint<prev){
	        continue;
	    }
	    res=res+"+"+sub;
	    string sub2=sparam.substr(i);
	    findc(subint,sub2,res);
	}
}

int main() {
	//code
	int n;
	cin>>n;
	string s;
	cin>>s;
	findc(0,s,"");


	return 0;
}
