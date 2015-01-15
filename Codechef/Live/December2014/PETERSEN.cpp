#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string result, q;
int graph[10][3] = { { 1, 4, 5 }, { 0, 2, 6 }, { 1, 3, 7 }, { 2, 4, 8 }, { 0, 3,
		9 }, { 0, 7, 8 }, { 1, 8, 9 }, { 2, 5, 9 }, { 3, 5, 6 }, { 4, 6, 7 } };
int len, flag = 0;
bool compare(int u, int v) {
	bool flag = false;
	for (int i = 0; i < 3; i++)
		if (graph[u][i] == v)
			flag = true;
	return flag;

}
void dfs(int i, string trace, int prev) {
	for (; i < len; i++) {
		int u = q[i] - 'A';
		if (compare(prev, u)) {
			trace += string(1, char(u + '0'));
			prev = u;

		} else if (compare(prev, u + 5)) {
			u += 5;
			trace += string(1, char(u + '0'));
			prev = u;
		}
	}
	if (trace.length() == len) {
		if (!flag) {
			result = trace;
			flag = true;
		}
	}

}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> q;
		len = q.length();
		result = "-1";
		int index1 = q[0] - 'A';
		flag = 0;
		dfs(1, string(1, char(index1 + '0')), index1);
		index1 += 5;
		dfs(1, string(1, char(index1 + '0')), index1);
		cout << result << endl;
	}
	return 0;
}
