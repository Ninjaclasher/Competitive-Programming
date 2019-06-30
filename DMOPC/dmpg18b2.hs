main = do
    [n, m] <- map(read :: String -> Int) <$> words <$> getLine
    if m > n
        then print n
        else print (m-1)
