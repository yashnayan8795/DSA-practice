class MyQueue {
    private Stack<Integer> stack;

    public MyQueue() {
        stack = new Stack<>();
    }
    public void push(int x) {
        if (stack.isEmpty()) {
            stack.push(x);
            return;
        }
        int top = stack.pop();
        push(x); 
        stack.push(top); 
    }

    
    public int pop() {
        if (stack.isEmpty()) {
            return -1; 
        }
        return stack.pop();
    }

    
    public int peek() {
        if (stack.isEmpty()) {
            return -1;
        }
        return stack.peek();
    }
    public boolean empty() {
        return stack.isEmpty();
    }
}
