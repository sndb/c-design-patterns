#include "stream_reader.h"

#include "stream_reader_struct.h"
#include "util.h"

#include <stdlib.h>

static int
stream_reader_getc(struct reader *r) {
	struct stream_reader *sr = CONTAINER_OF(r, struct stream_reader, super);
	return fgetc(sr->stream);
}

void
stream_reader_init(struct stream_reader *sr, FILE *stream) {
	*sr = (struct stream_reader){
		.super = {stream_reader_getc},
		.stream = stream,
	};
}

struct stream_reader *
stream_reader_new(FILE *stream) {
	struct stream_reader *sr = malloc(sizeof(*sr));
	if (!sr)
		return NULL;
	stream_reader_init(sr, stream);
	return sr;
}

struct reader *
stream_reader_get_reader(struct stream_reader *sr) {
	return &sr->super;
}
