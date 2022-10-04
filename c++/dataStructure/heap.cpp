#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct median {         //중앙값 구하기
    priority_queue<int> maxHeap;                              //default값으로 maxHeap을 priority로 갖는 priority queue 생성
    priority_queue<int, vector<int>, greater<int>> minHeap;   //minHeap으로 priority queue 생성

    void insert(int data) {       
        if(maxHeap.size() == 0) {                             //만약 maxHeap이 비어있으면
            maxHeap.push(data);                               //maxHeap 먼저 parmam을 넣어준다.
            return;
        }

        if(maxHeap.size() == minHeap.size()) {                //maxHeap과 minHeap의 갯수가 같다면
            if(data <= get())                                 //maxHeap 과 minHeap의 중앙값과 비교하여 param이 중앙값보다 작거나 같다면
                maxHeap.push(data);                           //maxHeap에 push
            else                                              //param이 중앙값보다 크다면
                minHeap.push(data);                           //minHeap에 push
            return;
        }

        if(maxHeap.size() < minHeap.size()) {                 //maxHeap이 minHeap보다 작으면
            if(data > get()){                                  //param가 minHeap의 leap(제일 큰값)보다 크다면 (queue이기때문에 minHeap에서의 top은 제일 큰 값이다.)
                maxHeap.push(minHeap.top());                  //minHeap의 leap(제일 큰 값)을 maxHeap에 push 해준다.
                minHeap.pop();                                //miniHeap의 leap(제일 큰 값)을 제거
                minHeap.push(data);                           //miniHeap의 leap(제일 큰 값)에 삽입                      *다시보니 swap과정이네요 
            }

            else                                              //maxHeap이 minHeap보다 작으면서 && param이 중앙값보다 작다면
                maxHeap.push(data);                           //그냥 maxHeap에 푸시해주면 된다.
                return;
        }

        if(data < get()) {                                    //maxHeap이 miniHeap보다 크면서 && param이 중앙값보다 작다면
            minHeap.push(maxHeap.top());                      //maxHeap의 leap(제일 작은 값)을 minHeap에 push해준다
            maxHeap.pop();                                    //maxHeap의 leap(제일 작은 값)을 하나 빼준다.
            maxHeap.push(data);                               //maxHeap에 param을 push해준다.
        }
        else                                                  //maxHeap이 miniHeap보다 크면서 && param이 중앙값보다 크다면
            minHeap.push(data);                               //miniHeap애 param을 push해준다.                         *결론적으로 모든 경우의 수에서 중앙값과 param을 비교하고 swap을 진행한다.
    }

    double get() {                                            //중앙값을 구하는 함수 minHeap과 maxHeap의 중앙값을 리턴해줌
        if(maxHeap.size() == minHeap.size())                  //만약 maxHeap과 minHeap의 크기가 같으면
            return (maxHeap.top() + minHeap.top()) / 2.0;     //(maxHeap + minHeap) / 2 가 중앙값이다.
        
        if(maxHeap.size() < minHeap.size())                   //만약 minHeap의 size가 더 크면 miniHeap의 top이 중앙값이다.
            return minHeap.top();

        return maxHeap.top();                                 //만약 maxHeap의 size가 더 크면 maxHeap의 top이 중앙값이다.
    }
};

int main() {
    median md;

    md.insert(1);

    cout << "1 삽입 후 중앙값 : " << md.get() << endl;

    md.insert(5);
    cout << "5 삽입 후 중앙값 : " << md.get() << endl;
    
    md.insert(2);
    cout << "2 삽입 후 중앙값 : " << md.get() << endl;
 }