//factorial between recursive way and iterative way

//recursive way
int factorial(int n){
	if(!n){           //stop condition  n==0
		return 1;
	}else{
		return n*factorial(n-1);   //complexity θ(n)
	}
}

//iterative way
int factorial(int n) {
	int result = 1;
	for (; n >= 1; n--) {           //complexity θ(n)
		result *= n ;
	}
	return result;
}

/*
here, iterative way is more better as no need to build stack(happen in recursive way by os)
 so i save time and memory (more fast and economic)

- complexity for 2 ways is same(Linear), but constant for recursive is more bigger
  say for example that 
		complexity for recursive  5n
		complexity for iterative  3n
*/