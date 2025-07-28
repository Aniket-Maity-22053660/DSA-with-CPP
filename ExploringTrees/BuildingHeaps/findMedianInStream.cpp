#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class FindMedianInStream{
    vector<int> stream;
    vector<double> ans;
    int size;
    public:
    FindMedianInStream(){
        cout<<"Enter the size of the input stream: ";
        cin>>size;
        int element;
        for(int i = 0 ; i < size ; i++){
            cout<<"Enter the element-"<<(i+1)<<": ";
            cin>>element;
            stream.push_back(element);
        }
        cout<<"Given steam:-"<<endl;
        for(int i = 0 ; i < size ; i++){
            cout<<stream.at(i)<<" ";
        }
        cout<<'\n';
    }

    vector<double> findMedian(){
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num : stream){
            if(maxHeap.empty() || num <= maxHeap.top()){
                maxHeap.push(num);
            }else{
                minHeap.push(num);
            }

            if(maxHeap.size() - minHeap.size() > 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }else if(minHeap.size() > maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            if((maxHeap.size() + minHeap.size()) % 2 == 0){
                ans.push_back((minHeap.top() + maxHeap.top()) / 2.00);
            }else{
                ans.push_back(maxHeap.top());
            }
        }
        return ans;
    }
};

int main(){
    cout<<"Finding the median of a continuous stream:-"<<endl;
    FindMedianInStream* objMedian = new FindMedianInStream();
    vector<double> ans = objMedian->findMedian();
    cout<<"Median of the stream:-"<<endl;
    for(int i = 0 ; i < ans.size() ; i++){
        cout<<ans.at(i)<<" ";
    }
    cout<<'\n';
    return 0;
}