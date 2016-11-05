@echo off
setlocal

cd /d "%~dp0"

dartdevc.bat --modules common -o build\out.js main.dart

exit /b
