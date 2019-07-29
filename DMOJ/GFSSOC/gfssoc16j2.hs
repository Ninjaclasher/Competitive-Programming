import Control.Monad
main = do
    scores <- replicateM 6 (read <$> getLine :: IO Int)
    aif <- read <$> getLine :: IO Int
    limit <- read <$> getLine :: IO Int
    if (sum scores) + 6 * aif >= 6 * limit
        then putStrLn "yes"
        else putStrLn "no"
