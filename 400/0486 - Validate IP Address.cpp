class Solution {
public:
    string validIPAddress(string IP) {
        const int IPV4_LIMIT = (1 << 8) - 1;
        const int IPV6_LIMIT = (1 << 16) - 1;
        const string NG = "Neither";
        vector<int> v;
        int type = 0, counter = 0;
        size_t found;
        
        found = IP.find_first_of(".:");
        while(found != string::npos)
        {
            counter++;
            if(IP[found] == '.')
                type = 1;
            else
                type = 2;
            
            IP[found] = ' ';
            found = IP.find_first_of(".:", found+1);
        }
        if(type == 1 && counter != 3)
            return NG;
        if(type == 2 && counter != 7)
            return NG;
        
        stringstream ss(IP);
        string str;
        while(ss>>str)
        {
            if(str.length() > 4 || str.length() == 0)
                return NG;
            
            int val;
            
            switch(type)
            {
                case 1:
                    if(str.length() > 1 && str[0] == '0')
                        return NG;
                    for(auto ch:str)
                    {
                        if(!isdigit(ch))
                            return NG;
                    }
                    sscanf(str.c_str(), "%d", &val);
                    if(val > IPV4_LIMIT)
                        return NG;
                    break;
                case 2:
                    for(auto ch:str)
                    {
                        if(!isxdigit(ch))
                            return NG;
                    }
                    sscanf(str.c_str(), "%x", &val);
                    if(val > IPV6_LIMIT)
                        return NG;
                    break;
                default:
                    return NG;
            }
            v.push_back(val);
        }
        cout << endl;
        
        if(type == 1 && v.size() == 4)
            return "IPv4";
        else if(type == 2 && v.size() == 8)
            return "IPv6";
        
        return NG;
    }
};