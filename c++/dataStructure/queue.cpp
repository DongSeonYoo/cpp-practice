#include <iostream>
#define MAX_SIZE 100000

using namespace std;                              //FIFO

// push
// pop
// size
// empty
// front
// back

template <typename T>

class Queue {
    private :
        int data[MAX_SIZE];
        int head;                                     //queue의 front를 가리키고있는 포인터
        int tail;                                     //queue의 tail을 가리키고 있는 포인터

    public :
        Queue() {
            head = 0;
            tail = 0;
        }

        void push(T input) {
            this->data[this->tail + 1] = input;
            this->tail++;
        }

        void pop() {
            if(!this->empty()) {                      //queue가 비어있지 않으면
                head++;                               //head를 1증가시킴
            }
            else {
                return;
            }
        }

        int size() {
            return this->tail - this->head;
        }

        bool empty() {
            if(this->tail - this->head == 0) {
                return true;
            }
            else {
                return false;
            }
        }

        T front() {
            return this->data[head + 1];
        }

        T back() {
            return this->data[tail];
        }
};