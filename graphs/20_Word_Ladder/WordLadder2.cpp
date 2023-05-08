// https://practice.geeksforgeeks.org/problems/word-ladder-ii/1

#include<bits/stdc++.h>
using namespace std;


vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    
    set<string>s;
    for(string str: wordList)s.insert(str);
    queue<vector<string>>q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;
    vector<vector<string>> res;
    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        if(vec.size()>level){
            level++;
            for (auto it: usedOnLevel)
                s.erase(it);
        }
        string word = vec.back();
        // cout<<word;
        if(word==endWord){
            if(res.size()==0)
                res.push_back(vec);
            else if(res[0].size()==vec.size()){
                res.push_back(vec);
            }
        }
        for(int k = 0; k<word.size(); k++){
            for(int i=0; i<26; i++){
                string temp = word;
                temp[k] = char(int('a')+i);
                if (temp!=word && s.find(temp) != s.end()) {
                    // cout<<temp<<" ";
                    vec.push_back(temp);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
        }
    }

    return res;
}

int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin >> n;
        vector<string> wordList(n);
        for(int i = 0; i<n; i++){
            cin>>wordList[i];
        }
        string beginWord, endWord;
        cin >> beginWord >> endWord;
        vector<vector<string>> res= findSequences(beginWord, endWord, wordList);
        for(auto it1: res){
            for(auto it2:it1){
                cout<< it2 <<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

//g++ WordLadder2.cpp && ./a.out && rm ./a.out
//g++ ~/Desktop/coding/graphs/20_Word_Ladder/WordLadder2.cpp && ./a.out && rm ./a.out