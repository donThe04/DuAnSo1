#include <iostream>

using namespace std;

int fiBo(int n) {
	if (n <= 1) return n;
	return fiBo(n - 1) + fiBo(n - 2);
}

int main() {
	int n; cin >> n;
	cout << fiBo(n - 1) << endl;

	return 0;
}

