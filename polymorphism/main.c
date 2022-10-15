#include "buffer_reader.h"
#include "stream_reader.h"

#include <stdio.h>

void
sum_values(struct reader *r) {
	int sum = 0;
	for (int i = 0;;) {
		int c = reader_getc(r);
		if (c == EOF)
			break;
		if (c == '\n')
			continue;
		sum += c;
		printf("i%d: %d\n", i, c);
		i++;
	}
	printf("---\nSum: %d\n", sum);
}

void
test_buffer_reader() {
	uint8_t buffer[] = {1, 2, 3, 4};
	struct buffer_reader *br = buffer_reader_new(buffer, 4);
	sum_values(buffer_reader_get_reader(br));
	free(br);
}

void
test_stream_reader() {
	struct stream_reader *sr = stream_reader_new(stdin);
	sum_values(stream_reader_get_reader(sr));
	free(sr);
}

int
main(void) {
	test_buffer_reader();
	test_stream_reader();
	return 0;
}
