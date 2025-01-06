#include <iostream>

using namespace std;

int k, n;
int a[1005][1005];


int const mod = 1e9 + 7;

void sang() {
	a[1][0] = 1;
	a[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) a[i][j] = 1;
			else a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % mod;

		}
	}
}


int main() {
	cin >> k >> n;
	sang();

	cout << a[n][k];

	return 0;
}

