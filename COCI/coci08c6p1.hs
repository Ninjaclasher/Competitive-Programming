main = do
    a <- read <$> getLine :: IO Integer
    t <- getLine
    b <- read <$> getLine :: IO Integer
    if t == "+"
        then print(a + b)
        else print(a * b)
