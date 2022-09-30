#include <iostream>
#define MAX_SIZE 100000

using namespace std;                              //FIFO

template <typename T>

// push
// pop
// size
// empty
// front
// end


class Queue{
    private :
        T data[MAX_SIZE];
        int front_idx;
        int back_idx;

    public :
        Queue() {
            front_idx = -1;
            back_idx = -1;
        }

        void push(T input) {
            this->data[this->back_idx + 1] = input;
        }

        void pop() {
            if(this->empty()) {
                return;
            }
            else {
                
            }
        }

        T size() {
            return this->back_idx - this->front_idx;
        }

        bool empty() {
            if(this->size == 0) {
                return true;
            }
            else {
                return false;
            }
        }

        T front() {
            
        }

        
};