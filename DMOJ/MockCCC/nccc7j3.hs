main = do
    [n, k] <- map(read :: String -> Integer) <$> words <$> getLine
    print (quot (n * k + k) (k + 1))
