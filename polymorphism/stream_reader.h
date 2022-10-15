#include "reader.h"

#include <stdio.h>

struct stream_reader;

void stream_reader_init(struct stream_reader *sr, FILE *stream);
struct stream_reader *stream_reader_new(FILE *stream);
struct reader *stream_reader_get_reader(struct stream_reader *);
