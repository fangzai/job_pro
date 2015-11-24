/**
 * Created by hduser on 15-11-24.
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack
 */
import java.util.Stack;
public class MinStack {
    public Stack<Integer> dataStack = null;
    public Stack<Integer> minimum = null;
    public MinStack(){
        dataStack = new Stack<Integer>();
        minimum = new Stack<Integer>();
    }
    public void push(int x) {
        if (minimum.empty()) {
            this.minimum.push(x);
        } else {
            if (minimum.peek() > x) {
                this.minimum.push(x);
            } else {
                this.minimum.push(minimum.peek());
            }
        }
        this.dataStack.push(x);
    }

    public void pop() {
        if (dataStack.empty()) {
            return;
        } else {
            dataStack.pop();
            minimum.pop();
        }
    }

    public int top() {
        return dataStack.peek().intValue();
    }

    public int getMin() {
        return this.minimum.peek().intValue();
    }
}
