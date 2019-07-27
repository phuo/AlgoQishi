//Leetcode 190:
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int m = 32;
        uint32_t out;
        while(m>0){
            out = (out<<1) + (n&1);
            n>>=1;
            m--;
        }
        return out;
    }
};

//Leetcode 338:
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> out(num+1, 0);
        for (int i = 1; i <= num; ++i)
            out[i] = out[i&(i-1)] + 1;
        return out;
    }
};

//Leetcode 401:
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> out;
        for(int h=0; h<12; h++){
            for(int min=0; min<60; min++){
                if(bitset<10>(h<<6 | min).count() == num){
                    out.push_back( to_string(h) + (min<10? ":0":":") + to_string(min) );
                }
            }
        }
        return out;

    }
};

//Leetcode 693:
class Solution {
public:
    bool hasAlternatingBits(int n) {
        //std::cout<<(int)( n>>1 )<<std::endl;
        if ( ((n & (n>>1)) == 0)  && ((n &(n>>2)) == (n>>2) ) ) return true;
        else return false;
    }
};
