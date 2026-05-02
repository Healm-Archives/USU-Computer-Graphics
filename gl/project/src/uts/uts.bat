set PATH=%PATH%;bin
g++ src/uts/uts.cpp -Iinclude -Llib -lglew32 -lglfw3 -lopengl32 -lgdi32 -o src/uts/app.exe
.\src\uts\app
@REM pause

