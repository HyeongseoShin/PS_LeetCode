/*
문자열 자르기
*/
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        // 문자열 자르기
        istringstream ss(sentence);
        string buffer; // 쪼개진 단어
        vector<string> result; // 쪼개진 단어 모음
        
        while(getline(ss, buffer, ' '))
        {
            result.push_back(buffer);
        }

        for(int i = 0 ; i < (int)result.size(); i++)
        {
            int idx = result[i].find(searchWord);
            if(idx == 0) return i+1;
        }

        return -1;
    }
};