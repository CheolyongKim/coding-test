#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

void debug1(auto x){
    for (int i=0; i<x.size(); i++){
        for (int j=0; j<x.at(i).size(); j++)
            cout << x.at(i).at(j) << " ";
        cout << "\n";
    }
    cout << "\n\n\n";
}

bool comp(vector<int> a, vector<int> b){
    if (a.at(1) > b.at(1)){
        return true;
    }else if (a.at(1) < b.at(1)){
        return false;
    }else{
        return a.at(0) < b.at(0);
    }
}

struct Node{
    int v, idx;
    Node* l; Node* r; // left, right
    //Node* parent;
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    // 좌표 -> 트리 정보 변환
    // ====================
    // y로 깊이는 정해짐
    // x는 모두 다름, 그리고 이진트리이기 때문에 항상 부모 개수 * 2 이하
    
    // order by Y asc, X asc
    for (int i = 0; i < nodeinfo.size(); i++)
        nodeinfo.at(i).push_back(i+1);
    sort(nodeinfo.begin(), nodeinfo.end(), comp);
    
    //debug1(nodeinfo);
    
    // make tree
    Node* root = NULL;
    for (int i = 0; i < nodeinfo.size(); i++){
        Node* n = new Node();
        int curval = nodeinfo.at(i).at(0);
        n->idx = nodeinfo.at(i).at(2);
        n->v = curval;
        if (root == NULL){
            root = n;
        }else{
            // insert
            Node* ptr = root;
            while (!((curval < ptr->v && ptr->l == NULL) || (curval > ptr->v && ptr->r == NULL))){
                ptr = (curval < ptr->v) ? ptr->l : ptr->r;
            }
            if (curval < ptr->v) ptr->l = n;
            else ptr->r = n;
        }
    }
    
    // 트리 정보 -> 순회 결과
    vector<int> preorder, postorder;
    // ===================
    vector<bool> visited(nodeinfo.size()+1, false);
    // 전위 순회
    stack<Node*> s;
    s.push(root);
    while (!s.empty()){
        Node* ptr = s.top();
        if (!visited.at(ptr->idx)) preorder.push_back(ptr->idx);
        visited.at(ptr->idx) = true;
        if (ptr->l != NULL && !visited.at(ptr->l->idx)){
            s.push(ptr->l);
            ptr = ptr->l;
            continue;
        }
        if (ptr->r != NULL && !visited.at(ptr->r->idx)){
            s.push(ptr->r);
            ptr = ptr->r;
            continue;
        }
        s.pop();
    }
    
    // 후위 순회
    while (!s.empty()) s.pop();
    visited.clear();
    visited.resize(nodeinfo.size()+1, false);
    s.push(root);
    // dfs-like
    while (!s.empty()){
        Node* ptr = s.top();
        visited.at(ptr->idx) = true;
        if (ptr->l != NULL && !visited.at(ptr->l->idx)){
            s.push(ptr->l);
            ptr = ptr->l;
            continue;
        }
        if (ptr->r != NULL && !visited.at(ptr->r->idx)){
            s.push(ptr->r);
            ptr = ptr->r;
            continue;
        }
        postorder.push_back(s.top()->idx);
        s.pop();
    }
    
    answer.push_back(preorder);
    answer.push_back(postorder);
    
    return answer;
}