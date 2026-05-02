set PATH=%PATH%;bin
g++ src/glew2/glew2.cpp -Iinclude -Llib -lglew32 -lglfw3 -lopengl32 -lgdi32 -o src/glew2/app.exe
.\src\glew2\app
@REM pause

