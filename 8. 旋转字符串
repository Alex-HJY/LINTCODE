class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        // write your code here
        int length=str.size();
        if (length!=0){
            offset%=length;
            string temp="";
            for (int i=0;i<offset;i++){
                temp = str.substr(0,length-1);
                str=str[length-1]+temp;
            }
        }
        else
        return;
    }
};
