@echo off

REM Check if a parameter is provided
if "%1"=="" (
    echo No folder name provided. Exit...
    exit /b 1
)

REM Check if the specified folder exists
if not exist "%1"  (
    echo Creating folder "%1"...
    mkdir "%1"
) else  (
    echo Folder "%1" already exists.
)


REM Check if the folder is already initialized (Makefile exists)
cd "%1"
if exist "Makefile" (
    echo This project has already been initialized. Exiting...
    cd ..
    exit /b 0
)

REM Initialize the folder

echo Add Makefile...
cp ../.initializers/Makefile_template.txt Makefile

echo Creating necessary folders...
mkdir headers obj src bin

echo Configuring preset files...
cp ../.initializers/main.txt src/main.cpp
cp ../.initializers/headers.txt headers/headers.h
cp ../.initializers/addheader.bat addheader.bat

echo Project successfully initialized.
code src/main.cpp
