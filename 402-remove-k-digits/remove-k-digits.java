class Solution {
    public String removeKdigits(String num, int k) {
        int l= num.length();
        if(k==0) return num;
        if(k==l) return "0";

        Stack<Character> stack = new Stack<>();
        int idx=0;
        while(idx<l){
            while(k>0 && !stack.isEmpty() && stack.peek()> num.charAt(idx)){
                stack.pop();
                k--;
            }
            stack.push(num.charAt(idx++));
        } 
        while(k-- >0)
            stack.pop();

        String s="";
        while(!stack.isEmpty()) s= stack.pop() + s;

        while(s.length()>1 && s.charAt(0)=='0')
            s=s.substring(1);

        return s;
    }
}