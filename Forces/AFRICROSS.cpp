#include<iostream>
char a[101][101];
int i,j,l,n,m,p;
main(){
	std::cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			std::cin>>a[i][j];

	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++){
		p=0;
		for(l=1;l<=n;l++)
			if(l!=i)
				if(a[l][j]==a[i][j])
					p++;
		for(l=1;l<=m;l++)
			if(l!=j)
				if(a[i][j]==a[i][l])p++;
		if(!p)
			std::cout<<a[i][j];
	}
}
