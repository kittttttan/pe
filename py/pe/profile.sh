#!/bin/sh

if [ -z $1 ]
then
  echo ./pe_profile.sh ProblemNumber
  exit 0
fi

echo python -m cProfile pe$1.py $*
python3 -m cProfile pe$1.py $*

exit 0
