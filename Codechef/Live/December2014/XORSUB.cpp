#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string.h>
using namespace std;
int nact[1005];
int highestBitSet(int value) {
	for (int i = 9; i >= 0; i--)
		if ((value & (1 << i)))
			return i;
	return 0;

}

int main() {
	int T, K, value, N, mask;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		mask = K;
		for (int i = 0; i < N; i++) {
			cin >> value;
			nact[i] = value;
		}
		sort(nact, nact + N, greater<int>());
		for (int i = 0; i < N; i++) {
			int pos = highestBitSet(nact[i]);
			for (int j = i + 1; j < N; j++) {
				if ((nact[j] & (1 << pos)))
					nact[j] ^= nact[i];
				else
					break;
			}
			sort(nact, nact + N, greater<int>());
		}
		for (int i = 0; i < N; i++)
			mask = max(mask, mask ^ nact[i]);
		cout << mask << endl;

	}

}
