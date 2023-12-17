msort :: Ord a => [a] -> [a]
msort = mergesort' . map (: [])

mergesort' :: Ord a => [[a]] -> [a]
mergesort' [] = []
mergesort' [xs] = xs
mergesort' xss = mergesort' (mergePairs xss)

mergePairs :: Ord a => [[a]] -> [[a]]
mergePairs [] = []
mergePairs [xs] = [xs]
mergePairs (xs : ys : xss) = merge xs ys : mergePairs xss

merge :: Ord a => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x : xs) (y : ys)
  | x <= y = x : merge xs (y : ys)
  | otherwise = y : merge (x : xs) ys

-- wrap :: a -> [a]
-- wrap x = [x]

main :: IO ()
main =
  do
    print (msort [3, 4, 1])
    print (msort [])
