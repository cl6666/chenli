CC := gcc
CFLAGS := -Wall -O3
Libs = -lsqlite3
Target := client
Source := $(wildcard src/*.c)
Objs := $(patsubst %.c,%.o,$(Source))
Modules += main is_malloc_ok creat_head search_linkman choose_action is_ID_exit display_linkman \
	print_interface display_search delete_linkman choose2int is_num add_information \
	insert_linkman sort_linkman str_com help insert_old_linkman 
	
AllObjs := $(addsuffix /src/*.o,$(Modules))

