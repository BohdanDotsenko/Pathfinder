void mx_printchar(char c);

void mx_printint(int n) {
	int long m = n;
	int p = 1;
	if (n < 0) {
		mx_printchar('-');
		m = -m;
	}
	while(p < m) {
		p *= 10;
	}
	p /= 10;
	while(p > 0) {
		mx_printchar((m / p) + '0');
		m %= p;
		p /=10;
	}
}
