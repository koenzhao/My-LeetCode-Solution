package queue_by_two_stack;

public class Demo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TwoStackQueue test = new TwoStackQueue();
		for(int i = 1;i<5;i++){
			test.add(i);
		}
		System.out.println(test.poll());
		test.add(5);
		System.out.println(test.poll());
		System.out.println(test.poll());
		System.out.println(test.poll());
		System.out.println(test.poll());
	}

}
