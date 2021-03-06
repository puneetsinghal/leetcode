class Solution {
private:
	int length;
public:
	void print(array<int, 4> data){
		for (int i = 0; i < data.size(); ++i)
		{
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}

	void print(vector<int> data){
		for (int i = 0; i < data.size(); ++i)
		{
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}

	bool makesquare(vector<int>& nums){
		array<int,4> sums = {0, 0, 0, 0};
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			sum+=nums[i];
		}
		if(sum%4 ==0)
			length = sum/ 4;
		else
			return false;
		
		std::vector<int> sortedNums;
		while(nums.size()!=0){
			int maxNum = 0;
			int index = 0;
			for (int i = 0; i < nums.size(); ++i)
			{
				if(maxNum<nums[i]){
					maxNum = nums[i];
					index = i;
				}
			}
			sortedNums.push_back(maxNum);
			nums.erase(nums.begin()+index);
		}
		// print(sortedNums);
		return (makesquare(sortedNums, sums));
	}

	bool makesquare(vector<int> nums,  array<int, 4> &sums){
		// cout<<nums.size()<<"      ";
  //       print(sums);
		if(nums.size()==0){
			if(sums[0]==sums[1] && sums[1]==sums[2] && sums[2]==sums[3] && sums[0!=0]) return true;
			else return false;
		}
		bool feasible = false;
        
        int newNum = nums[0];
        nums.erase(nums.begin());
		array<int,4> sums1 = sums;
		sums1[0] = sums[0]+newNum;
		if(sums1[0]<=length){
			feasible = feasible || makesquare(nums, sums1);
		}

		array<int,4> sums2 = sums;
		sums2[1] = sums[1]+newNum;
		if(sums2[1]<=length){
			feasible = feasible || makesquare(nums, sums2);
		}

		array<int,4> sums3 = sums;
		sums3[2] = sums[2]+newNum;
		if(sums3[2]<=length){
			feasible = feasible || makesquare(nums, sums3);
		}

		array<int,4> sums4 = sums;
		sums4[3] = sums[3]+newNum;
		if(sums4[3]<=length){
			feasible = feasible || makesquare(nums, sums4);
		}		

		// return (makesquare(nums, sums1) || makesquare(nums, sums2) || makesquare(nums, sums3) || makesquare(nums, sums4));
		return feasible;
	}
};