@echo off
setlocal

if "%1"=="" (
  echo pe_timeit ProblemNumber [loop] [option]
  exit /b
)

set /a N=1
if not "%2"=="" set /a N=%2

@echo on
python -m timeit -n %N% -r 1 -s ^
"import pe%1" "pe%1.pe%1(%3)"
@echo off

exit /b
