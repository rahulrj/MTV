http://codeforces.com/problemset/problem/271/D

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	set <long long> uniq;
	string s, bad;
	int k;
	cin >> s >> bad >> k;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		long long hash = 0;
		int count = 0;
		for (int j = i; j < n; j++) {
			count += (bad[s[j] - 'a'] == '0');
			if (count > k) break;
			hash = (hash * 131) ^ s[j];
			//cout<<hash<<endl;
			uniq.insert(hash);
		}
	}
	cout << uniq.size();
	return 0;
}
