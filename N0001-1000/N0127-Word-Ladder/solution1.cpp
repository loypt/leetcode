//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/27/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
using namespace std::chrono;

class Solution {
    unordered_map<string, int> word_table;
    vector<vector<int>> edge;
    int nodeNo = 0;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (string& word: wordList) {
            addEdge(word);
        }
        addEdge(beginWord);
        // judge if not have end word
        if (!word_table.count(endWord)){
            return 0;
        }

        vector<int> dis(nodeNo, INT_MAX); // destination
        int beginId = word_table[beginWord], endId = word_table[endWord];
        dis[beginId] = 0;

        queue<int> que;
        que.push(beginId);
        while (!que.empty()){
            int x = que.front();
            que.pop();
            if (x == endId) {
                return dis[endId] / 2 + 1;
            }
            for (int & it: edge[x]) {
                if (dis[it] == INT_MAX){
                    dis[it] = dis[x] + 1;
                    que.push(it);
                }
            }
        }
        return 0;
    }

    void addWord(string& word){
        if (!word_table.count(word)){
            word_table[word] = nodeNo++;
            edge.emplace_back();
        }
    }

    void addEdge(string& word){
        addWord(word);
        int id_one = word_table[word];
        for (char & c : word) { // generate *it, h*t, hi*
            char temp = c;
            c = '*';
            addWord(word);
            int id_two = word_table[word];
            edge[id_one].push_back(id_two);
            edge[id_two].push_back(id_one);
            c = temp;
        }
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution solution;
    cout << solution.ladderLength(beginWord ,endWord, wordList);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

