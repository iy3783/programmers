#include <string> 
#include <vector> 
#include <algorithm>
using namespace std;

bool dfs(string from , vector<vector<string> >& tickets ,vector<bool>& visit ,vector<string>& temp , vector<string>& answer,int depth ) {
	if (depth ==tickets.size()) {
		answer.push_back("ICN");
		for (int i = 0; i < temp.size();i++) {
			answer.push_back(temp[i]);
		}
		return true;
	}


	for (int i = 0; i < tickets.size(); i++) {
		if (from == tickets[i][0]) {
			if (visit[i] == false) {
				temp.push_back(tickets[i][1]);
				visit[i] = true;
				bool isfinished = dfs(tickets[i][1], tickets, visit, temp, answer, depth + 1);
				temp.pop_back();
				visit[i] = false;
				if (isfinished == true) {
					return true;
				}
			}
	


		}

	}


	return false;
	
}



vector<string> solution(vector<vector<string> >  tickets) { 
	vector<string> answer, temp;
	vector<bool> visit(tickets.size(), false);
	sort(tickets.begin(), tickets.end());
	
	dfs("ICN", tickets, visit, temp, answer, 0); 
	return answer; 
}