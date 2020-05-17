class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int a[26]={0};
        vector<int> ans;
        if(p.size()>s.size()||s.size()==0)
            return {};
        for(int i=0;i<p.size();i++)
        {
            a[p[i]-'a']++;
        }
        
        int b[26]={0};
        int count=0;
        for(int i=0;i<p.size();i++)
        {
            b[s[i]-'a']++;
            if(b[s[i]-'a']<=a[s[i]-'a'])
            {
                count++;
            }
        }
        int i;
        for( i=p.size();i<s.size();i++)
        {
            if(count==p.size())
                ans.push_back(i-p.size());
            b[s[i-p.size()]-'a']--;
            if(b[s[i-p.size()]-'a']<a[s[i-p.size()]-'a'])
            {
             count--;   
            }
            b[s[i]-'a']++;
            if(b[s[i]-'a']<=a[s[i]-'a'])
            {
                count++;
            }   
        }
        
            if(count==p.size())
                ans.push_back(i-p.size());
        return ans;
    }
};