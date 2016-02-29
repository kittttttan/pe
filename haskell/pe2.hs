{-

-}

import Fib

pe2 :: Integer -> Integer
pe2 n = sum[x | x <- takeWhile (< n) fibs, even x]

pe2' :: Integer -> Integer
pe2' n = sum[x | x <- takeWhile (< n) fibs', even x]

main :: IO()
main = do
    print $ pe2 4000000
