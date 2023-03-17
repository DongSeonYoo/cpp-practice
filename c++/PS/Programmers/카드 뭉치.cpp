#include <string>
#include <vector>

using namespace std;

// 1. goal의 길이만큼 돌아주며 cards1, cards2를 비교한다.
// 2. cards1과 goal의 문자열을 비교하고 만약 다른 문자열이 나오거나 cards1의 길이가 끝나면 cards2로 넘어간다.
// 3. cards2와 goal의 문자열을 비교하고 만약 다른 문자열이 나오거나 cards2의 길이가 끝나면 cards1로 넘어간다.
// 4. 이때 cards1의 길이가 끝나지 않았다면? -> 길이가 끝나거나 다른 문자열이 나올때까지 goal과 비교한다.
// 5. 이때 cards1의 길이가 끝나있다면? -> flag변수를 false로 정하고 루프를 빠져나온다.
// 6. flag가 true이면 Yes, false이면 No,


string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int length1 = 0;
    int length2 = 0;
    bool flag = true;

    for (int i = 0; i < goal.size(); i++) {                                 // 1.
      if (cards1[length1] == goal[i] && length1 < cards1.size()) {          // 2.
        length1++;
      } else if (cards2[length2] == goal[i] && length2 < cards2.size()) {   // 3.
        length2++;
      } else {                                                              // 5.
        flag = false;
        break;
      }
    }

    if (flag) {                                                             // 6.
      answer = "Yes";
    } else {
      answer = "No";
    }
    
    return answer;
}