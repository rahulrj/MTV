http://codeforces.com/problemset/problem/514/C

#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
vector<string> A[600005];
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	string s;
		while(n--)
		{
			cin>>s;
			A[s.length()].push_back(s);
		}
		while(m--)
		{
            cin>>s;
			if(mp[s]==1) cout<<"YES"<<endl;
			else if(mp[s]==2) cout<<"NO"<<endl;
			else
			{
				int counter=0;
				int len=s.length();
				int sizee=A[len].size();
				cout<<sizee<<endl;
				for(i=0;i<sizee;i++)
				{
					counter=0;
					for(j=0;j<len;j++)
					{
						if(A[len][i][j]!=s[j]) counter++;
						if(counter>1) break;
					}
					if(counter==1)
					{
						cout<<"YES"<<endl;
						mp[s]=1;
						break;
					}
				}
				if(counter!=1)
				{
					cout<<"NO"<<endl;
					mp[s]=2;
				}
			}
		}
	return 0;
}
