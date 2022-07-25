#include <stdio.h>
#include <stdint.h>
#include <memory.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("syntax : add-nbo <file1> <file2>\n");
		printf("sample : add-nbo a.bin c.bin\n");
		return 1;
	}

	FILE *file1 = fopen(argv[1], "rb");
	FILE *file2 = fopen(argv[2], "rb");

	if(file1 == NULL || file2 == NULL){
		printf("file is empty\n");
		return 1;
	}

	uint32_t input1;
	uint32_t input2;

	fread(&input1, sizeof(uint32_t), 1, file1);
	fread(&input2, sizeof(uint32_t), 1, file2);

	input1 = ntohl(input1);
	input2 = ntohl(input2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", input1, input1, input2, input2, input1+input2, input1 + input2);

	fclose(file1);
	fclose(file2);
}
