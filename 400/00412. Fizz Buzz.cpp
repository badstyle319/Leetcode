class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        stringstream ss;
        for(int i=1;i<=n;i++){
            if(i%15==0)
                result.push_back("FizzBuzz");
            else if(i%3==0)
                result.push_back("Fizz");
            else if(i%5==0)
                result.push_back("Buzz");
            else{
                ss.str("");
                ss.clear();
                ss<<i;
                result.push_back(ss.str());
            }
        }
        return result;
    }
};