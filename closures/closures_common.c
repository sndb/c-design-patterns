#include <stdbool.h>
#include <stdio.h>

struct filter_closure {
	bool (*fn)(struct filter_closure *, int);
	void *ctx;
};

void
print_filtered(int n, struct filter_closure *filter) {
	for (int i = 1; i <= n; ++i)
		if (filter->fn(filter, i))
			printf("%d ", i);
	puts("");
}

bool
is_divisible(struct filter_closure *closure, int n) {
	return n % *(int *)closure->ctx == 0;
}

bool
is_prime(struct filter_closure *closure, int n) {
	(void)closure;
	if (n <= 1)
		return false;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	return true;
}

int
main(void) {
	print_filtered(30, &(struct filter_closure){is_divisible, &(int){3}});
	print_filtered(30, &(struct filter_closure){is_prime, NULL});
}
