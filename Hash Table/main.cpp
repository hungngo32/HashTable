#include<iostream>
#include<vector>
using namespace std;
const int MAX = 1000;
vector<pair<int, int>> h[MAX];
int getHash(int key) {
	return key % MAX;
}
void insert(int key, int val) {
	int hkey = getHash(key);
	for (auto x : h[hkey]) {
		if (x.first == key) {
			return;
		}
	}
	h[hkey].emplace_back(key, val);
}
int find(int key) {
	int hkey = getHash(key);
	for (auto x : h[hkey]) {
		if (x.first == key) {
			return x.second;
		}
	}
	return -1;
}
int main() {
	int a[] = { -1, 9, -5, -8, -5, -2 };
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++) {
		insert(i, a[i]);
	}
	cout << find(-5);
	system("pause");
	return 0;
}