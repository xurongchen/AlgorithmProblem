#define LL long long int
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;

char S[55][25];
LL C[55];

int nodeCount;
map<string, int> pre_str2NodeID;
map<string, int> suf_str2NodeID;
string nodeID2Str[2100]; 
bool Palindrome[2100];
LL Distance[2100];
bool Visit[2100];
int PRE_COUNT;
int N;

struct nextNode{
    int ne;
    LL weight;
    nextNode(int _n,LL _w):ne(_n),weight(_w){}
};

vector<nextNode> weight[2100];

int main() {
    N = 0;
    nodeCount = 1;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%s%lld", S[i], &C[i]);
    }

    pre_str2NodeID.clear();
    suf_str2NodeID.clear();

    Palindrome[0] = false;
    nodeID2Str[0] = "";
    for(int i = 0 ; i < N; ++i){ // make node, prefix
        int sl = strlen(S[i]);
        string str = S[i];
        for(int k = 0; k <= sl; ++k){
            string pre = str.substr(sl - k, k);
            if (pre_str2NodeID.count(pre) == 0){
                string preR = pre;
                reverse(preR.begin(), preR.end());
                if(pre.compare(preR) == 0 || pre.length() == 0){
                    Palindrome[nodeCount] = true;
                }
                else Palindrome[nodeCount] = false;
                nodeID2Str[nodeCount] = pre;
                pre_str2NodeID[pre] = nodeCount++;
                // cout << "[Trace] pre_str2NodeID[" << pre << "] =  " << nodeCount-1 << endl;
                // cout << "[Trace] Palindrome[" << nodeCount-1 << "] =  " << Palindrome[nodeCount-1] << endl;
            }
        }
    }

    PRE_COUNT = nodeCount;

    for(int i = 0 ; i < N; ++i){ // make node, suffix
        int sl = strlen(S[i]);
        string str = S[i];
        for(int k = 0; k <= sl; ++k){
            string suf = str.substr(0, k);
            if (suf_str2NodeID.count(suf) == 0){
                string sufR = suf;
                reverse(sufR.begin(), sufR.end());
                if(suf.compare(sufR) == 0 || suf.length() == 0){
                    Palindrome[nodeCount] = true;
                }
                else Palindrome[nodeCount] = false;
                nodeID2Str[nodeCount] = suf;
                suf_str2NodeID[suf] = nodeCount++;
                // cout << "[Trace] suf_str2NodeID[" << suf << "] =  " << nodeCount-1 << endl;
                // cout << "[Trace] Palindrome[" << nodeCount-1 << "] =  " << Palindrome[nodeCount-1] << endl;
            }
        }
    }


    for(int i = 0; i < N; ++i){
        string str = S[i];
        string strR = str;
        reverse(strR.begin(), strR.end());

        weight[0].push_back(nextNode(pre_str2NodeID[str], C[i]));
        weight[0].push_back(nextNode(suf_str2NodeID[str], C[i]));

        for(int j = 1; j < PRE_COUNT; ++j){
            string state = nodeID2Str[j];
            if(state.length() >= strR.length()){
                auto miss = mismatch(strR.begin(), strR.end(), state.begin());
                if(miss.first == strR.end()){
                    string suf = state.substr(strR.length(), state.length() - strR.length());
                    weight[j].push_back(nextNode(pre_str2NodeID[suf], C[i]));
                }
            }
            else {
                auto miss = mismatch(state.begin(), state.end(), strR.begin());
                if(miss.first == state.end()){
                    string suf = strR.substr(state.length(), strR.length() - state.length());
                    reverse(suf.begin(), suf.end());
                    weight[j].push_back(nextNode(suf_str2NodeID[suf], C[i]));
                }
            }
        }

        for(int j = PRE_COUNT; j < nodeCount; ++j){
            string state = nodeID2Str[j];
            reverse(state.begin(), state.end());
            if(state.length() >= str.length()){
                auto miss = mismatch(str.begin(), str.end(), state.begin());
                if(miss.first == str.end()){
                    string suf = state.substr(str.length(), state.length() - str.length());
                    reverse(suf.begin(), suf.end());
                    weight[j].push_back(nextNode(suf_str2NodeID[suf], C[i]));
                }
            }
            else {
                auto miss = mismatch(state.begin(), state.end(), str.begin());
                if(miss.first == state.end()){
                    string suf = str.substr(state.length(), str.length() - state.length());
                    // cout<<"[Debug] suf: "<<suf<<endl;
                    weight[j].push_back(nextNode(pre_str2NodeID[suf], C[i]));
                }
            }
        }
    }

    // shortest distance
    Distance[0] = 0;
    Visit[0] = false;

    for(int i = 1; i < nodeCount; ++i){
        Distance[i] = -1;
        Visit[i] = false;
    }

    for(int i = 0; i < nodeCount; ++i){
        int nowClosest = -1;
        for(int j = 0; j < nodeCount; ++j){
            // cout<<"[Trace] Distance[" << j << "] = " << Distance[j] << endl;
            if(!Visit[j] && Distance[j] >= 0 && (nowClosest == -1 || Distance[j] < Distance[nowClosest])){
                nowClosest = j;
            }
        }
        if(nowClosest == -1) break;
        // printf("[Trace] nowClosest = %d\n", nowClosest);
        Visit[nowClosest] = true;
        for(auto it = weight[nowClosest].begin(); it != weight[nowClosest].end(); ++it){
            if(Distance[it->ne] == -1 || Distance[it->ne] > Distance[nowClosest] + it->weight){
                Distance[it->ne] = Distance[nowClosest] + it->weight;
            }
        }
    }

    LL bestResult = -1;

    for(int i = 0; i < nodeCount; ++i){
        if(Palindrome[i] && (bestResult == -1 || Distance[i] < bestResult) && Distance[i] > 0)
            bestResult = Distance[i];
    }

    printf("%lld\n", bestResult);
}