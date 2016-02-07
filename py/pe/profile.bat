@echo off
setlocal

if "%1"=="" (
  echo pe_profile ProblemNumber
  exit /b
)

set CDIR=%~dp0

@echo on
python -m cProfile %CDIR%pe%1.py %*
@echo off

exit /b
