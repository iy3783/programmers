#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct genre_count {
	int num;
	int play;
};

struct genre_count_vector_info {
	vector<genre_count> vgc;
	int sum;

};

bool compare(genre_count_vector_info a, genre_count_vector_info b) {
	return a.sum > b.sum;
}
bool compare2(genre_count a, genre_count b) {
	if (a.play == b.play) {
		return a.num < b.num;
	}
	return a.play> b.play;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, genre_count_vector_info > mapp;

	for (int i = 0; i <genres.size(); i++) {
		if (mapp.count(genres[i]) == 0) {
			genre_count_vector_info gcvi;

			vector<genre_count> tmp_genre_v;
			genre_count tmp;
			tmp.num = i;
			tmp.play = plays[i];
			tmp_genre_v.push_back(tmp);
			gcvi.vgc = tmp_genre_v;
			gcvi.sum = plays[i];
			mapp.insert(make_pair(genres[i], gcvi));

		}
		else {
			genre_count_vector_info gcvi;
			genre_count tmp;
			tmp.num = i;
			tmp.play = plays[i];
			mapp[genres[i]].vgc.push_back(tmp);
			mapp[genres[i]].sum += plays[i];


		}
	}
	vector<genre_count_vector_info> t_v;
	for (auto i = mapp.begin(); i != mapp.end(); i++) {
		t_v.push_back(i->second);
	}
	sort(t_v.begin(), t_v.end(), compare);
	for (int i = 0; i< t_v.size(); i++) {
		sort(t_v[i].vgc.begin(), t_v[i].vgc.end(), compare2);
	}

	if (t_v.size() == 1) {
		if (t_v[0].vgc.size() == 1) {
			answer.push_back(t_v[0].vgc[0].num);
		}
		else {
			answer.push_back(t_v[0].vgc[0].num);
			answer.push_back(t_v[0].vgc[1].num);
		}


	}
	else {
		for (int i = 0; i < t_v.size(); i++) {
			if (t_v[i].vgc.size() == 1) {
				answer.push_back(t_v[i].vgc[0].num);
			}
			else {
				answer.push_back(t_v[i].vgc[0].num);
				answer.push_back(t_v[i].vgc[1].num);

			}
		}


	}


	return answer;
}
