http://codeforces.com/problemset/problem/59/A

#include <bits/stdc++.h>

using namespace std;

int main() {
  string s; cin >> s;
  int u = 0;
  for(char c : s) {
    u += isupper(c) > 0;
  }
  for(char c : s) {
    putchar(u * 2 > (int)s.size() ? toupper(c) : tolower(c));
  }
  putchar('\n');
  return 0;
}
