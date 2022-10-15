#include <stdbool.h>
#include <stdio.h>

typedef bool filter_fn(void *, int);

struct is_divisible {
	bool (*fn)(void *, int);
	int divisor;
};

bool
is_divisible(void *closure, int n) {
	struct is_divisible *ctx = closure;
	return n % ctx->divisor == 0;
}

bool
is_prime(void *ctx, int n) {
	(void)ctx;
	if (n <= 1)
		return false;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	return true;
}

void
print_filtered(int n, filter_fn **f) {
	for (int i = 0; i <= n; i++)
		if ((*f)(f, i))
			printf("%d ", i);
	puts("");
}

int
main(void) {
	struct is_divisible is_divisible_by_3 = {is_divisible, 3};
	filter_fn *is_prime_closure = is_prime;

	puts("Divisible by 3");
	print_filtered(30, &is_divisible_by_3.fn);

	puts("Primes");
	print_filtered(30, &is_prime_closure);
}
