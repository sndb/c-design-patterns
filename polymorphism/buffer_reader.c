#include "buffer_reader.h"

#include "buffer_reader_struct.h"
#include "util.h"

#include <stdio.h>

int
buffer_reader_getc(struct reader *r) {
	struct buffer_reader *br = CONTAINER_OF(r, struct buffer_reader, super);
	if (br->pos == br->size)
		return EOF;
	return br->buffer[br->pos++];
}

void
buffer_reader_init(struct buffer_reader *br, uint8_t *buffer, size_t size) {
	*br = (struct buffer_reader){
		.super = {buffer_reader_getc},
		.buffer = buffer,
		.size = size,
		.pos = 0,
	};
}

struct buffer_reader *
buffer_reader_new(uint8_t *buffer, size_t size) {
	struct buffer_reader *br = malloc(sizeof(*br));
	if (!br)
		return NULL;
	buffer_reader_init(br, buffer, size);
	return br;
}

struct reader *
buffer_reader_get_reader(struct buffer_reader *br) {
	return &br->super;
}
