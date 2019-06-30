main = do
    [n, m] <- map(read :: String -> Integer) <$> words <$> getLine
    print(max (n * m) (max(n + m) (abs(n - m))))
