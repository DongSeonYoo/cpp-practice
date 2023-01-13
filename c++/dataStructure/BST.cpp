#include <iostream>

using namespace std;

struct node {      //노드 구조체
    int data;
    node* left;
    node* right;
};

struct BST
{
    node* root = nullptr;

    node* find(int value) {
        return find_impl(root, value);
    }

    private:
        node* find_impl(node* current, int value) {                 //검색
            if(!current) {                                          //만약 현재 노드가 없으면
                cout << endl;                                       
                return NULL;                                        //탈출
            }

            if(current->data == value) {                            //현재노드와 찾는값이 일치하면
                cout << value << "를 찾았습니다." << endl;
                return current;                                     //반환
            }

            if(value < current->data) {                             //만약 찾는값이 현재노드보다 작으면
                cout << current->data << "에서 왼쪽으로 이동" << endl;  
                return find_impl(current->left, value);             //재귀를 이용해 첫째자식에게 접근
            }

            else {                                                  //만약 찾는값이 현재노드보다 크다면
                cout << current->data << "에서 오른쪽으로 이동" << endl;
                return find_impl(current->right, value);            //재귀를 이용해 둘째자식에게 접근
            }
        }                                                           //재귀함수를 이용하여 조건을 만족할때까지 자식노드로 파고든다..

    public:
        void insert(int value) {                                    //삽입함수
            if(!root) {                                             //만약 루트가 없다면
                root = new node {value, NULL, NULL};                 //param으로 받은 value를 루트로 생성
            }
            else {                                                  //루트가 있다면
                insert_impl(root, value);                           //삽입 실행
            }
        }

    private:
        void insert_impl(node* current, int value) {                //삽입
            if(value < current->data) {                             //만약 넣고싶은 값이 현재노드보다 작다면?
                if(!current->left) {                                //현재노드가 첫째자식을 가지고있지 않다면
                    current->left = new node {value, NULL, NULL};    //현재노드의 첫째자식으로 생성      (둘째자식이 없으니깐)
                }
                else {                                              //만약 현재노드가 첫째자식을 가지고있다면 
                    insert_impl(current->left, value);              //재귀를 이용해 노드의 자식들에게 접근한다. (첫째자식을 가지고있지 않은 노드를 찾아서....)
                }
            }
            else {                                                  //만약 넣고싶은 값이 현재노드보다 크다면? (value > current->data)
                if(!current->right) {                               //현재노드가 둘째자식을 가지고있지 않다면
                    current->right = new node {value, NULL, NULL};   //현재노드의 둘째자식으로 생성      (둘째자식이 없으니깐)
                }
                else {                                              //만약 현재노드가 둘째자식을 가지고있다면?
                    insert_impl(current->right, value);             //재귀를 이용해 노드의 자식들에게 접근한다. (둘째자식을 가지고있지 않은 노드를 찾아서....)
                }
            }
        }

    public:
        void inorder() {                                            //중위 순회
            inorder_impl(root);
        }
    
    private:
        void inorder_impl(node* start) {                            
            if(!start) {                                            //만약 루트노드가 없으면
                return;                                             //함수탈출
            }
            inorder_impl(start->left);                              //첫째 자식 방문
            cout << start->data << " ";                             //현재 노드 출력
            inorder_impl(start->right);                             //둘째 자식 방문
        }

    public:
        node* successor(node* start) {                              //후손 노드를 찾는 함수
            auto current = start->right;
            while(current && current->left) {
                current = current->left;
            }
            return current;
        }

        void deleteValue(int value) {
            root = delete_imple(root, value);
        }
    
    private:
        node* delete_imple(node* start, int value) {
            if(!start) 
                return NULL;

            if(value < start->data) 
                start->left = delete_imple(start->left, value);
            
            if(value > start->data)
                start->right = delete_imple(start->right, value);
            
            else
                if(!start->left) {
                    auto temp = start->right;
                    delete start;
                    return temp;
                }

                if(!start->right) {
                    auto temp = start->left;
                    delete start;
                    return temp;
                }

                auto succNode = successor(start);
                start->data = succNode->data;

                start->right = delete_imple(start->right, succNode->data);
        return start;
        }
};

int main() {

    BST tree;

    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);
    tree.insert(12);

    cout << "중위 순회 : ";
    tree.inorder();
    cout << endl;

    tree.deleteValue(12);
    cout << "12를 삭제한 후 중위 순회 : ";
    tree.inorder();
    cout << endl;

    if(tree.find(12)) {
        cout << "원소 12는 트리에 있습니다." << endl;
    }
    else {
        cout << "원소 12는 트리에 없습니다 yes ." << endl;
    }
}