class Solution {
    public String longestPrefix(String s) {
        int n= s.length();
        int[] lps = new int[n];
        int len=0;

        for(int i=1;i<n;){
            if(s.charAt(i)== s.charAt(len)){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len!=0){
                    len=lps[len-1];

                }else{
                    lps[i++]=0;
                }
            }
        }
        int happy_len=lps[n-1];
        return happy_len>0 ? s.substring(0,happy_len):"";
    }
}