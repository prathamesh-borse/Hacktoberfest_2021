class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector <int> s1hash(26,0);
        vector <int> s2hash(26,0);
        
        if (s2.length()<s1.length()) return false;
        
        int right=0, left=0;
        while(right<s1.length()){
            s1hash[s1[right]-'a']+=1;
            s2hash[s2[right]-'a']+=1;
            right+=1;
        }
        right-=1;
        while(right<s2.length()){
            if (s1hash==s2hash) return true;
            right+=1;
            
            if(right!=s2.length()){
                s2hash[s2[right]-'a']+=1;
            }
            s2hash[s2[left]-'a']-=1;
            left+=1;
        }
        return false;
    }
};
