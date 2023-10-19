//https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder
#include<bits/stdc++.h>
using namespace std;
int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    set<string> mySet(wordList.begin(), wordList.end());

    queue<pair<string, int>>my_queue;

    my_queue.push({startWord, 1});

    mySet.erase(startWord);

    while(!my_queue.empty()){
        string word = my_queue.front().first;
        int step = my_queue.front().second;
        my_queue.pop();

        if(word == targetWord) return step;

        if(!mySet.empty()){ // because we don't have anything to remove from set => we have an answer
            for(int i = 0; i < word.size(); ++i){
                char original = word[i];
                for(char j = 'a'; j <= 'z'; ++j){
                    word[i] = j;
                    if(mySet.find(word) != mySet.end()){ // find that word in set
                        my_queue.push({word, step + 1});
                        mySet.erase(word);
                    }
                }
                word[i] = original; // to return back to original word
            }
        }

    }
    return 0;
}