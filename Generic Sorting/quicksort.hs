qsort :: Ord a => [a] -> [a] -- allows for comparisons
qsort [] = [] -- base case
qsort (p : xs) = qsort lesser ++ [p] ++ qsort greater -- concatenates the list with the smaller numbers and bigger numbers
  where
    lesser = filter (<= p) xs -- filters the values less than or equal to the pivot, adds the numbers to the lesser list
    greater = filter (> p) xs -- filters values greater than the pivot, adds the numbers to the greater list

main :: IO ()
main =
  do
    print (qsort [10, 4, 1])
    -- print (qsort [])
    print (qsort [-1])