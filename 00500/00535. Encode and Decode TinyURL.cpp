class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        long_to_short[longUrl] = "http://tinyurl.com/" + to_string(getHash(longUrl));
        short_to_long[long_to_short[longUrl]] = longUrl;
        return long_to_short[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short_to_long[shortUrl];
    }
    
private:
    uint64_t getHash(const string& str) {
        uint64_t hash = 0xfedcba98;

        for(int i = 0; i < str.size(); ++i) {
            hash ^= str[i];
            hash <<= 8;
        }

        return hash;
    }
    
    unordered_map<string, string> long_to_short;
    unordered_map<string, string> short_to_long;
};