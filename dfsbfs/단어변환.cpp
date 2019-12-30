#include <string>
#include <vector>
using namespace std;


int min_depth = 2332;
int check[100];

int wordchecking(string s1,string s2) {
	int diffcounter = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i]) {
			diffcounter++;
		}
	}
	if (diffcounter<=1) {
		return 1;
	}
	else {
		return 0;
	}
}


void back_tracking(int depth, string target, string cur_str , vector<string> words) {
	if (cur_str == target) {
		if (depth <min_depth) {
			min_depth = depth;
		}
		return;
	}

	for (int i = 0; i < words.size();i++) {
		if (check[i] == 0) {
			if (wordchecking(cur_str , words[i])==1  ) {
				check[i] = 1;
				back_tracking(depth + 1, target, words[i], words );
				check[i] = 0;
			}
		}

	}

	return;
}


int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	int notarget = 1;
	for (int i = 0; i < words.size();i++) {
		if (words[i] == target) {
			notarget = 0;
		}
	}
	if (notarget==1) {
		return answer;
	}

	back_tracking( 0 , target,begin, words);

	if (min_depth ==2332) {
		answer = 0;
	}
	else {
		answer = min_depth;
	}



	return answer;
}