class toggle2 {
	public:
	
	bool last=false;
	bool runfirst=true;

	void (*f_a)();
	void (*f_b)();
	
	toggle2(void(*a)(),void(*b)()) {
		f_a=a;
		f_b=b;
	}

	void run(bool condition) { //tests if the condition is true, if so run the correct funtions
		if (!last&condition) {
			runfirst?f_a():f_b(); //run which ever function is next
			runfirst=!runfirst; //invert it function to run
		}
		last=condition;
	}
};