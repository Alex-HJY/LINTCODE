class MinStack {
public:
	stack<int> s;
	stack<int> mins;
	MinStack() {
		// do intialization if necessary
	}

	/*
	* @param number: An integer
	* @return: nothing
	*/
	void push(int number) {
		// write your code here
		s.push(number);
		if (mins.empty() || number <= mins.top()) {
			mins.push(number);
		}
	}

	/*
	* @return: An integer
	*/
	int pop() {
		// write your code here
		int i=s.top();
		if (s.top() == mins.top())
			mins.pop();
		    s.pop();	
		    return i;
	}

	/*
	* @return: An integer
	*/
	int min() {
		if (!mins.empty())
			return mins.top();
		// write your code here
	}
};