class Solution {
    public String shortestPalindrome(String s) {
        if(s == null || s.isEmpty()){
            return "";
        }
        int i=0;
        for(int j=s.length()-1;j>=0;j--){
            if(s.charAt(i) ==s.charAt(j)){
                i++;
            }
        }
        if(i==s.length()){
            return s;
        }
        String suffix= s.substring(i);
        String prefix = new StringBuilder(suffix).reverse().toString();
        String middle = shortestPalindrome(s.substring(0,i));
        return prefix +middle + suffix;
    }
}