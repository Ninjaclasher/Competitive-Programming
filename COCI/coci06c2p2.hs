import Data.Char
import Data.List

main = do
    arr <- map(read :: String -> Integer) <$> words <$> getLine
    let v = sort arr
    order <- getLine
    putStrLn(unwords(map (\x -> show(v!!(ord x - 65))) order))
