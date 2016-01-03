package queue_by_two_stack;

import java.util.Stack;

import javax.management.RuntimeErrorException;

public class TwoStackQueue {
	public Stack<Integer> stackPush;
	public Stack<Integer> stackPop;
	
	public TwoStackQueue(){
		stackPush = new Stack<Integer>();
		stackPop = new Stack<Integer>();
	}
	
	public void add(int pushInt){
		stackPush.push(pushInt);
	}
	
	public int poll(){
		if(stackPop.empty() && stackPush.empty()){
			throw new RuntimeErrorException(null,"Queue is empty!");
		} else if(stackPop.empty()){
			while(!stackPush.empty()){
				stackPop.push(stackPush.pop());
			}
		}
		return stackPop.pop();
	}
	
	public int peek(){
		if(stackPop.empty() && stackPush.empty()){
			throw new RuntimeErrorException(null, "Queue is empty!");
		} else if(stackPop.empty()){
			while (!stackPush.empty()){
				stackPop.push(stackPush.pop());
			}
		}
		
		return stackPop.peek();
	}
}
