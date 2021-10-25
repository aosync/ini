#include "ini.h"

#include <stdio.h>

int main() {
	char i[] = "[core]\n; this is a comment\nkernel=KERNEL\ninitrd=INITRD\nvideo=80x25";

	printf("PARSING: \n%s\n\n-----\n\n", i);
	
	ini_t ini;
	ini_init(&ini, i);
	char *a, *b, *s;
	while (ini_iter(&ini, &a, &b, &s)) {
		if (s) {
			printf("sec(%s)\n", s);
		} else if (a && b) {
			printf("\tkey(%s) = val(%s)\n", a, b);
		}
	}
}
