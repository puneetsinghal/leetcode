#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        
        int numSegments = 0;

        int currentIndex = 0;
        
        if(s[currentIndex] == '\0'){
            return numSegments;
        }
        bool encounteredNewWord = true;
        while(s[currentIndex] != '\0'){
        	if(s[currentIndex] != ' ' && encounteredNewWord){
                numSegments++;
                encounteredNewWord = false; 
            }
            else if(s[currentIndex] == ' '){
                encounteredNewWord = true; 
            }
            currentIndex++;
        }
        return numSegments;
    }
};

int main(){

    string s = "                d";
    Solution sol;
    std::cout<<sol.countSegments(s)<<endl;
    return 0;
}