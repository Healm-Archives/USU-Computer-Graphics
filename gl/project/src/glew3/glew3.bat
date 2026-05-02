set PATH=%PATH%;bin
g++ src/glew3/glew3.cpp -Iinclude -Llib -lglew32 -lglfw3 -lopengl32 -lgdi32 -o src/glew3/app.exe
.\src\glew3\app
@REM pause

