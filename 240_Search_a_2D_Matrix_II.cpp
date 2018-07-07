#include <iostream>
#include <vector>
// #include <>

using namespace std;

class Solution {
public:
	void updateIndeces(int index, int &lowerBound, int &upperBound){

		if(lowerBound == -1) lowerBound = index;
		else	lowerBound = min(lowerBound, index);
		if(upperBound == -1) upperBound = index;
		else 	upperBound = max(upperBound, index);
		return;
	}

	// void searchBounds(vector<vector<int>> const &data, int const target, int &lowerBound, int &upperBound, int startIndex, int endIndex){

	// 	if(endIndex<startIndex) return;
	// 	if(target < data[startIndex][startIndex]){
	// 		upperBound = min(upperBound, startIndex);
	// 		return;
	// 	}
	// 	if(target > data[endIndex][endIndex]){
	// 		lowerBound = max(lowerBound, endIndex);
	// 		return;
	// 	}

	// 	int numElements = (endIndex - startIndex + 1);
	// 	if(numElements == 1){
	// 		// updateIndeces(startIndex, lowerBound, upperBound);
	// 		return;
	// 	}

	// 	int middleIndex = (startIndex+ endIndex)/2;

	// 	if(target<data[middleIndex][middleIndex]){
	// 		upperBound = min(upperBound, middleIndex);
	// 		searchBounds(data, target, lowerBound, upperBound, startIndex, middleIndex-1);
	// 	}
	// 	else if(target>data[middleIndex][middleIndex]){
	// 		lowerBound = max(lowerBound, middleIndex);
	// 		searchBounds(data, target, lowerBound, upperBound, middleIndex+1, endIndex);
	// 	}
	// 	else{
	// 		searchBounds(data, target, lowerBound, upperBound, startIndex, middleIndex-1);
	// 		searchBounds(data, target, lowerBound, upperBound, middleIndex+1, endIndex);
	// 	}
	// 	return;
	// }

	bool searchBounds(vector<vector<int>> const &data, int const target, int &lowerBound, int &upperBound, int startIndex, int endIndex){
		if(target>data[endIndex][endIndex]) return false;
		if(target<data[startIndex][startIndex]) return false;

		for(int i = startIndex; i<=endIndex; ++i){
			if(target>data[i][i]){
				lowerBound = i;
				upperBound = i;
			}
			else if(target<data[i][i]){
				upperBound = i;
				return true;
			}
			else
				upperBound = i;
		}
		return true;
	}

	void searchBoundsRow(vector<vector<int>> const &data, int rowIndex, int const target, int &lowerBound, int &upperBound, int startIndex, int endIndex){

		if(endIndex<startIndex) return;
		if(target < data[rowIndex][startIndex])	return;
		if(target > data[rowIndex][endIndex])	return;

		int numElements = (endIndex - startIndex + 1);
		if(numElements == 1 && data[rowIndex][startIndex] == target){
			updateIndeces(startIndex, lowerBound, upperBound);
			return;
		}

		int middleIndex = (startIndex+ endIndex)/2;

		if(target<=data[rowIndex][middleIndex])
			searchBounds(data, target, lowerBound, upperBound, startIndex, middleIndex);

		if(target>=data[rowIndex][middleIndex])
			searchBounds(data, target, lowerBound, upperBound, middleIndex+1, endIndex);

		return;
	}

	void searchBoundsCol(vector<vector<int>> const &data, int colIndex, int const target, int &lowerBound, int &upperBound, int startIndex, int endIndex){

		if(endIndex<startIndex) return;
		if(target < data[startIndex][colIndex])	return;
		if(target > data[endIndex][colIndex])	return;

		int numElements = (endIndex - startIndex + 1);
		if(numElements == 1 && data[startIndex][colIndex] == target){
			updateIndeces(startIndex, lowerBound, upperBound);
			return;
		}

		int middleIndex = (startIndex+ endIndex)/2;

		if(target<=data[middleIndex][colIndex])
			searchBounds(data, target, lowerBound, upperBound, startIndex, middleIndex);

		if(target>=data[middleIndex][colIndex])
			searchBounds(data, target, lowerBound, upperBound, middleIndex+1, endIndex);

		return;
	}

	bool searchMatrix(vector<vector<int>>& data, int target) {
		int height = data.size();
		if(height==0) return false;
		int width = data[0].size();
		if(width==0) return false;

		int lowerBound(0), upperBound(0);

		cout<<lowerBound<<" "<<upperBound<<endl;
		
		int numOccurances = 0;

		if(!searchBounds(data, target, lowerBound, upperBound, 0, min(height, width) - 1)) cout<<"no solution"<<endl;
		else{

			cout<<lowerBound<<" "<<upperBound<<endl;
			for(int i = lowerBound; i<=upperBound; ++i){
				if(target == data[i][i]) numOccurances--;
			}
			int endRow = upperBound;
			int endColumn = upperBound;
			int startIndex = lowerBound;

			if(upperBound == height-1){
				endColumn = width -1;
			}
			if(upperBound == width - 1){
				endRow = height -1;
			}

			for(int i=startIndex; i<=endRow; ++i){
				lowerBound = -1;
				upperBound = -1;
				searchBoundsRow(data, i, target, lowerBound, upperBound, 0, min(i,endColumn));
				if(lowerBound == -1) continue;
				numOccurances += upperBound - lowerBound + 1;
			}

			for(int i=startIndex; i<=endColumn; ++i){
				lowerBound = -1;
				upperBound = -1;
				searchBoundsCol(data, i, target, lowerBound, upperBound, 0, min(i,endRow));
				if(lowerBound == -1) continue;
				numOccurances += upperBound - lowerBound + 1;
			}
		}

		// cout<<"number of occurances: "<<numOccurances<<endl;    
		if(numOccurances>0) return true;
		else return false;
	}
};

int main(){
	// vector<vector<int>> data = {{1,4,7,11,15},{2,5,8,11,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
	vector<vector<int>> data = {{-1,3}};
	
	int target = 3;

	Solution sol;
	cout<<sol.searchMatrix(data,target);

	return 0;
}