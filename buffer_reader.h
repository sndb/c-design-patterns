#include "reader.h"

#include <stdint.h>
#include <stdlib.h>

struct buffer_reader;

void buffer_reader_init(struct buffer_reader *br, uint8_t *buffer, size_t size);
struct buffer_reader *buffer_reader_new(uint8_t *buffer, size_t size);
struct reader *buffer_reader_get_reader(struct buffer_reader *br);
