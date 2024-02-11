# Raylib Template (Windows)

This template aims to be a quick and modular raylib C development setup for windows.

## Step by step:

1. Download and install the latest official raylib windows installer (64bit MinGW compiler). https://www.raylib.com/

2. Add the following to the system PATH: `C:\raylib\w64devkit\bin`.

3. (Optional, needed to build the release package) Download 7z and add it to the system path, for example: `C:\Program Files\7-Zip`.

4. Clone this repository and run `make` inside the root folder.

There you go! at this point you should see an alien on the screen. You can now modify the metadata and add source code files to the `src/` folder in order to build your game/app.

## Makefile:

By default you can run `make`, the project will compile and execute with debug flags and the terminal running in the background.

Also you can run `make release` to compile with optimization flags and no background terminal, additionally, it will create a .zip file with the final project. (Needs 7z installed, see step 3 of the setup guide).
