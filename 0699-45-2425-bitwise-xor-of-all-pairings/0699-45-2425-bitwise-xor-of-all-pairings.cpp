/*
비트 마스킹
*/
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int tmp1 = 1;
        int tmp2 = 1;
        
        /*
        nums1와 nums2를 모두 XOR 하는 연산
        = nums1의 모든 원소를 서로 XOR한 이후 nums2의 크기만큼 반복하여 XOR 연산
        = nums2의 모든 원소를 서로 XOR한 이후 nums1의 크기만큼 반복하여 XOR 연산
        */


        // nums2의 크기가 짝수라면 XOR 이후 0임
        if(m % 2 == 0) tmp1 = 0;

        else
        {
            for(int i = 0; i < n; i++)
            {
                tmp1 ^= nums1[i];
            }

            tmp1 ^= 1;
        }

        // nums1의 크기가 짝수라면 XOR 이후 0임
        if(n % 2 == 0) tmp2 = 0;

        else
        {
            for(int i = 0; i < m; i++)
            {
                tmp2 ^= nums2[i];
            }

            tmp2 ^= 1;
        }

        // cout << "tmp1: " << tmp1 << " tmp2: " << tmp2 << "\n";

        return (tmp1 ^ tmp2);
    }
};