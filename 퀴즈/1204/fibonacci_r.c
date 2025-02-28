int fibonacci_r(int n) {
	if (n <= 1)
		return n;
	else 
		return (fibonacci_r(n - 1) + fibonacci_r(n - 2));
}

int main() {
	int n = 43;
	fibonacci_r(n);

	return 0;
}
