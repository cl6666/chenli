CC := gcc
CFLAGS := -Wall -O3
Libs = -lpthread
Target := park
Source := $(wildcard src/*.c)
Objs := $(patsubst %.c,%.o,$(Source))
Modules += init_park init_wait ins_wait is_park_full my_strcmp\
        my_strlen my_strcpy surface leave car_park print main
AllObjs := $(addsuffix /src/*.o,$(Modules))
