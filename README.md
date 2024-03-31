# Raylib Dev Boilerplate

Basic raylib template to make quick tests or check new features.

## Requirements:

* w64devkit bin folder added to PATH.

* Modify RAYLIB_PATH and RAYGUI_PATH inside the Makefile to match desired setup, defaults to expect the following:

```
/parent-folder
    /raylib
    /raygui
    /raylib-template-C-windows (folder that holds the files of this repo)
```

_(Optional) DEBUG:_

* remedybg and cv2pdb added to PATH.

### How to use:

Simply run `make` inside the root folder and the window will start automatically. Otherwise run `make debug` to open remedybg and main.c as the source file.
