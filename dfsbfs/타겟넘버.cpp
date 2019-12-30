#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int sum=0;
vector<int> v;



void back_tracking(vector<int> numbers,int depth, int target) {
	if (depth == numbers.size()) {
		int tmpsum = 0;
		
		for (int i = 0; i < numbers.size();i++) {
			if (v[i] ==0) {
				tmpsum -= numbers[i];
			}
			else if (v[i] ==1) {
				tmpsum += numbers[i];
			}
		}
		if (tmpsum == target) {
			sum++;
		}


		return;
	}

	v.push_back(0);
	back_tracking(numbers,depth+1,target);
	v.pop_back();

	v.push_back(1);
	back_tracking(numbers, depth + 1, target);
	v.pop_back();

	return;

}


int solution(vector<int> numbers, int target) {
	int answer = 0;
	sum = 0;

	back_tracking(numbers, 0, target);

	answer = sum;

	return answer;
}


int main() {






	return 0;
}