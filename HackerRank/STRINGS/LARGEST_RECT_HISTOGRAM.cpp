#include <iostream>
using namespace std;

int getMaxArea(int *hist,int n){

    int i=0;
    int max_area=0;
    while(i<n){

        int j=1,k=1;
        while(i+j<n && hist[i+j]>=hist[i+j-1]){
            j++;
        }
        while(i-k>=0 && hist[i-k]>=hist[i-k+1]){
            k++;
        }

        int area=hist[i]*(j+k-1);
        if(area>max_area){
            max_area=area;
        }
        i+=1;

    }
    return max_area;
}

int main()
{
	int hist[] = {2,1,5,6,2,3};
	int n = sizeof(hist)/sizeof(hist[0]);
	cout << "Maximum area is " << getMaxArea(hist, n);

	return 0;
}
