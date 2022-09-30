#include <iostream>
#define MAX_DATA 100000

using namespace std;

template <typename T>

class Deque {
    private :
        int data[MAX_DATA * 2];
        int head;
        int tail;

    public :
        Deque() {
            head = MAX_DATA;                        //양쪽에서 삽입과 삭제가 이루어져야하기때문에 전체 배열의 사이즈의 중간위치로 초기화된다.
            tail = MAX_DATA;                        //마찬가지로 중간 위치로 초기화된다.
                                                    //덱이 비어있을땐 head와 tail이 같은 위치를 가리키고있다.
        }

        void push_front(T input) {                  
            this->data[this->head - 1] = input;     //head의 한칸 앞에 값을 넣어준다.
            this->head--;                           //head를 앞으로 한칸 옮겨준다.
        }

        void push_back(T input) {                   //tail의 위치에 값을 넣어준다.
            this->data[this->tail] = input;         //tail은 항상 값의 + 1을 가리키고있다.
            this->tail++;
        }

        void pop_front() {                          
            this->head++;                           //그냥 포인터만 옮겨주면된다.
        }

        void pop_back() {
            this->tail--;                           //동일
        }

        int size() {
            return this->tail - this->head;         //tail - head = size
        }

        bool empty() {
            if(this->size() == 0) {
                return true;
            }
            else {
                return false;
            }
        }

        T front() {
            return data[head];
        }

        T back() {
            return data[tail - 1];
        }
};
