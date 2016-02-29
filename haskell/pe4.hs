{-

-}

pe4 :: Int -> [Int]
pe4 n = [x | y <- [first..last], z <- [y..last], let x = y * z, let s = show x, s == reverse s]
    where
    first = 10 * n ^ (n - 1)
    last = 10 ^ n - 1

main :: IO()
main = do
    print $ maximum $ pe4 3
