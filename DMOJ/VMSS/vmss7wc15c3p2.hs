import Control.Monad
import Data.List

main = do
    [n, k] <- map(read :: String -> Int) <$> words <$> getLine
    arr <- replicateM n (read <$> getLine :: IO Int)
    print(sum(take k (filter (>0) . reverse $ sort arr)))
