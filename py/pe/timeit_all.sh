#!/bin/sh

for i in pe*.py
do
  if [ ! $i = "pe.py" ]
  then
    ni=${i%.*}
    echo ${ni}
    python3 -m timeit -n 1 -r 1 -s "\"import ${ni}\"" "\"${ni}.${ni}()\""
  fi
done

exit 0
