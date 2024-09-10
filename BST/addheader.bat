@echo off

REM Check if a parameter is provided
if "%1"=="" (
    echo No header name provided. Exit...
    exit /b 1
)

touch headers/"%1".h
touch src/"%1".cpp

echo Done.
code headers/"%1".h src/"%1".cpp
