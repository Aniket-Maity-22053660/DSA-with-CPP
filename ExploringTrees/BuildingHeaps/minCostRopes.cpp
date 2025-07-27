#include<iostream>
#include<queue>

using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        int totalCost = 0;
        for(int i : arr){
            pq.push(i);
        }
        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int sum = first + second;
            totalCost += sum;
            pq.push(sum);
        }
        return totalCost;
    }
};

int main(){
    return 0;
}