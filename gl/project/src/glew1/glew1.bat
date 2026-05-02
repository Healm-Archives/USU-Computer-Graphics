set PATH=%PATH%;bin
g++ src/glew1/glew1.cpp -Iinclude -Llib -lglew32 -lglfw3 -lopengl32 -lgdi32 -o src/glew1/app.exe
.\src\glew1\app
@REM pause

