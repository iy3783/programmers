#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
vector<string> clothes_kind;
vector<int> back_tracking_vector;
map<string, int> my_map;




int solution(vector<vector<string> > clothes) {
	int answer = 0;


	for (int i = 0; i < clothes.size(); i++) {
		if (my_map.count(clothes[i][1])==0) {
			my_map.insert(make_pair(clothes[i][1], 1));
			clothes_kind.push_back(clothes[i][1]);
		}
		else {
			my_map[clothes[i][1]]++;
		}
	}
	int sum=0;
	int tmp_sum = 1;
	for (int i = 0; i < clothes_kind.size();i++) {
		tmp_sum *= (my_map[clothes_kind[i]] + 1);
	}
	if (clothes_kind.size()!=0) {
		sum = tmp_sum-1;
	}

	answer = sum;



	return answer;
}
int main() {
	vector<vector<string> > clothes;
	vector<string> tmp[3];
	tmp[0].push_back("yellow_hat");
	tmp[0].push_back("headgear");
	clothes.push_back(tmp[0]);
	tmp[1].push_back("blue_sunglasses");
	tmp[1].push_back("eyewear");
	clothes.push_back(tmp[1]);
	tmp[2].push_back("green_turban");
	tmp[2].push_back("headgear");
	clothes.push_back(tmp[2]);
	cout<< solution(clothes);


	return 0;
}

