// https://leetcode.com/problems/longest-happy-string

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        //multiple hh toh koi bhi daldo
        int total=a+b+c;  //maximun posiible length of string
        int curra=0,currb=0,currc=0; // consecutive counts of char
        string ans="";
        for(int i=0;i<total;i++)
        {
            if((a>=b and a>=c and curra!=2) or(a>0 and (currb==2 or currc==2)))
            {
                ans+='a';
                a--;
                curra++;
                currb=0;
                currc=0;
            }
           else if((b>=a and b>=c and currb!=2) or(b>0 and (currc==2 or curra==2)))
            {
                ans+='b';
                b--;
                currb++;
                curra=0;
                currc=0;
            }
            else if((c>=a and c>=b and currc!=2) or (c>0 and (curra==2 or currb==2)))
            {
                ans+='c';
                c--;
                currc++;
                curra=0;
                currb=0;
            }
        }
        return ans;

    }
};