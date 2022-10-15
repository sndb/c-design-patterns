struct reader {
	int (*getc_fn)(struct reader *);
};
