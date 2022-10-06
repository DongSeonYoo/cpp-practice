#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
int partition(vector<T> &arr, int start, int end) {
    const auto &pivot = arr[end];      //피벗은 오른쪽 제일 끝
    vector<T> partitioned(end - start + 1);      //분할된 데이터 저장하는 벡터

    int left = 0;
    int right = end - start;

    for(int i = start; i <= end; i++) {
        if(arr[i] <= pivot) {           //피벗보다 작다면
            partitioned[left] = arr[i]; //피벗보다 작은값은 pivot왼쪽에
            left++;
        }
        else {                          //피벗보다 크다면
            partitioned[right] = arr[i];//피벗보다 큰값은 pivop오른쪽에
            right++;
        }
    }
    for(int i = start; i <= end; i++) {
        arr[i + start] = partitioned[i];
    }

    return right;       //피벗의 위치가 right가 되므로 피벗의 위치를 반환
}

void partition_test() {         //분할 test 함수
    vector<int> v = {3, 12 ,4 ,56 ,5 ,72, 123};

    int result = partition(v, 0, v.size() - 1);

    cout << result << " ";     //6 출력 (피벗의 위치. 정상출력 확인)
}

template <typename T>
void quick_sort(vector<T> &arr, int start, int end) {
    if(start >= end)
        return;

    int pivot_idx = partition(arr, start, end);     //아까 테스트했던 값 (파티션 후 피벗의 위치)
    quick_sort(arr, start, pivot_idx - 1);          //완전히 정렬될때까지 recursive
    quick_sort(arr, pivot_idx + 1, end);            //완전히 정렬될때까지 recursive
}

int main() {
    vector<int> v = {3, 12 ,4 ,56 ,5 ,72, 123};

    cout << "before : ";
    for(auto &a : v) {
        cout << a << " ";
    }
    cout << endl;
    
    quick_sort(v, 0, v.size() - 1);

    cout << "after : "; 
    for(auto &a : v) {
        cout << a << " ";
    }
}