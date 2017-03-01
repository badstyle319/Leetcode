class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int h=0;h<12;h++){
            for(int m=0;m<60;m++){
                bitset<10> bs(h<<6 | m);
                if(bs.count()==num){
                    stringstream ss;
                    ss<<h;
                    ss<<":";
                    if(m<10)
                        ss<<"0";
                    ss<<m;
                    ans.push_back(ss.str());
                }
            }
        }
        return ans;
    }
};