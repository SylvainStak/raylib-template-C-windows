.PHONE: all compile clean metadata

RAYLIB_PATH = ../raylib/src
RAYGUI_PATH = ../raygui/src

all: clean compile
	./\main.exe

compile:
	gcc -o main.exe main.c -Wall -Werror -std=c99 -D_DEFAULT_SOURCE -DPLATFORM_DESKTOP -g -D_DEBUG -I. -I$(RAYLIB_PATH) -I$(RAYGUI_PATH) -L$(RAYLIB_PATH) metadata.rc.data -lraylib -lopengl32 -lgdi32 -lwinmm 

clean:
	rm -rf main.exe

metadata:
	windres metadata.rc -o metadata.rc.data --target=pe-x86-64
