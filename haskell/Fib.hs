{-
Fibonacci sequence
-}

module Fib where
    import Data.List
    import Data.Bits

    fibs :: [Integer]
    fibs = 0 : 1 : zipWith (+) fibs (tail fibs)

    zipWith' f (a:as) (b:bs) = x `seq` x : zipWith' f as bs
        where
        x = f a b
    zipWith' _ _ _ = []

    fibs' :: [Integer]
    fibs' = 0 : 1 : zipWith' (+) fibs (tail fibs)

    fib :: Int -> Integer
    fib n = snd . foldl' fib' (1, 0) . dropWhile not $
                [testBit n k | k <- let s = finiteBitSize n in [s-1,s-2..0]]
        where
            fib' (f, g) p
                | p         = (f*(f+2*g), ss)
                | otherwise = (ss, g*(2*f-g))
                where ss = f*f+g*g

    fib1 :: Int -> Integer
    fib1 n = snd . foldl fib' (1, 0) . map (toEnum . fromIntegral) $ unfoldl divs n
        where
            unfoldl f x = case f x of
                    Nothing     -> []
                    Just (u, v) -> unfoldl f v ++ [u]
     
            divs 0 = Nothing
            divs k = Just (uncurry (flip (,)) (k `divMod` 2))
     
            fib' (f, g) p
                | p         = (f*(f+2*g), f^2 + g^2)
                | otherwise = (f^2+g^2,   g*(2*f-g))
