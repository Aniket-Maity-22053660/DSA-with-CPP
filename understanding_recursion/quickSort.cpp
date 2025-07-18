#include <iostream>
#include <vector>
using namespace std;

// Lomuto Partition Function
int partition(vector<int> &vec, int s, int e) {
   // int pivot = vec[e];  // Use last element as pivot
    int pivot = vec[s]; //use first element as pivot
    int i = e + 1;

    /*for (int j = s; j <= e; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    */
    for(int j = e ; j >=s ; j--){
        if(vec.at(j) >= pivot){
            i--;
            swap(vec.at(j), vec.at(i));
        }
    }


    //swap(vec[i + 1], vec[s]);  // Place pivot in correct position
    return i;
}

// QuickSort Function
void quickSort(vector<int> &vec, int s, int e) {
    if (s < e) {
        int p = partition(vec, s, e);
        quickSort(vec, s, p - 1);
        quickSort(vec, p + 1, e);
    }
}

int main() {
    vector<int> vec{1, 3, 2, 5, 3, 6, 4, 7, 3, 1, 89};

    cout << "Before sorting: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    quickSort(vec, 0, vec.size() - 1);

    cout << "After sorting: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
