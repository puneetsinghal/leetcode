#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> sortedElements; // final vector (sorted) that will be returned
        queue<int> independentNodes; // keeps track of nodes that have no dependencies at any given point and hence can be added to sorted list
        vector<int> inDegree = computeIndegree(numCourses, prerequisites); // inDegree counts the number of dependencies for each node

        for (int i = 0; i < numCourses; ++i)
        {
        	if(inDegree[i]==0){
        		independentNodes.push(i);
        	}
        }
        while(!independentNodes.empty()){
        	int currentNode = independentNodes.front();
        	independentNodes.pop();

        	sortedElements.push_back(currentNode);

        	for (int i = 0; i < prerequisites.size(); ++i)
        	{
        		if(prerequisites[i].second != currentNode){
        			continue;
        		}
        		if(inDegree[prerequisites[i].first] == 1){
        			independentNodes.push(prerequisites[i].first);
        		}        		
    			inDegree[prerequisites[i].first] = inDegree[prerequisites[i].first] - 1;
        	}
        }
        //	Check if the graph is not acyclic and return empty vector in that case
        for (int i = 0; i < inDegree.size(); ++i)
        {
        	if (inDegree[i]!=0) return vector<int> {};
        }
        return sortedElements;
    }
private:
	// function to count the number of dependencies for each node and return a vector of these counts
	vector<int> computeIndegree(int numCourses, const vector<pair<int, int>>& prerequisites){
		vector<int> inDegree(numCourses);
		for (int i = 0; i < prerequisites.size(); ++i)
		{
			inDegree[prerequisites[i].first] = inDegree[prerequisites[i].first]+1;
		}
		return inDegree;
	}
};



int main(){

    vector<pair<int, int>> prerequisites =  {{1,0},{1,2},{0,1}};
    int numCourses = 3;
    Solution sol;
    std::vector<int> sortedElements = sol.findOrder(numCourses, prerequisites);

    for (int i = 0; i < sortedElements.size(); ++i)
    {
    	cout<<sortedElements[i]<<"  ";
    }
    return 0;
}	