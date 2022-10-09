#include <iostream>
#include <vector>

using namespace std;

class Hash_map {

    vector<int> data;

    public :
    Hash_map(size_t size) {
        data = vector<int>(size, -1);
    }

    void insertion(size_t num) {
        int size = data.size();

        data[num % size] = num;
        cout << num << " 삽입" << '\n';
    }

    void erase(size_t num) {
        int size = data.size();

        if(data[num % size] == num) {
            data[num % size] = -1;

            cout << num << " 을 삭제 " << '\n';
        }
        else
            cout << num << " 에 해당하는 숫자가 없습니다" << '\n';
    }

    bool find(size_t num) {
        return (data[num % data.size()] == num);
    }
};

int main() {

    Hash_map hash_map(7);

    auto print_find_result = [&](int value) {
        if(hash_map.find(value)) 
            cout << value << " 를 찾았습니다. " << '\n';

        else
            cout << value << " 를 찾지 못했슴. "<< '\n';
    };

    hash_map.insertion(2);
    hash_map.insertion(25);
    hash_map.insertion(10);
    print_find_result(25);

    hash_map.insertion(100);
    print_find_result(100);
    print_find_result(2);

    //100을 삽입하면 100 % 7 == 2 이기때문에 처음에 넣었던 2를 덮어씌게된다. (Hash Collision)
    //hash collision을 원인이무엇이고 어떻게해결할까? 방지하게위해 어떻게 코드를 짜야하고 어떤 라이브러리를 긁어올까?
}