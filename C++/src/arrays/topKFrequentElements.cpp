#include <iostream>     // std::cout
#include <functional>   // std::less
#include <algorithm>    // std::sort, std::includes
#include <vector>
#include <unordered_map>

using namespace std;

static bool compare(pair<int, int> left, pair<int, int> right) {
	if (left.second == right.second) {
		return left.first > right.first;
	}
	return left.second > right.second;
}

vector<int> topKFrequent(vector<int> &nums, int k) {
	vector<int> rv;
	unordered_map<int, int> elementCount;
	for (int i = 0; i < nums.size(); i++) {
		elementCount[nums[i]]++;
	}
	vector<pair<int, int> > freq_arr(elementCount.begin(), elementCount.end());
	sort(freq_arr.begin(), freq_arr.end(), compare);
	for (int i = 0; i < k; i++) {
		rv.push_back(freq_arr[i].first);
	}
	return rv;
}
