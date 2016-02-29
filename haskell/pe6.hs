pe6 :: Int -> Int
pe6 n = (sum [1..n]) ^ 2 - (sum $ map (^ 2) [1..n])

main :: IO()
main = do
    print $ pe6 100
