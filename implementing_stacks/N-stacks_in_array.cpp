#include<iostream>
#include<vector>
using namespace std;

template<class T>
class N_Stacks{
    int arrSize;
    int N;
    int stackSize;
    vector<int> partition;
    vector<int> stackTop;
    public:
    T* arr;
    N_Stacks(int arrSize, int N){
        this->arrSize = arrSize;
        this->N = N;
        partition.resize(N);
        stackTop.resize(N);
        arr = new T[arrSize];
        stackSize = arrSize / N;
        
        int num = -1;
        for(int i = 0 ; i < N ; i++){
        partition[i] = num;
        num += stackSize;
        }
        
        for(int i = 0 ; i < N ; i++){
        stackTop[i] = partition[i];
        }
    }

    ~N_Stacks(){
        delete [] arr;
    }

    void push(T element, int stackNo);
    T pop(int stackNo);
    bool isEmpty(int stackNo);
    T top(int stackNo);
};
template<class T>
void N_Stacks<T>::push(T element, int stackNo){
    if(stackTop[stackNo-1] <= (partition[stackNo-1] + stackSize)-1){
        stackTop[stackNo-1] += 1;
        arr[stackTop[stackNo-1]] = element;
    }else{
        cout<<"Stack overflow from stack "<<stackNo<<endl;
    }
}

template<class T>
T N_Stacks<T>::pop(int stackNo){
    if(stackTop[stackNo-1] > partition[stackNo-1]){
        T element = arr[stackTop[stackNo-1]];
        stackTop[stackNo-1] -= 1;
        return element;
    }
    else{
        cout<<"Stack underflow from stack "<<stackNo<<endl;
        return T();
    }
}

template<class T>
bool N_Stacks<T>::isEmpty(int stackNo){
    if(stackTop[stackNo-1] == partition[stackNo-1]){
        return true;
    }else{
        return false;
    }
}
template<class T>
T N_Stacks<T>::top(int stackNo){
    return arr[stackTop[stackNo-1]];
}
int main(){
    int arrSize, N;
    cout<<"Provide the length of the array: ";
    cin>>arrSize;
    vector<int> vec(arrSize);
    cout<<"Provide the number of stacks: ";
    cin>>N;
    N_Stacks<int> nst(arrSize, N);


    return 0;
}