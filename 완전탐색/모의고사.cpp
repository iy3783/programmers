#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int supoza1[15] = { 1,2,3,4,5 };
int supoza2[15] = { 2,1,2,3,2,4,2,5 };
int supoza3[15] = { 3,3,1,1,2,2,4,4,5,5 };



struct supoza_info {
	int num;
	int count;


};

bool compare(supoza_info a, supoza_info b) {
	if (a.count == b.count) {
		return a.num < b.num;
	}
	return a.count> b.count;

}



vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int answers_length = answers.size();
	supoza_info counter[3] = { 0 };
	counter[0].num = 1;
	counter[1].num = 2;
	counter[2].num = 3;
	for (int i = 0; i < answers_length; i++) {

		int a = i % 5;
		int b = i % 8;
		int c = i % 10;


		if (answers[i] == supoza1[a]) {
			counter[0].count++;
		}
		if (answers[i] == supoza2[b]) {
			counter[1].count++;
		}
		if (answers[i] == supoza3[c]) {
			counter[2].count++;
		}

	}
	sort(counter, counter + 3, compare);
	int max = counter[0].count;
	for (int i = 0; i < 3; i++) {
		if (counter[i].count == max) {
			answer.push_back(counter[i].num);
		}
	}





	return answer;
}