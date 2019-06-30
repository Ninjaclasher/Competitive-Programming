import Control.Monad

main = do
    n <- read <$> getLine :: IO Int
    arr <- replicateM n (getLine)
    putStrLn . unlines $ map (\x -> show $ length x) arr
