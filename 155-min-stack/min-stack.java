class MinStack {
    Stack<Integer> st;
    Stack<Integer> minStack;
    public MinStack() {
        this.st = new Stack<>();
        this.minStack =  new Stack<>();
    }
    
    public void push(int val) {
        if(minStack.empty() || val <= minStack.peek()){
            if(!minStack.empty())System.out.println("Curr min before push: " + minStack.peek());
            minStack.push(val);
        }
        st.push(val); 

    }
    
    public void pop() {

        if(st.pop().equals(minStack.peek()))minStack.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return minStack.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */