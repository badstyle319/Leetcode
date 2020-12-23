class Solution {
    bool isOperator(string s)
    {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        
        for(auto token:tokens)
        {
            if(!isOperator(token))
            {
                S.push(stoi(token));
            }
            else
            {
                int op1 = S.top(); S.pop();
                int op2 = S.top(); S.pop();
                if(token == "+")
                    S.push(op2+op1);
                else if(token == "-")
                    S.push(op2-op1);
                else if(token == "*")
                    S.push(op2*op1);
                else
                    S.push(op2/op1);
            }
        }
        
        return S.empty()?0:S.top();
    }
};