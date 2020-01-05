#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int clothes[35] = { 0, };


	for (int i = 1; i <= n; i++) {
		clothes[i] = 1;
		for (int j = 0; j <lost.size(); j++) {
			if (lost[j] == i) {
				clothes[i]--;
				break;
			}
		}
		for (int j = 0; j < reserve.size(); j++) {
			if (reserve[j] == i) {
				clothes[i]++;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (clothes[i] == 1) {
			answer++;
		}
		else if (clothes[i] == 0) {
			if (clothes[i + 1] == 2) {
				clothes[i]++;
				clothes[i + 1]--;
				answer++;
			}

		}
		else if (clothes[i] == 2) {
			if (clothes[i + 1] == 0) {
				clothes[i]--;
				clothes[i + 1]++;
				answer++;
			}
			else {
				answer++;
			}
		}

	}



	return answer;
}