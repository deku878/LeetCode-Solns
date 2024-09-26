// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

class Solution {
public:
    int minFlips(int a, int b, int c) {
                int flip = 0;

        for(int i = 0; i < 32; i++) {
            bool ai = (a & (1 << i)); // taking the ith bit in a
            bool bi = (b & (1 << i)); // taking the ith bit in b
            bool ci = (c & (1 << i)); // taking the ith bit in c

            if(ci) {
                if(!ai && !bi) flip++;
            } else {
                if(ai && bi) flip += 2;
                else if(ai || bi) flip++;
            }
        }
        return flip;}
};