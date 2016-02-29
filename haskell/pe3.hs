{-

-}

import Util

pe3 :: Integer -> [Integer]
pe3 n = factorize n (2:[3,5..])

main :: IO()
main = do
    print $ pe3 600851475143
