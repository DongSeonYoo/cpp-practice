#include <bits/stdc++.h>

using namespace std;


vector<string> split(string input, string delimeter) {

    vector<string> resultVector;
    long long pos = 0;
    string token = "";

    while((pos = input.find(delimeter)) != string::npos) {

        token = input.substr(0, pos);
        resultVector.push_back(token);
        input.erase(0, pos + delimeter.length());
    }

    resultVector.push_back(input);

    return resultVector;
}

int main() {

    vector<string> str;
    string input = "유.동.선,동.유";    // 기댓값 : 유 동 선,동 유

    str = split(input, ".");

    for(auto a : str) {
        cout << a << ' ';            // 출력값 : 유 동 선,동 유
    }
}