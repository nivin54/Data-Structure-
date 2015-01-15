#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int md = 1000000007;
inline void add(int& a, int b) {
	a += b;
	if (a >= md)
		a -= md;
}

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	int f[n][n];
	memset(f, 0, sizeof(f));
	for (int d = 0; d < n; d++) {
		for (int i = 0; i < n; i++) {
			int j = d + i;
			if (j >= n)
				continue;
			int & res = f[i][j];
			res = 1;
			if (i < j)
				add(res, (f[i][j - 1] + md - 1) % md);
			for (int k = i; k < j; k++) {
				if (a[k] < 0 && a[k] + a[j] == 0) {
					int fi = (i < k ? f[i][k - 1] : 1);
					int se = (k < j - 1 ? f[k + 1][j - 1] : 1);
					add(res, fi * 1ll * se % md);
				}

			}

		}
	}

	printf("%d\n", f[0][n - 1]);
	return 0;
}
