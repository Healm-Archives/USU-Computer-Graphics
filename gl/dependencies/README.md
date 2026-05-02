# Dependencies

setting up GLFW and GLEW to run on windows with minGW without visual studio

## GLFW

1. download GLFW (this project uses glfw-3.3.8.bin.WIN64.zip)
2. inside downloaded GLFW

        - copy header (.h) files inside include/ folder to your include/ folder
                glfw3.h
                glfw3natine.h
                
        - copy dll and lib from lib-mingw-w64/
                - move glfw3.dll file into bin/ folder
                - move libglfw3.a, libglfw3dll.a files to lib/ folder

## GLEW

        - download GLEW (this project uses glew-2.1.0.tgz)
        - inside downloaded GLEW
                - copy header (.h) files inside include/ folder to your include/ folder
                        - eglew.h
                        - glew.h
                        - glxew.h
                        - wglew.h

        - to get the .dll and .a files, i manually compiled glew from Linux using mingw toolchain
                - Step-by-step:
                        - install mingw-w64
                                sudo apt install mingw-w64

                - inside the glew folder, Makefile.mingw (glew-2.1.0/config/Makefile.mingw)
                - comment the -nostdlib flag inside that makefile
                        - example :
                        - Makefile.mingw (probably line 9)
                        - # LDFLAGS.EXTRA += -nostdlib

                - run make
                        make SYSTEM=linux-mingw64 \
                                CC=x86_64-w64-mingw32-gcc \
                                LD=x86_64-w64-mingw32-ld \
                                AR=x86_64-w64-mingw32-ar \
                                RANLIB=x86_64-w64-mingw32-ranlib \
                                STRIP=x86_64-w64-mingw32-strip

                - inside lib folder in glew, copy dll and lib from lib-mingw-w64/
                        - glew32.dll
                        - move .dll file into bin/ folder

                        - libglew32.a
                        - libglew32.dll.a
                        - move .a files to lib/ folder

- note 
        - .lib file are only compatible with visual studio
        - .dll files need to be on the same directory as .exe (unless the path to the dll is added to PATH)

## Project Compile using bat files

using bat file to temporarily add bin/ folder to PATH, we will link and compile the project using glfw and glew flag before executing the exe file.

        ```bat
        set PATH=%PATH%;bin
        g++ src/uts/uts.cpp -Iinclude -Llib -lglew32 -lglfw3 -lopengl32 -lgdi32 -o src/uts/app.exe
        .\src\uts\app
        ```
