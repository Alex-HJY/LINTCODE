class Solution {
public:
    /*
     * @param n: the nth
     * @return: the nth sequence
     */
    string countAndSay(int n) {
        // write your code here
        string ans="1 ";
        for(int i=2;i<=n;i++){
            string t="";
            int length=ans.length();
            for(int j=0;j<length-1;j++){
                char c=ans[j];
                int count=1;
                if (j<length-1){
                    while (ans[j]==ans[j+1]){
                        j++;
                        count++;
                    }
                }
                t=t+to_string(count)+c;
            }
            ans=t+" ";
        }
        ans=ans.substr(0,ans.length()-1);
        return ans;
    }
};
