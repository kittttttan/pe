{-
Add all the natural numbers below one thousand
that are multiples of 3 or 5.
-}

import Test.QuickCheck
import Data.List

prop_Pe1 :: Integer -> Bool
prop_Pe1 n = (pe1 n) == (pe1a n)

pe1 :: Integer -> Integer
pe1 limit = pe1c limit

-- recursive
pe1a :: Integer -> Integer
pe1a limit = fst $ pe1a_ 0 limit

pe1a_ :: Integer -> Integer -> (Integer, Integer)
pe1a_ s n
    | n == 0 = (s, 0)
    | mod n 3 == 0 || mod n 5 == 0 = pe1a_ (s + n) (n - 1)
    | otherwise = pe1a_ s (n - 1)

-- sum of list
pe1b :: Integer -> Integer
pe1b limit = sum[x | x <- [1..limit], mod x 3 == 0 || mod x 5 == 0]

-- foldl'
pe1x :: Integer -> Integer
pe1x limit = foldl1' (+) [x | x <- [1..limit], mod x 3 == 0 || mod x 5 == 0]

-- calc
pe1c :: Integer -> Integer
pe1c n
    | n < 3     = 0
    | otherwise = div (3 * n3 * (n3 + 1) + 5 * n5 * (n5 + 1) - 15 * n15 * (n15 + 1)) 2
         where
         n3 = div n 3
         n5 = div n 5
         n15 = div n 15

main :: IO()
main = do
    print $ pe1 1000
