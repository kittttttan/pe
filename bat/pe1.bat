@echo off
setlocal

if "%1"=="/?" call :usage&exit /b

set ans=0

set loop=0
if /i "%1" == "/L" set loop=1&shift

set n=1000
if not "%1" == "" set n=%1
echo n = %n%

if %loop%==1 (
  echo Problem1 Loop
  call :pe1loop
) else (
  echo Problem1 non Loop
  call :pe1 %n%
)

echo %ans%
exit /b

:usage
  echo Solve Project Euler Problem 1
  echo.
  echo PE1 [/L] [NUMBER]
  echo.
  echo.  ^/L loop
goto :EOF

:pe1
  set /a t1 = %1 / 3
  set /a t2 = %1 / 5
  set /a t3 = %1 / 15
  set /a ans = ^
    (3 * t1 * (t1 + 1) + 5 * t2 * (t2 + 1) ^
        - 15 * t3 * (t3 + 1)) ^>^> 1
goto :EOF

:pe1loop
  for /L %%i in (3, 1, %n%) do call :add %%i
goto :EOF

:add
  set /a t1 = %1 %% 3
  if %t1% equ 0 set /a ans += %1 & goto :EOF
  set /a t2 = %1 %% 5
  if %t2% equ 0 set /a ans += %1
goto :EOF
