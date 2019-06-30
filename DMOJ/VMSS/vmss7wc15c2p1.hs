import Control.Monad

f :: Int -> Bool
f x = do
   x <= 41

main = do
    n <- read <$> getLine :: IO Int
    arr <- replicateM n (read <$> getLine :: IO Int)
    print . sum $ map (\x -> if (x-1 < 0 || f(arr!!(x-1))) && f(arr!!x) && (x+1 > n-1 || f(arr!!(x+1))) then 1 else 0) [0..n-1]
