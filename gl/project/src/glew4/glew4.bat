set PATH=%PATH%;bin
g++ src/glew4/glew4.cpp -Iinclude -Llib -lglew32 -lglfw3 -lopengl32 -lgdi32 -o src/glew4/app.exe
.\src\glew4\app
@REM pause

 