{-

-}

pe5 :: Integer -> Integer
pe5 n
    | n < 2     = 1
    | otherwise = foldr1 lcm [2..n]

main :: IO()
main = do
    print $ pe5 20
