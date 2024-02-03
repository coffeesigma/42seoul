#include <stdio.h>
#include "ft_printf.h"

int main() {
	printf(" %d\n", 5);
	ft_printf(" %d\n", 5);
	printf("%cc\n", 'e');
	ft_printf("%cc\n", 'e');

	return (0);
}