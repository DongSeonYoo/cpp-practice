#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Hash_map {
    vector<list<int>> data;

    public:
        Hash_map(size_t n) {
            data.resize(n);
        }

        void insert(size_t value) {
            int n = data.size();
            data[value % n].push_back(value);
            cout << value << " 를 삽입했습니다." << '\n';
        }

        bool find(size_t value) {
            int n = data.size();
            auto &cnt = data[value % n];
            return std::find(cnt.begin(),cnt.end(), value) != cnt.end();
        }

        void erase(size_t value) {
            int n = data.size();
            auto &cnt = data[value % n];
            auto it = std::find(cnt.begin(), cnt.end(), value);

            if(it != cnt.end()) {
                cnt.erase(it);
                cout << value << " 삭제" << '\n';
            }
        }
};

int main() {
    Hash_map hm(7);

    auto print = [&](int value) {
        if(hm.find(value))
            cout << value << "를 찾았습니다. " << '\n';

        else
            cout << value << "를 찾지 못했습니다 " << '\n';
    };

    hm.insert(2);
    hm.insert(25);
    hm.insert(10);

    hm.insert(100);
    hm.insert(55);

    print(100);
    print(2);

    hm.erase(2);
}