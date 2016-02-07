@echo off
setlocal

python setup.py build_py -c -O2
python setup.py install 

exit /b
