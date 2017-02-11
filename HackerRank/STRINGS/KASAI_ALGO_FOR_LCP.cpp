// C++ program for building LCP array for given text
#include <bits/stdc++.h>
using namespace std;

// Structure to store information of a suffix
struct suffix
{
	int index; // To store original index
	int rank[2]; // To store ranks and next rank pair
};

// A comparison function used by sort() to compare two suffixes
// Compares two pairs, returns 1 if first pair is smaller
int cmp(struct suffix a, struct suffix b)
{
	return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
		(a.rank[0] < b.rank[0] ?1: 0);
}

// This is the main function that takes a string 'txt' of size n as an
// argument, builds and return the suffix array for the given string
vector<int> buildSuffixArray(string txt, int n)
{
	// A structure to store suffixes and their indexes
	struct suffix suffixes[n];

	// Store suffixes and their indexes in an array of structures.
	// The structure is needed to sort the suffixes alphabatically
	// and maintain their old indexes while sorting
	for (int i = 0; i < n; i++)
	{
		suffixes[i].index = i;
		suffixes[i].rank[0] = txt[i] - 'a';
		suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1;
	}

	// Sort the suffixes using the comparison function
	// defined above.
	sort(suffixes, suffixes+n, cmp);

	// At his point, all suffixes are sorted according to first
	// 2 characters. Let us sort suffixes according to first 4
	// characters, then first 8 and so on
	int ind[n]; // This array is needed to get the index in suffixes[]
	// from original index. This mapping is needed to get
	// next suffix.
	for (int k = 4; k < 2*n; k = k*2)
	{
		// Assigning rank and index values to first suffix
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;

		// Assigning rank to suffixes
		for (int i = 1; i < n; i++)
		{
			// If first rank and next ranks are same as that of previous
			// suffix in array, assign the same new rank to this suffix
			if (suffixes[i].rank[0] == prev_rank &&
					suffixes[i].rank[1] == suffixes[i-1].rank[1])
			{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			}
			else // Otherwise increment rank and assign
			{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}
			ind[suffixes[i].index] = i;
		}

		// Assign next rank to every suffix
		for (int i = 0; i < n; i++)
		{
			int nextindex = suffixes[i].index + k/2;
			suffixes[i].rank[1] = (nextindex < n)?
								suffixes[ind[nextindex]].rank[0]: -1;
		}

		// Sort the suffixes according to first k characters
		sort(suffixes, suffixes+n, cmp);
	}

	// Store indexes of all sorted suffixes in the suffix array
	vector<int>suffixArr;
	for (int i = 0; i < n; i++)
		suffixArr.push_back(suffixes[i].index);

	// Return the suffix array
	return suffixArr;
}

/* To construct and return LCP */
vector<int> kasai(string txt, vector<int> suffixArr,int n)
{
    vector<int>lcp(n);
    int revSuff[n];

    for(int i=0;i<n;i++){
        revSuff[suffixArr[i]]=i;
    }


    int k=0;
    for(int i=0;i<n;i++){

        if(revSuff[i]==n-1){
            k=0;
            continue;
        }


        int j=suffixArr[revSuff[i]+1];


        while(i+k<n &&j+k<n && txt[i+k]==txt[j+k]){
            k++;
        }

        lcp[revSuff[i]]=k;

        if(k>0){
            k--;
        }

    }

	// return the constructed lcp array
	return lcp;
}

// Utility function to print an array
void printArr(vector<int>arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver program
int main()
{
	string str = "banana";

	vector<int>suffixArr = buildSuffixArray(str, str.length());
	int n = suffixArr.size();

	cout << "Suffix Array : \n";
	printArr(suffixArr, n);

	vector<int>lcp = kasai(str, suffixArr,n);

	cout << "\nLCP Array : \n";
	printArr(lcp, n);
	return 0;
}
