
#include "mem_malloc.h"

char mem_id[10]={0};

void test_malloc(int i, int size){
	printf("------test_malloc-------\n");
	mem_id[i] = mem_malloc(size);
	if(mem_id[i] == 0){
		printf("malloc --- fail\n");
		printf("size=%d\n", size);
	}else{
		char *p = mem_buffer(mem_id[i]);
        memset(p, i, size);
        printf("p = 0x%x, i=%d, id=%d, size=%d\n", (int)p, i, mem_id[i], size);
	}
	print_mem_hex(MEM_SIZE);
}

void test_buffer(int i, int size){
	printf("------test_buffer-------\n");
	printf("i=%d, id = %d, size=%d\n", i, mem_id[i], size);
	char *p = mem_buffer(mem_id[i]);
    if(p != NULL){
		memset(p, 0xf0+i, size);
        print_mem_hex(MEM_SIZE);
	}else{
		printf("test_buffer---fail\n");
	}
}

void test_realloc(int i, int size){
	printf("------test_realloc-------\n");
    printf("i=%d, id = %d, size=%d\n", i, mem_id[i], size);
	int ret = mem_realloc(mem_id[i], size);
	if(ret){
		char *p = mem_buffer(mem_id[i]);
		memset(p, 0xa0+i, size);
        print_mem_hex(MEM_SIZE);
	}else{
		printf("test_realloc---fail\n");
	}
}

void test_free(int i){
	printf("------test_free-------\n");
	printf("i=%d, id = %d\n", i, mem_id[i]);
	if(mem_free(mem_id[i]))
		print_mem_hex( MEM_SIZE);
}

void main(void){

	print_mem_info();
	test_malloc(1, 10);
	test_malloc(2, 8);
	test_malloc(3, 20);

	test_free(2);

	test_malloc(4, 10);

	test_free(1);

	test_malloc(5, 20);
	test_malloc(6, 10);
	test_malloc(7, 10);

	test_free(6);

	test_malloc(8, 13);

	test_buffer(5, 20);

	test_free(4);

	test_buffer(3, 20);

	test_malloc(9, 15);
	test_malloc(10, 15);

	test_realloc(3, 10);
	test_realloc(8, 15);
	test_realloc(5, 30);
	test_realloc(8, 20);
	test_realloc(9, 20);
	test_realloc(9, 13);
	
	for(int i=0; i<10; i++)
		test_free(i);
} 

