/*
 * Copyright (c) 2026, Ae-foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * software name includes “ae”.
 *
 * THE SOFTWARE IS PROVIDED “AS IS” AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE
 * FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static inline void
aeframe(char *txt, bool direct)
{
	ssize_t n = strlen(txt) - 1;
	if (n < 1)
		return;
	if (direct)
		putchar('A');
	while (n--)
		putchar('E');
	if (!direct)
		putchar('A');
	putchar('\n');
}

int
main(void)
{
	char *pathname = getcwd(NULL, 0);
	if (!pathname) {
		fprintf(stderr, "%s\n", strerror(errno));
		return 1;
	}
	aeframe(pathname, 1);
	puts(pathname);
	aeframe(pathname, 0);
	return 0;
}