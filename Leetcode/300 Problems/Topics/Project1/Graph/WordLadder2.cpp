//https://practice.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    set<string> mySet(wordList.begin(), wordList.end());
  vector<vector<string>>ans;

  queue<vector<string>>my_queue;
  my_queue.push({beginWord});

  vector<string> usedOnLevels;
  usedOnLevels.push_back({beginWord});

  int level = 0;
   while(!my_queue.empty()){
      vector<string>top = my_queue.front();
      my_queue.pop();

      //remove all words in previous level
      if(top.size() > level){
        ++level;
        for(auto it : usedOnLevels){
          mySet.erase(it);
        }
        usedOnLevels.clear();
      }
      string last = top.back();

      if(last == endWord){
        if(ans.size() == 0 || ans[0].size() == top.size()){
          ans.push_back(top);
        }
      }

      
      for(int i = 0; i < last.length(); ++i){
        char original = last[i];
        for(char c = 'z'; c >= 'a'; --c){
          last[i] = c;
          if(mySet.find(last) != mySet.end()){ // find that word in set
            vector<string>temp = top;
            temp.push_back(last);
            my_queue.push(temp);
            usedOnLevels.push_back(word); // find all words to delete in current level

          }
        }
        last[i] = original; // to return back to original word
      }

    }
  return ans;
    }
};