/*
투 포인터

start의 문자 != target의 문자 => 불가능
start의 L 위치 < target의 L 위치 => 불가능
start의 R위치 > target R위치 => 불가능
*/

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();

        for(int i = 0, j = 0; i < n || j < n; i++, j++)
        {
            while(start[i] == '_') i++;
            while(target[j] == '_') j++;

            // start의 문자 != target의 문자 => 알파벳의 배열이 역전되는 것은 불가능
            if(start[i] != target[j]) return false;
            // L일때는 항상 start가 target보다 오른쪽에 위치해야함
            if(start[i] == 'L' && i < j) return false;
            // R일때는 항상 start가 target보다 왼쪽에 위치해야함
            if(start[i] == 'R' && i > j) return false;
        }

        return true;
    }
};