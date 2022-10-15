#include "reader_struct.h"

#include <stdint.h>
#include <stdlib.h>

struct buffer_reader {
	struct reader super;
	uint8_t *buffer;
	size_t size, pos;
};
