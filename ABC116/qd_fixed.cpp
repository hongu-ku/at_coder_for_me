#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<long long int>v(N);
	vector<long long int>w;
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		if (v[L - 1] < R) {
			w.push_back(v[L - 1]);
			v[L - 1] = R;
		}
		else {
			w.push_back(R);
		}
	}
	sort(w.begin(), w.end(), greater<long long int>());
	long long int ans = 0;
	sort(v.begin(), v.end(), greater<long long int>());
	for (int i = 1; i < w.size(); i++) {
		w[i] += w[i - 1];
	}
	for (int i = 1; i < v.size(); i++) {
		v[i] += v[i - 1];
	}
	for (long long int i = 0; i < K; i++) {
		if (i&&v[i]==v[i-1])break;
		if (i == K - 1)ans = max(ans, v[i]+(i+1)*(i+1));
		else if(K-i-2>=0&&K-i-2<w.size())ans = max(ans, v[i] + w[K - i - 2] + (i + 1)*(i + 1));
	}
	cout << ans << endl;
	return 0;
}
