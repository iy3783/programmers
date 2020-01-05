#include <string>
#include <vector>
#include <iostream>
using namespace std;

int is_prime[10000020];// 0 소수 1 소수아님
vector<int> prime_test_vector;

void findPrime(long long int N) {
	for (long long int i = 2; i*i <= N;i++) {
		if (is_prime[i] == 0) {
			for (long long int j = i + i; j <=N;j+=i ) {
				is_prime[j] = 1;
			}
		}
		
	}
	return;
}
int vector_to_n(vector<int> v) {
	int digit = 1;
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += digit* v[i];
		digit *= 10;
	}
	return sum;
}

void dfs(int depth, vector<int>& v, string& numbers,int check[] , int& counter ) {
	if (depth == numbers.length()) {
	
		int sum = vector_to_n(v);
		for (int i = 0; i < prime_test_vector.size();i++) {
			if (sum == prime_test_vector[i]) {
				return;
		
			}
		}
		prime_test_vector.push_back(sum);
		if (is_prime[sum]==0) {
			counter++;
		}
		
		return;
	}

	dfs(depth + 1, v, numbers, check, counter);

	for (int i = 0; i <numbers.length(); i++) {
		if (check[i] == 0) {
			v.push_back(numbers[i] - '0');
			check[i] = 1;
			dfs(depth + 1, v, numbers, check, counter);
			v.pop_back();
			check[i] = 0;
		}
		
	}



	return;
}



int solution(string numbers) {
	int answer = 0;
	is_prime[0] = 1;
	is_prime[1] = 1;
	findPrime(10000000);
	vector<int> v;
	int counter = 0;
	int check[10] = { 0 };

	dfs(0,v,numbers,check,counter);

	answer = counter;

	return answer;
}



int main() {
	string s;
	cin >> s;
	solution(s);


}
