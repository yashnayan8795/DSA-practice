class Solution {
    public boolean isValid(String s) {
        if(s.length()==0) return true;
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) return false;
                char a = stack.peek();  //
                if ((c == ')' && a == '(') ||
                    (c == ']' && a == '[') ||
                    (c == '}' && a == '{')) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }
}
