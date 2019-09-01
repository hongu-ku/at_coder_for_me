

vector<vector<ll> > comb(int n, int r) {
  vector<vector<ll> > v(n + 1,vector<ll>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]) % MOD; // MODで割った数。
    }
  }
  return v;
}

// vector<vector<ll> > COMB(n + 1,vector<ll>(n + 1, 0)); で使う
