main = do
    let good = [1, 1, 2, 2, 2, 8]
    cur <- map (read :: String -> Integer) <$> words <$> getLine
    putStrLn . unwords $ map (\x -> show ((fst x) - (snd x))) (zip good cur)
