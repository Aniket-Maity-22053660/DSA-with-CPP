#include<iostream>
#include<vector>


using namespace std;

class NQueen{
    vector<vector<string>> ans;
    vector<string> vec;
    int n;
    bool isSafe(vector<string> &vec, int row, int col, int n){
        for(int i = row - 1 ; i >= 0 ; i--){
            if(vec[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = row - 1, j = col - 1 ; i >= 0 && j >= 0 ; i--, j--){
            if(vec[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = row - 1, j =  col + 1 ; i >= 0 && j < n ; i--, j++){
            if(vec[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solveUtil(vector<string> &vec, int row, int n){
        if(row == n){
            ans.push_back(vec);
            return;
        }
        for(int i = 0 ; i < n ; i++){
            if(isSafe(vec, row, i, n)){
                vec[row][i] = 'Q';
                solveUtil(vec, row + 1, n);
                vec[row][i] = '.';
            }
        }
        return;
    }
    void printAns(){
        for(int i = 0 ; i < ans.size() ; i++){
            vector<string> vec = ans.at(i);
            for(string str : vec){
                cout<<str<<endl;
            }
            cout<<'\n';
        }
    }
    public:
    NQueen(){
        cout<<"Enter the number of queens: ";
        cin>>n;
        vec.resize(n, string(n, '.'));
    }

    void solveNQueen(){
        solveUtil(vec, 0, n);
        printAns();
    }
};

int main(){

    NQueen* obj = new NQueen();
    cout<<"Solving for the N-Queens problem!"<<endl<<endl;
    obj->solveNQueen();
    return 0;
}