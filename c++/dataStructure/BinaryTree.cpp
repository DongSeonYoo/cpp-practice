#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct node {
    string position;    //직책
    node* first;        //첫번째 자식 노드
    node* second;       //둘번째 자식 노드
};

struct org_tree {           //새로운 트리를 만드는 정적 함수. 
    node* root;

    static org_tree create_org_structure(const string& pos) {
        org_tree tree;
        tree.root = new node {pos, NULL, NULL};
        return tree;
    }

    static node* find(node* root, const string& value) {        //특정 직책 이름에 해당하는 노드를 찾아서 반환하는 함수
        if(root == NULL)
            return NULL;

        if(root->position == value) {                           //가장먼저 루트노드를 검사.
            return root;
        }
                                                                //만약 루트노드에서 찾지 못했다면.
        auto firstFound = org_tree::find(root->first, value);   //왼쪽 서브트리(첫번째 자식)에서 다시 찾으려고 시도

        if(firstFound != NULL) {                                //시도
            return firstFound;
        }

        return org_tree::find(root->second, value);             //그래도 찾지 못했다면 오른쪽 서브트리도 검사.
    }

    //부하 직원을 추가하는 함수, 상사의 직책 이름과 부하직원의 직책 이름을 인자로 받음, 상사의 직책은 이미 트리에 존재한다.
    bool addSubordinate(const string& manager, const string& subordinate) {
        auto managerNode = org_tree::find(root, manager);

        if(!managerNode) {                                  //만약 상위노드가 없으면
            cout << manager << "를 찾을 수 없습니다." << endl;  // 출력
            return false;                                  //false 반환
        }

        if(managerNode->first && managerNode->second) {    //만약 상위노드에 first와 second 둘다 존재한다면.
            cout << manager << "아래에 " << subordinate << "를 추가할 수 없습니다." << endl;    //출력 (이진트리는 자식을 두개밖에 가질 수 없음.)
            return false;                                  //false 반환
        }

        if(!managerNode->first) {                                       //만약 첫번째 자식이 비어있으면
            managerNode->first = new node {subordinate, NULL, NULL};    //첫번째 자식에 노드 생성
        }
        else {                                                          //만약 두번째 자식이 비어있으면
            managerNode->second = new node {subordinate, NULL, NULL};   //두번째 자식에 노드 생성
        }
        cout << manager << "아래에 " << subordinate << "를 추가했습니다. " << endl;

        return true;                                                    //함수 종료
    }

    static void preOrder(node* start) {      //전위 순회 구현, 
        if(!start)
            return;

        cout << start->position << ",";
        preOrder(start->first);
        preOrder(start->second);
    }

    static void inOrder(node* start) {      //중위 순회 구현
        if(!start) 
            return;

        inOrder(start->first);
        cout << start->first << ",";
        inOrder(start->second);
    }

    static void postOrder(node* start) {    //후위 순회 구현
        if(!start) {
            return;
        }

        postOrder(start->first);
        postOrder(start->second);
        cout << start->position << ",";
    }

    static void levelOrder(node* start) {   //레벨 순서 순회 구현
        if(!start) {
            return;
        }

        queue<node*> q;                 //STL queue 생성
        q.push(start);         

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                auto current = q.front();           //부모노드 방문
                q.pop();                            //자식노드로 내려감

                cout << current->position << ",";   //부모노드의 직책을 출력.
                if(current->first) {                //만약 첫째자식이 있으면
                    q.push(current->first);         //첫째자식의 노드를 넣어줌
                }
                if(current->second) {               //만약 둘재자식이 있으면
                    q.push(current->second);        //둘째자식의 노드를 넣어줌
                }
                cout << endl;
            }
        }
    }
};

int main() {

    auto tree = org_tree::create_org_structure("CEO");                  //root노드를 CEO로 초기화.

    tree.addSubordinate("CEO", "부사장");
    tree.addSubordinate("부사장", "IT부장");
    tree.addSubordinate("부사장", "마케팅부장");
    tree.addSubordinate("IT부장", "보안팀장");
    tree.addSubordinate("IT부장", "앱개발팀장");
    tree.addSubordinate("마케팅부장", "물류팀장");
    tree.addSubordinate("마케팅부장", "홍보팀장");
    tree.addSubordinate("부사장", "재무부장");

    tree.preOrder(tree.root->first);            //전위순회
    cout << endl;
    tree.inOrder(tree.root->first);             //중위순회
    cout << endl;
    tree.postOrder(tree.root->first);           //후위순회

    cout << endl;

    tree.levelOrder(tree.root);                 //레벨순서순회
}