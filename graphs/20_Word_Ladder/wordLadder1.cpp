// https://practice.geeksforgeeks.org/problems/word-ladder/1

#include<bits/stdc++.h>
using namespace std;


int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    if (startWord==targetWord) return 0;
    set<string>s;
    for(string str: wordList)s.insert(str);
    queue<pair<string, int>>q;
    q.push({startWord, 1});
    s.erase(startWord);
    while(!q.empty()){
        string word = q.front().first;
        int dist = q.front().second;
        if(word==targetWord)
            return dist;
        q.pop();
        for(int k = 0; k<word.size(); k++){
            for(int i=0; i<26; i++){
                string temp = word;
                temp[k] = char(int('a')+i);
                if (s.find(temp) != s.end()) {
                    q.push({temp, dist+1});
                    s.erase(temp);
                }
            }
        }
    }

    return 0;
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
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        int res = wordLadderLength(startWord, targetWord, wordList);
        cout<<res<<endl;
    }
    return 0;
}
