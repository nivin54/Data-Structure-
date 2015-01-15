#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string.h>
using namespace std;
long long n, t, k, intensity[22], exactSum;
int run(int n) {
	long long sum = 0;
	for (int i = 0; i < n; i++)
		sum += intensity[i];
	if (sum == 0)
		return 1;
	for (int i = 0; i < 1 << (n - 1); i++) {
		long long csum = 0;
		for (int j = 0; j < n - 1; j++)
			if (i >> j & 1)
				csum += intensity[j];
		if (exactSum == (csum + intensity[n - 1])) {
			long long b[n];
			for (int j = 0; j < n; j++)
				b[j] = intensity[j];
			int index = 0;
			for (int j = 0; j < n - 1; j++)
				if ((i >> j & 1) == 0)
					intensity[index++] = intensity[j];
			if (run(index))
				return 1;
			for (int j = 0; j < n; j++)
				intensity[j] = b[j];
		}
	}
	return 0;

}
int main() {
	cin >> t;
	string result;
	long long sum;
	for (int i = 0; i < t; i++) {
		result = "";
		cin >> n >> k;
		sum = 0;
		for (int j = 0; j < n; j++) {
			cin >> intensity[j];
			sum += intensity[j];
		}
		exactSum = sum / k;
		if (n < k || (sum % k))
			result = "no";
		else
			result =( run(n) )? "yes" : "no";
		cout << result << endl;

	}
}
