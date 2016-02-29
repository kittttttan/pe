primesTME :: () -> [Int]
primesTME () = 2 : ([3,5..] `minus` join [[p*p,p*p+2*p..] | p <- primes]) 
  where
    primes = 3 : ([5,7..] `minus` join [[p*p,p*p+2*p..] | p <- primes])   
    join  ((x:xs):t)    = x : union xs (join (pairs t))
    pairs ((x:xs):ys:t) = (x : union xs ys) : pairs t

minus :: [Int] -> [Int] -> [Int]
minus (x:xs) (y:ys) = case (compare x y) of 
    LT -> x : minus  xs  (y:ys)
    EQ ->     minus  xs     ys 
    GT ->     minus (x:xs)  ys
minus  xs     _     = xs

union :: [Int] -> [Int] -> [Int]
union (x:xs) (y:ys) = case (compare x y) of 
    LT -> x : union  xs  (y:ys)
    EQ -> x : union  xs     ys 
    GT -> y : union (x:xs)  ys
union  xs     ys    = xs ++ ys

pe7 :: Int
pe7 = last $ take 10001 $ primesTME()

main :: IO()
main = do
    print $ pe7
