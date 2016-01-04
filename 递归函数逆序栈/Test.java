package chapter_1_q3;

import java.util.Stack;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack<Integer> stack = new Stack<>();
		for(int i = 1;i<=5;i++){
			stack.push(i);
		}
//		for(int i = 1;i<=5;i++)
//		{
//			System.out.println(stack.pop());
//		}
		ReverseStack.reverse(stack);
		for(int i = 1;i<=5;i++)
		{
			System.out.println(stack.pop());
		}
	}

}
