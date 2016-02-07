#!/bin/sh

if [ -z $1 ]
then
  echo ./pe_timeit.sh ProblemNumber [loop] [option]
  exit 0
fi

N=1
if [ ! -z $2 ]
then
  N=$2
fi

echo python -m timeit -n $N -r 1 -s "\"import pe$1\"" "\"pe$1.pe$1($3)\""
python3 -m timeit -n $N -r 1 -s "\"import pe$1\"" "\"pe$1.pe$1($3)\""
python3 -m timeit -n $N -r 1 -s "\"import pyximport\"" "\"pyximport.install()\"" "\"import pe$1\"" "\"pe$1.pe$1($3)\""
python3 -OO -m timeit -n $N -r 1 -s "\"import pe$1\"" "\"pe$1.pe$1($3)\""
python3 -OO -m timeit -n $N -r 1 -s "\"import pyximport\"" "\"pyximport.install()\"" "\"import pe$1\"" "\"pe$1.pe$1($3)\""

exit 0
