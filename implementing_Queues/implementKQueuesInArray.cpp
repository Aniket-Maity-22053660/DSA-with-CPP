#include<iostream>
#include<queue>
#include<vector>

using namespace std;

template<class T>
class Queue{
    
    T*arr;
    
    vector<int> partition;
    vector<int> front;
    vector<int> rear;

    public:
    int qSize;
    Queue(int arrSize,int K){
        this->qSize = arrSize / K;
        partition.resize(K);
        front.resize(K);
        rear.resize(K);
        int num = -1;
        for(int i = 0 ; i < K ; i++){
            partition[i] = num;
            num = num + qSize;
        }
        for(int i = 0 ; i < K ; i++){
            front[i] = partition[i];
        }
        for(int i = 0 ; i < K ; i++){
            rear[i] = partition[i];
        }
        arr = new T[arrSize];
    }
    void push(int qNo, int element);
    T pop(int qNo);
    void Size(int qNo);
    void Front(int qNo);
    void Rear(int qNo);
    bool isEmpty(int qNo);
    ~Queue(){
        delete []arr;
    }
};

template<class T>
void Queue<T>::push(int qNo, int element){
    if((partition[qNo - 1] + 1) + ((rear[qNo - 1]+1)%qSize) != front[qNo - 1]){
        if(rear[qNo - 1] == partition[qNo - 1]){
            front[qNo - 1] = (front[qNo - 1] + 1) % qSize + (partition[qNo - 1] + 1);
        }
        rear[qNo - 1] = (rear[qNo - 1] + 1)%qSize + (partition[qNo - 1] + 1);
        arr[rear[qNo - 1]] = element;
    }else{
        cout<<"Queue overflow!"<<endl;
    }
}

template<class T>
T Queue<T>::pop(int qNo){
    if(front[qNo - 1] != partition[qNo - 1] && rear[qNo - 1] != partition[qNo - 1]){
        T element = arr[front[qNo - 1]];
        if(front[qNo - 1] != rear[qNo - 1]){
            front[qNo - 1] = (partition[qNo - 1] + 1) + ((front[qNo - 1])+1) % qSize;
        }else{
            front[qNo - 1] = partition[qNo - 1];
            rear[qNo - 1] = partition[qNo - 1];
        }
        return element;
    }else{
        cout<<"Queue underflow!"<<endl;
        return T();
    }
}

template<class T>
void Queue<T>::Size(int qNo){
    if(front[qNo - 1] == partition[qNo - 1] && rear[qNo - 1] == partition[qNo - 1]){
        cout<<"Queue "<<qNo<<" is empty!"<<endl;
        return;
    }else{
        if(rear[qNo - 1] < front[qNo - 1]){
            cout<< "Size of queue "+to_string(qNo)+to_string(qSize - ((front[qNo - 1] - rear[qNo - 1])+1));
        }else if(rear[qNo - 1] == front[qNo - 1]){
            cout<< "Size of queue "+to_string(qNo) + ": "+to_string(1);
        }else{
            cout<< "Size of queue " + to_string(qNo) + ": " + to_string((rear[qNo - 1] - front[qNo - 1])+1);
        }
    }
}

template<class T>
void Queue<T>::Front(int qNo){
    if(front[qNo - 1] == partition[qNo - 1]){
        cout<< "Queue " + to_string(qNo) + " is empty!";
    }else{
        cout<< "Front of queue "+to_string(qNo)+": "+to_string(arr[front[qNo - 1]]);
    }
}

template<class T>
void Queue<T>::Rear(int qNo){
    if(rear[qNo - 1] == partition[qNo -1]){
        cout<< "Queue "+to_string(qNo)+" is empty!";
    }else{
        cout<< "Rear of queue "+to_string(qNo)+": "+to_string(arr[rear[qNo - 1]]);
    }
}
template<class T>
bool Queue<T>:: isEmpty(int qNo){
    if(front[qNo - 1] == partition[qNo - 1] && rear[qNo - 1] == partition[qNo - 1]){
        return true;
    }else{
        return false;
    }
}

int main() {
    int arrSize, K;
    cout << "Enter the size of the array: ";
    cin >> arrSize;
    cout << "Enter the value of K (number of queues): ";
    cin >> K;

    Queue<int> q(arrSize, K);

    // Test pushing to multiple queues
    q.push(1, 10);
    q.push(1, 20);
    q.push(2, 100);
    q.push(2, 200);
    q.push(3, 300); // This works if K >= 3

    // Display front and rear for queue 1
    q.Front(1); cout << endl;
    q.Rear(1);  cout << endl;
    q.Size(1);  cout << endl;

    // Pop an element from queue 1
    cout << "Popped from queue 1: " << q.pop(1) << endl;
    q.Front(1);
    cout << endl;
    q.Size(1);
    cout<<"\n";
    // Check if a queue is empty
    cout << "Is queue 3 empty? " << (q.isEmpty(3) ? "Yes" : "No") << endl;

    // Display size of queue 2
    q.Size(2);  
    cout << endl;

    return 0;
}
