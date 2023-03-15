#include <string>
#include <vector>

using namespace std;

// 프로그래머스 대충 만든 자판
// 1. targets벡터 0번째 요소의 첫 글자부터 size - 1 요소를 저장할 변수(s)를 만들자
// 2. (s)변수가 keymap벡터의 몇번째 요소에 있는지 확인한다.
// 3. 변수에 저장한 후 keymap벡터를 돌아주면서 s의 최단 인덱스를 확인하고 최소값 변수(minimun)에 넣어준다
// 4. flag변수를 선언해 발견하면 flag를 true, 발견하지 못할시 false이기때문에 -1을 pushback

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for (int i = 0; i < targets.size(); i++) {
            answer.push_back(0); // 여기서 잠깐 막혔는데 targets의 개수만큼 answer를 0으로 초기화 (targets과 keymap의 개수는 항상 일치한다.)
        for (int j = 0; j < targets[i].size(); j++) {
            char s = targets[i][j];
            int minimumValue = 101;  //최솟값(인덱스)을 담을 변수 *keymap의 길이는 100을 넘지 않는다.
            bool flag = false;       //발견하지 못했을 시 -1을 넣어주기 위한 플래그변수
            
            for (int k = 0; k < keymap.size(); k++) {
                for (int l = 0; l < keymap[k].size(); l++) {
                    if (keymap[k][l] == s) {
                        minimumValue = min(minimumValue, l + 1);
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) {
                answer[i] = -1;
                break;
            }
            
            answer[i] += minimumValue;
        }
    }
    return answer;
}