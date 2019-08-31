long long mod(long long a, long long m) {
    return (a % m + m) % m;
}
long long mul(long long a, long long b, long long m) {
    a = mod(a, m); b = mod(b, m);
    if (b == 0) return 0;
    long long res = mul(mod(a + a, m), b>>1, m);
    if (b & 1) res = mod(res + a, m);
    return res;
}
long long inv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a/b;
        a = mod(a - mul(t, b, m), m); swap(a, b);
        u = mod(u - mul(t, v, m), m); swap(u, v);
    }
    return mod(u, m);
}
