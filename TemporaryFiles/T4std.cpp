#include <bits/stdc++.h>
void rint(int& x) {
	char c = getchar(); x = 0;
	bool neg = false;
	while (c < '0' || c > '9') {
		neg |= (c == '-'); 
		c = getchar();
	}
	do {
		x = x * 10 + (c & 15);
		c = getchar();
	} while ('0' <= c && c <= '9');
	if (neg) x = -x;
}
#define N 500001
int n, m, st[N], tp = -1; char s[N];
int main() {
    freopen("a.in","r",stdin);
    freopen("a.ans","w",stdout);
	rint(n); rint(m);
	scanf("%s", s);
	s[n] = '0';
	long long ans = 0;
	st[++tp] = 1;
	if (s[0] == '1') ans += n;
	bool ts = (s[0] == '1');
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i-1]) {
			ans += n-i;
			st[++tp] = 1;
		} else st[tp]++;
	}
	ts ^= bool(tp & 1);
	while (m--) {
		int o; rint(o);
		bool ty = true;
		if (o < 0) {ty = false; o = -o; }
		int t = 0;
		while (tp >= 0) {
			if (ty == ts) {
				t += st[tp];
				if (tp || ty) ans -= t;
				tp--;
				ts = !ts;
			} else {
				if (st[tp] <= o) {
					t += st[tp];
					o -= st[tp];
					if (tp || !ty) ans -= t;
					tp--;
					ts = !ts;
				} else {
					t += o;
					st[tp] -= o;
					break;
				}
			}
		}
		st[++tp] = t;
		if (tp || ty) ans += t;
		ts = ty;
		printf("%lld\n", ans);
	}
//    system("pause");
}
