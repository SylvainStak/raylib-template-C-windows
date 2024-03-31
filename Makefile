.PHONE: all debug compile clean

RAYLIB_PATH = ../raylib/src
RAYGUI_PATH = ../raygui/src

all: clean compile
	./\main.exe

debug: clean compile
	cv2pdb main.exe
	powershell -ExecutionPolicy Bypass -File ./debug.ps1

compile:
	gcc -o main.exe main.c -Wall -std=c99 -D_DEFAULT_SOURCE -DPLATFORM_DESKTOP -g -D_DEBUG -I. -I$(RAYLIB_PATH) -I$(RAYGUI_PATH) -L$(RAYLIB_PATH) -lraylib -lopengl32 -lgdi32 -lwinmm

clean:
	rm -rf *.exe *.pdb
