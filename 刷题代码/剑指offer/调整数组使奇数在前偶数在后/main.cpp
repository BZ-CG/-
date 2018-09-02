#include <iostream>
#include <vector>
using namespace std;

void reOrderArray(vector<int> &arr) {
    vector<int> odd,even;
    for(int i = 0;i < arr.size();i++) {
        if (arr[i] & 1)
            odd.push_back(arr[i]);
        else
            even.push_back(arr[i]);
    }

    arr.clear();
    for(int i = 0;i < odd.size();i++)
        arr.push_back(odd[i]);
    for(int i = 0;i < even.size();i++)
        arr.push_back(even[i]);
}

int main(void) {
    vector<int> arr = {-2,1,2,3,4,5,6,7,8};
    reOrderArray(arr);

    for(int i = 0;i < arr.size();i++) {
        cout<<arr[i] <<" ";
    }
    cout<<endl;
    return 0;
}
