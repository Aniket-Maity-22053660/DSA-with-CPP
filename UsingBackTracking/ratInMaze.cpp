#include<iostream>
#include<vector>
using namespace std;

class RatInMaze{
    vector<vector<int>> maze;
    int rowEnd, colEnd;
    vector<vector<vector<int>>> ans;
    vector<vector<int>> visited;

    void solveUtil(int rowCurr, int colCurr){
        if(rowCurr == rowEnd && colCurr == colEnd){
            ans.push_back(maze);
            return;
        }

        if(rowCurr + 1 < maze.size() && visited[rowCurr + 1][colCurr] != 1 && maze[rowCurr + 1][colCurr] != 0){
            int prev = maze[rowCurr + 1][colCurr];
            maze[rowCurr + 1][colCurr] = 7;
            visited[rowCurr + 1][colCurr] = 1;
            solveUtil(rowCurr + 1, colCurr);
            maze[rowCurr + 1][colCurr] = prev;
            visited[rowCurr + 1][colCurr] = 0;
        }

        if(colCurr - 1 >= 0 && visited[rowCurr][colCurr - 1] != 1 && maze[rowCurr][colCurr - 1] != 0){
            int prev = maze[rowCurr][colCurr - 1];
            maze[rowCurr][colCurr - 1] = 7;
            visited[rowCurr][colCurr - 1] = 1;
            solveUtil(rowCurr, colCurr -1);
            maze[rowCurr][colCurr - 1] = prev;
            visited[rowCurr][colCurr - 1] = 0;
        }
        if(colCurr + 1 < maze[0].size() && visited[rowCurr][colCurr + 1] != 1 && maze[rowCurr][colCurr + 1] != 0){
            int prev = maze[rowCurr][colCurr + 1];
            maze[rowCurr][colCurr + 1] = 7;
            visited[rowCurr][colCurr + 1] = 1;
            solveUtil(rowCurr, colCurr + 1);
            maze[rowCurr][colCurr + 1] = prev;
            visited[rowCurr][colCurr + 1] = 0;
        }
        if(rowCurr - 1 >= 0 && visited[rowCurr - 1][colCurr] != 1 && maze[rowCurr - 1][colCurr] != 0){
            int prev = maze[rowCurr - 1][colCurr];
            maze[rowCurr - 1][colCurr] = 7;
            visited[rowCurr - 1][colCurr] = 1;
            solveUtil(rowCurr - 1, colCurr);
            maze[rowCurr - 1][colCurr] = prev;
            visited[rowCurr - 1][colCurr] = 0;
        }
        return;
    }
    void printAns(){
        for(vector<vector<int>> x : ans){
            for(vector<int> y : x){
                for(int z : y){
                    cout<<z<<" ";
                }
                cout<<'\n';
            }
            cout<<'\n';
        }
    }
    public:
    RatInMaze(vector<vector<int>> vec){
        maze = vec;
        rowEnd = maze.size() - 1;
        colEnd = maze[0].size() - 1;
        visited.resize(maze.size(), vector<int>(maze[0].size(), 0));
    }

    void solveRatInMaze(){
        visited[0][0] = 1;
        maze[0][0] = 7;
        solveUtil(0, 0);
        printAns();
    }
};

int main(){
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    cout<<"Solving the Rat in Maze problem!"<<endl<<endl;
    RatInMaze* obj = new RatInMaze(maze);
    obj->solveRatInMaze();
    return 0;
}