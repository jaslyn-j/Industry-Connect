#include <stdio.h>
#include <stdarg.h>

void print_int(int num, ...){
	va_list args;
	va_start(args, num);
	for(int i=0; i<num; i++){
		int value=va_arg(args, int);
		printf("%d: %d\n", i, value);
	}
	va_end(args);	
}
int main(){
	printf("Function call 1\n");
	print_int(3, 24, 26, 312);
	printf("Function call 2\n");
	print_int(2, 256, 512);
	printf("Function call 3\n");
	print_int(7, 2, 3, 4, 5, 6, 7, 8);
}
