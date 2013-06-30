@echo off
setlocal

for %%i in (pe*.py) do (
if not %%i==pe.py (
echo %%i
pypy -m timeit -n 1 -r 3 -s "import %%~ni" "%%~ni.%%~ni()"
)
)

exit /b
