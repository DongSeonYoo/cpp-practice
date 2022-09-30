#include <iostream>
#include <stack>

#define MAX_SIZE 100000

using namespace std;

template <typename T>


class Stack {
    private :
        T data[MAX_SIZE];
        int idx;                    //스택의 인덱스(top을가리킴)

    public :                        //생성자
        Stack() {
            idx = -1;
        }

        void push(T input) {        //push
            this->data[this->idx + 1] = input;
            this->idx++;
        }

        void pop() {                //pop
            if(this->empty()) {
                return;
            }
            else {
                this->idx--;
            }
        }

        int size() {                //size
            return idx + 1;
        }

        bool empty() {              //empty
            if(this->size() == 0) {
                return true;
            }
            else {
                return false;
            }
        }

        T top() {                   //top
            T result = data[idx];
            return result;
        }
};

int main() {


Stack <int> s;

s.push(1);
s.pop();
s.pop();
s.pop();

s.push(2);
}
// 스택의 원소를 모두출력하는 메서드를 만들고싶었는데 그럴거면 스택을쓰는 의미가없구나싶었다 그럴빠엔 vector나 list를 사용하자