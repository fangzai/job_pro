{--------------------------------------------------------------------
 - by ht, 2015/12.17
 - 列表上的递归续
 --------------------------------------------------------------------}
 
 -- 多个列表递归
onZip :: [a] -> [b] -> [(a, b)]
onZip la lb = case (la) of
		[]		-> []
		(x:xs)	-> case (lb) of
				[]		-> []
				(y:ys)	-> (x, y) : onZip xs ys

-- take的实现
onTake :: Int -> [a] -> [a]
onTake n list = if n <= 0 then []
				else case list of
					[]		-> []
					(x:xs)	-> x : onTake (n-1) xs
-- 快排的实现
qSort :: [Int] -> [Int]
qSort list = case list of
		[]		->[]
		(x:xs)	-> qSort [sn | sn <- xs, sn <= x] ++ [x] ++ qSort [sn | sn <- xs, sn > x]
-- reverse实现
onReverse :: [Int] -> [Int]
onReverse list = case (list) of 
		[]		-> []
		(x:xs)	-> (onReverse xs) ++ [x]

-- unit test

-- for onReverse test
testOnReverse :: [Int]
testOnReverse = onReverse nums1
-- for qSort test
testQSort :: [Int]
testQSort = qSort nums1


-- for onTake test
str = "hello world!"
n = 3
testOnTake :: String
testOnTake = onTake n str

-- for onZip test
nums1 = [10, 1, 8,6]
str1  = ["a", "b", "c", "d", "e"]
testOnZip :: [(Int, String)]
testOnZip = (onZip nums1 str1)
