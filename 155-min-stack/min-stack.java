class MinStack {
    Stack<Integer> st;
    PriorityQueue<Integer> p ;
    public MinStack() {
        this.st = new Stack<Integer>();
        this.p =  new PriorityQueue<>();
        
    }
    
    public void push(int val) {
        st.push(val);
        p.add(val);
    }
    
    public void pop() {
        int val = st.peek();
        p.remove(val);
        st.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return p.peek();
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