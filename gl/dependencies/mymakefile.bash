
# building glew for minGW from linux

# sudo apt install mingw-w64

# Makefile.mingw (probably line 9)
# LDFLAGS.EXTRA += -nostdlib

make SYSTEM=linux-mingw64 \
     CC=x86_64-w64-mingw32-gcc \
     LD=x86_64-w64-mingw32-ld \
     AR=x86_64-w64-mingw32-ar \
     RANLIB=x86_64-w64-mingw32-ranlib \
     STRIP=x86_64-w64-mingw32-strip

grab lib folder
     - glew32.dll (put in bin)
     - libglew32.a (put in lib)
     - libglew32.dll.a (put in lib)
