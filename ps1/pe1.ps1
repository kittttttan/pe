Param([int] $n)
if ($n -lt 1) {
  $n = 1000
}

[int] $a = 0

for ($i = 0; $i -le $n; $i++) {
  if ($i % 3 -eq 0 -or $i % 5 -eq 0) {
    $a += $i
  }
}

echo $a
