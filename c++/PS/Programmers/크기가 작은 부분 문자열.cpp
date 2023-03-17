#include <string>
#include <vector>

using namespace std;

// 11번라인 : (30분 헤맴)p를 stol함수를 이용해 long타입으로 변환해주는 pToInt변수를 선언해준다. (p의 최대길이는 18, int가 아닌 long으로 지정해줘야 한다.)
// 15번라인 : 얘도 마찬가지로 p의 자리수가 18자리가 되면 무지막지하게 커지기 때문에 substr한 값을 long타입으로 변환해줘야한다.

int solution(string t, string p) {
    int answer = 0;
    vector<int> v;
    long pToInt = stol(p);
    int pSize = p.size();
    
    for (int i = 0; i <= t.size() - pSize; i++) {
        long a = stol(t.substr(i, pSize));
        
        if (a <= pToInt) {
            v.push_back(a);
        }
    }
    
    answer = v.size();
    
    return answer;
}