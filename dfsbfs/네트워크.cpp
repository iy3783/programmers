#include <iostream>
#include <string>
#include <vector>


using namespace std;

int map[205];
int parent[205];
int sum[205];
int find_parent(int n) {
	if (parent[n] == n) {
		return n;
	}
	return parent[n] = find_parent(parent[n]);

}
void merge(int a ,int b) {
	int v=find_parent(a);
	int w=find_parent(b);
	if (v==w) {
		return;
	}
	parent[v] = w;

}
void parent_init() {
	for (int i = 0; i <= 200;i++) {
		parent[i] = i;
	}
}


int solution(int n, vector<vector<int> > computers) {
	int answer = 0;
	parent_init();
	for (int i = 0; i < n;i++ ) {
		for (int j = 0; j < n;j++) {
			if (computers[i][j] ==1) {
				merge(i, j);
			}
		}
	}
	for (int i = 0; i < n;i++) {
		find_parent(i);
		sum[parent[i]] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (sum[i]==1 ) {
			answer++;
		}
	}



	return answer;
}

