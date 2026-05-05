
# building glew for minGW from linux

# sudo apt install mingw-w64

# Makefile.mingw (probably line 9) (this step is only for gcc?)
# LDFLAGS.EXTRA += -nostdlib

# build with gcc installed from apt
make SYSTEM=linux-mingw64 \
     CC=x86_64-w64-mingw32-gcc \
     LD=x86_64-w64-mingw32-ld \
     AR=x86_64-w64-mingw32-ar \
     RANLIB=x86_64-w64-mingw32-ranlib \
     STRIP=x86_64-w64-mingw32-strip

# build with clang
x86_64-w64-mingw32-clang \
  -target x86_64-w64-windows-gnu \
  --sysroot=/home/healm/susdo/toolchains/mingw \
  -fuse-ld=lld \
  -nostdlib \
  -DGLEW_BUILD \
  -Iinclude \
  src/glew.c \
  -shared \
  -lopengl32 -lgdi32 -luser32 -lkernel32 \
  -Wl,--out-implib,lib/libglew32.dll.a \
  -o lib/libglew32.dll

# build with gcc installed from llvm 
x86_64-w64-mingw32-gcc \
  -nostdlib \
  -DGLEW_BUILD \
  -Iinclude \
  src/glew.c \
  -shared \
  -lopengl32 -lgdi32 -luser32 -lkernel32 \
  -Wl,--out-implib,lib/libglew32.dll.a \
  -o lib/libglew32.dll

grab lib folder
     - glew32.dll (put in bin)
     - libglew32.a (put in lib) (only for gcc)
     - libglew32.dll.a (put in lib)
