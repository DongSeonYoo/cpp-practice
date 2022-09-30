#include <iostream>
#define MAX_SIZE 100000

using namespace std;

template <typename T>

class Stack {
    private :
        T data[MAX_SIZE];
        int idx;

    public :
        Stack() {
            idx = -1;
        }

        void push(T input) {
            data[idx] = input;
            idx++;
        }

        T pop() {
            T result = data[idx];
            idx--;
            return result;
        }

        int size() {
            return idx + 1;
        }

        bool empty() {
            if(this->size == 0) {
                return true;
            }
            else {
                return false;
            }
        }

        T top() {
            T result = data[idx];
            return result;
        }
};

int main() {

    Stack<int> s;

    cout << "size : " << s.size() << endl;
    
}