#!/bin/sh

if [ "$1" == "-h" ]
then
  echo Usage: ./$0 [option] [number]
  echo
  echo "  -l  loop"
  exit 0
fi

declare -i n=1000
declare -i loop=0
if [ "$1" == "-l" ]
then
  echo loop
  loop=1
  shift
else
  echo no loop
fi

if [ "$1" != "" ]
then
  n=$1
fi

echo n = $n

declare -i ans=0
if [ $loop -eq 1 ]
then
  for ((i = 3; i <= $n; ++i))
  do
    if [ $((i % 3)) -eq 0 -o $((i % 5)) -eq 0 ]
    then
      ((ans += i))
    fi
  done
else
  declare -i t1=$((n / 3))
  declare -i t2=$((n / 5))
  declare -i t3=$((n / 15))
  ((ans = (3 * t1 * (t1 + 1) + 5 * t2 * (t2 + 1) - 15 * t3 * (t3 + 1)) >> 1))
fi

echo $ans
exit 0
