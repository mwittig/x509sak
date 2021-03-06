/* This file is AUTO-GENERATED       */
/* Do not edit by hand.              */
/* Your changes will be overwritten. */

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "argparse.h"

enum argparse_option_internal_t {
	ARG_MODE_SHORT = 'm',
	ARG_THREAD_CNT_SHORT = 't',
	ARG_BIT_LENGTH_SHORT = 'b',
	ARG_NUM_PRIMES_SHORT = 'n',
	ARG_MODE_LONG = 1000,
	ARG_THREAD_CNT_LONG = 1001,
	ARG_BIT_LENGTH_LONG = 1002,
	ARG_NUM_PRIMES_LONG = 1003,
};

bool argparse_parse(int argc, char **argv, argparse_callback_t argument_callback) {
	const char *short_options = "m:t:b:n:";
	struct option long_options[] = {
		{ "mode",                             required_argument, 0, ARG_MODE_LONG },
		{ "thread-cnt",                       required_argument, 0, ARG_THREAD_CNT_LONG },
		{ "bit-length",                       required_argument, 0, ARG_BIT_LENGTH_LONG },
		{ "num-primes",                       required_argument, 0, ARG_NUM_PRIMES_LONG },
		{ 0 }
	};

	while (true) {
		int optval = getopt_long(argc, argv, short_options, long_options, NULL);
		if (optval == -1) {
			break;
		}
		enum argparse_option_internal_t arg = (enum argparse_option_internal_t)optval;
		switch (arg) {
			case ARG_MODE_SHORT:
			case ARG_MODE_LONG:
				if (!argument_callback(ARG_MODE, optarg)) {
					return false;
				}
				break;

			case ARG_THREAD_CNT_SHORT:
			case ARG_THREAD_CNT_LONG:
				if (!argument_callback(ARG_THREAD_CNT, optarg)) {
					return false;
				}
				break;

			case ARG_BIT_LENGTH_SHORT:
			case ARG_BIT_LENGTH_LONG:
				if (!argument_callback(ARG_BIT_LENGTH, optarg)) {
					return false;
				}
				break;

			case ARG_NUM_PRIMES_SHORT:
			case ARG_NUM_PRIMES_LONG:
				if (!argument_callback(ARG_NUM_PRIMES, optarg)) {
					return false;
				}
				break;

			default:
				return false;
		}
	}

	/* TODO: Handle positional arguments */

	return true;
}

void argparse_show_syntax(void) {
	fprintf(stderr, "usage: primegen [-m {random,crt}] [-t number] [-b bits] [-n cnt]\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "Multithreaded prime generation\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "optional arguments:\n");
	fprintf(stderr, "  -m {random,crt}, --mode {random,crt}\n");
	fprintf(stderr, "                        Mode in which to try to generate primes. Can be one of\n");
	fprintf(stderr, "                        random, crt, defaults to random.\n");
	fprintf(stderr, "  -t number, --thread-cnt number\n");
	fprintf(stderr, "                        Number of threads to use. Defaults to 8.\n");
	fprintf(stderr, "  -b bits, --bit-length bits\n");
	fprintf(stderr, "                        Number of bits that generated primes will have.\n");
	fprintf(stderr, "                        Defaults to 2048. May be imprecise in case of CRT-\n");
	fprintf(stderr, "                        generated primes.\n");
	fprintf(stderr, "  -n cnt, --num-primes cnt\n");
	fprintf(stderr, "                        Number of primes that are generated by primegen.\n");
	fprintf(stderr, "                        Defaults to 10.\n");
}

void argparse_parse_or_die(int argc, char **argv, argparse_callback_t argument_callback) {
	if (!argparse_parse(argc, argv, argument_callback)) {
		argparse_show_syntax();
		exit(EXIT_FAILURE);
	}
}
