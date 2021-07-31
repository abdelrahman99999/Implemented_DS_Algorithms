//fibonacci between recursive way and iterative way

//recursive way
int fibonacci(int n) {
	if (n == 0)return 0;
	else if (n == 1)return 1;
	else
		return ( fibonacci(n - 1) + fibonacci(n - 2) );	 //complexity θ(e pow n)
}


//iterative way
int fibonacci(int n){
	int backone,backtwo,current;
	if (n == 0)return 0;
	else if (n == 1)return 1;
	else{
		backone=0;
		backtwo=1;
		for(int i=2;i<=n;i++){     //complexity θ(n)
			current=backone+backtwo;
			backone=backtwo;
			backtwo=current;
		}
		return current;
	}
}

/*
iterative way is more better as 
			1- we don't use stack this will save time and memory
			2- complexity is more better  
*/