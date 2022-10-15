#include "reader_struct.h"

#include <stdio.h>

struct stream_reader {
	struct reader super;
	FILE *stream;
};
