#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size();i++) {
		for (int j = i + 1; j < phone_book.size();j++) {
			int is_same = 1;
			for (int k = 0; k < phone_book[i].length();k++) {
				if (phone_book[i][k] != phone_book[j][k]) {
					is_same = 0;
					break;
				}
			}
			if (is_same ==1) {
				answer = false;
			}

		}
	}



	return answer;
}


int main() {


	return 0;
}