#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, Q; string S;
char c[200009], p[200009], d[200009];

int simulation(int pos) {
	for (int i = 1; i <= Q; i++) {
		if (pos == 0) return 1;
		if (pos == N + 1) return 3;

		if (d[pos] == c[i]) {
			if (p[i] == 'L') pos--;
			else pos++;
		}
	}

	if (pos == 0) return 1;
	if (pos == N + 1) return 3;
	return 2;
}

int main() {
	cin >> N >> Q >> S;
	for (int i = 1; i <= N; i++) d[i] = S[i - 1];
	for (int i = 1; i <= Q; i++) cin >> c[i] >> p[i];

	int L1 = 1, R1 = N + 1, M1, maxn = 0;
	for (int i = 0; i < 25; i++) {
		M1 = (L1 + R1) / 2;
		int Z = simulation(M1);
		if (Z == 1) { maxn = max(maxn, M1); L1 = M1; }
		else { R1 = M1; }
	}

	int L2 = 1, R2 = N + 1, M2, minx = N + 1;
	for (int i = 0; i < 25; i++) {
		M2 = (L2 + R2) / 2;
		int Z = simulation(M2);
		if (Z == 3) { minx = min(minx, M2); R2 = M2; }
		else { L2 = M2; }
	}

	cout << N - (maxn + (N + 1 - minx)) << endl;
	return 0;
}
