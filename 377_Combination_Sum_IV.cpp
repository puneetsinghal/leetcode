#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
	unordered_multimap<int, int> memo;
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target<0) return 0;
        if (target==0) return 1;

        int sum = 0;
        if(memo.find(target)!= memo.end()){
        	return memo.find(target)->second;
        }
        for(int i =0; i<nums.size(); i++){
        	sum += combinationSum4(nums, target-nums[i]);
        }
        memo.insert({target, sum});
        return sum;
    }
};


int main(){

    vector<int> nums = {1, 2, 3};
    int target = 4;
    Solution sol;
    std::cout<<sol.combinationSum4(nums, target)<<endl;
    return 0;
}	