class Solution {
    int width;
    int height;
    
private:
    int vectorize(vector<int> const &index){
        return (index[0]*width+index[1]);
    }
    
    vector<int> devectorize(int index){
        vector<int> location;
        int row = int(index/width);
        location.push_back(row);
        int col = index - width*row;
        location.push_back(col);
        return location;
    }
    
    bool insideMap(int row, int col){
        if (row<0 || row >= height)
            return false;
        if(col<0 || col >=width)
            return false;
        return true;
    }
    
    vector<vector<char>> expand(vector<vector<char>>& board, list<vector<int>> *openList, vector<int> const &location){
        if(board[location[0]][location[1]]!='E'){
            return board;
        }
        list<vector<int>> newLocations;
        int numMines=0;
        for(int i = -1; i<2; i++){
            int row = location[0] + i; 
            for(int j=-1; j<2; j++){
                //cout<<endl<<"next: "<<i<<"  "<<j;
                if(i == 0 && j == 0){
                    continue;
                }
                int col = location[1] + j;
                //cout<<"  "<<row<<"  "<<col<<"  "<<numMines;
                if(!insideMap(row, col)){
                    continue;
                }
                if(board[row][col]=='M'){
                    numMines++;
                }
                else{
                    vector<int> newLoc;
                    newLoc.push_back(row);
                    newLoc.push_back(col);
                    newLocations.push_back(newLoc);
                }
            }
        }
        //cout<<"mines are: "<<numMines<<endl;
        if(numMines>0){
            char mines = numMines + '0';
            //cout<<"mines are: "<<numMines<<", "<<mines<<endl;
            board[location[0]][location[1]] = mines;
        }
        else{
            for(list<vector<int>>::iterator it=newLocations.begin();it!=newLocations.end();it++){
                openList->push_back(*it);
                //cout<<(*it)[0]<<"  "<<(*it)[1]<<endl;
            }
            board[location[0]][location[1]] = 'B';
        }
        return board;
    }
    
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        height = board.size();
        width = board[0].size();
        list<vector<int>> openList;
        if(board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        openList.push_back(click);
        //cout<<"height: "<<height<<"  width:  "<<width<<endl;
        while(!openList.empty()){
            vector<int> currentHead = openList.front();
            //cout<<currentHead[0]<<"  "<<currentHead[1]<<endl;
            expand(board, &openList, currentHead);
            openList.pop_front();
        }
        return board;
    }
};