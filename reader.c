#include "reader.h"

#include "reader_struct.h"

int
reader_getc(struct reader *r) {
	return r->getc_fn(r);
}
