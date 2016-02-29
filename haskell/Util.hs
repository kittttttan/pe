{-
Fibonacci sequence
-}

module Util where

    factorize :: Integer -> [Integer] -> [Integer]
    factorize n (x:xs)
        | n < x * x    = [n]
        | mod n x == 0 = x : factorize (div n x) (x:xs)
        | otherwise    = factorize n xs
