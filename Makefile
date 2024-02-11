.PHONY: all metadata clean release

BUILD_MODE          = DEBUG
PROJECT_NAME        = release
METADATA_RAW 		= metadata.rc
METADATA_COMPILED 	= metadata.rc.data
SRC_DIR 	 		= src

CC = gcc
CFLAGS += -Wall -Wno-missing-braces -std=c99 -D_DEFAULT_SOURCE -DPLATFORM_DESKTOP 
ifeq ($(BUILD_MODE),DEBUG)
    CFLAGS += -Og -g3
else
    CFLAGS += -s -O1 -Wl,--subsystem,windows
endif
LDLIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
SOURCE_FILES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c)

all:
	$(CC) $(SOURCE_FILES) -o $(PROJECT_NAME) $(CFLAGS) $(METADATA_COMPILED) $(LDLIBS)

metadata:
	windres $(METADATA_RAW) -o $(METADATA_COMPILED) --target=pe-x86-64

clean:
	rm -rf space_invaders.exe game.zip metadata.rc.data release

release:
	mkdir -p release
	cp -r assets release.exe release/
	7z a -tzip game.zip release
	rm -rf release
