
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
        printf("p = 0x%x, id=%d, size=%d\n", (int)p, mem_id[i], size);
	}
	print_mem_hex(MEM_SIZE);
}

void test_buffer(int i, int size){
	printf("------test_buffer-------\n");
	printf("id = %d, size=%d\n", mem_id[i], size);
	char *p = mem_buffer(mem_id[i]);
    if(p != NULL){
		memset(p, 0xf0+i, size);
        print_mem_hex(MEM_SIZE);
	}
}

void test_free(int id){
	printf("------test_free-------\n");
	printf("id = %d\n", mem_id[id]);
	mem_free(mem_id[id]);
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
} 

