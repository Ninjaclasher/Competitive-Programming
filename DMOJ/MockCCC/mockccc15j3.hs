import qualified Data.Set

main = do
    n <- read <$> getLine :: IO Int
    arr <- map(read :: String -> Int) <$> words <$> getLine
    print . Data.Set.size . Data.Set.fromList $ arr
