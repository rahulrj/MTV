import java.io.*;
import java.util.*;

class GFG {
	public static void main (String[] args) {
		
		Stack<Integer>stack=new Stack<>();
		stack.push(5);
		stack.push(7);
		stack.push(1);
		stack.push(4);
		stack.push(9);
		stack.push(11);
		stack.push(13);
		
		reverse(stack);
		
		while(!stack.empty()){
		    System.out.println(stack.peek());
		    stack.pop();
		}
		
	}
	
	static void reverse(Stack<Integer>stack){
	    
	    if(stack.empty()){
	        return;
	    }
	    
	    int x=stack.pop();
	    reverse(stack);
	    
	    insert(stack,x);
	    
	}
	
	static void insert(Stack<Integer>stack,int x){
	    //System.out.println(x);
	    if(stack.empty()){
	        stack.push(x);
	        return;
	    }
	    
	    int top=stack.peek();
	    stack.pop();
	    
	    insert(stack,x);
	    stack.push(top);
	    //System.out.println("stack: " + stack);
	    
	}
	
	
}