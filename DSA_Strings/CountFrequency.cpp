class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for(char ch : s){
            freqMap[ch]++; // appending to an unordered map all the chars of string
        }

        vector<string> buckets(s.size() + 1); // size of bucket needs to be length of string at max for each letter if all are uniique
        for(auto [ch, freq] : freqMap){
            buckets[freq] += string(ch, freq);
            // we add the string multiplied by its frequency to bucket of freq index. 
            // eg: string('a', 3) adds 'aaa' to buckets[3]
        }
        string res = "";
        for(int i = buckets.size() - 1; i > 0; i--){
            if(!buckets[i].empty()) {
                res += buckets[i];
            }
        }
        return res;
    }
};