{-----------------------------------------------------------------
 -- by ht, 2015/12/16
 -- 关于模式匹配
 -----------------------------------------------------------------}
import Data.Char
---------------
-- 关于模式匹配
---------------

firstDigit :: String -> Char
firstDigit st = case ([ch | ch <- st, isDigit ch]) of 
		[]		-> '\0'
		(x:_)	-> x

-----------
-- 递归操作
-----------	
onSum :: [Int] -> Int
onSum list = case (list) of
			[]		-> 0				-- 当递归为空的时候
			(x:xs)	-> x + onSum xs		-- 模式匹配，取出第一项,剩下的项目为xs 

onProduct :: [Int] -> Int
onProduct list = case (list) of
			[]		-> 1 
			(x:xs)	-> x * onProduct xs

onAnd :: [Bool] -> Bool
onAnd list = case (list) of
		[]		-> True
		(x:xs)	-> (x && (onAnd xs))

onOr :: [Bool] -> Bool
onOr list = case (list) of
		[]		-> False
		(x:xs)	-> (x || (onOr xs))

onConcat :: [[Int]] -> [Int]
onConcat list = case (list) of 
		[]		-> []
		(x:xs)	-> x ++ (onConcat xs)

onElem :: Int -> [Int] -> Bool
onElem target list = case (list) of
		[]		-> False
		(x:xs)	-> (target == x) || (onElem target xs)

doubleAll :: [Int] -> [Int]
doubleAll list = case (list) of
		[]		-> []
		(x:xs)	-> 2*x : (doubleAll xs)
-- 取出为偶数的
isEven :: Int -> Bool
isEven n = if n `mod` 2 == 0 then True
		   else False
selectEven :: [Int] -> [Int]
selectEven list = [ele | ele <- list, isEven ele]

-- 插入排序实现
-- 插入单个元素
insert :: Int -> [Int] -> [Int]
insert target list = case (list) of
			[]		-> [target]
			(y:ys)	-> if target <= y then target : (y : ys)
					   else y : (insert target ys)

iSort :: [Int] -> [Int]
iSort list = case (list) of
		[]		-> []
		(x:xs)	-> insert x (iSort xs)

-- 模式判别和函数定义实现求解某个元素在列表中出现的次数
elemNum :: Int -> [Int] -> Int
elemNum target list = sum [1 | ele <- list, ele == target]

-- 删除列表中的某元素
deleteElem :: Int -> [Int] -> [Int]
deleteElem target list = [ sn | sn <- list, target /= sn]

-- 列表概括实现获取列表中出现１次的元素

unique :: [Int] -> [Int]
unique list = [sn | sn <- list, (elemNum sn list) == 1]
-- 模式匹配实现列表中只出现一次的元素
uniqueRec :: [Int] -> [Int]
uniqueRec list = case (list) of
		[]		-> []
		(x:xs)	-> if (elemNum x xs) == 0 then x : uniqueRec xs
				   else uniqueRec (deleteElem x xs)
-- 模式匹配实现列表中出现过的元素
uniqueElem :: [Int] -> [Int]
uniqueElem list = case (list) of
		[]		-> []
		(x:xs)	-> if (elemNum x xs) == 0 then x : uniqueElem xs
				   else uniqueElem xs

------------
-- unit test
------------

target = 7 
numList = [7, 7, 10, (-1)]
-- for unique test
testUnique :: [Int]
testUnique = unique numList

-- for uniqueRec test
testUniqueRec :: [Int]
testUniqueRec = uniqueRec numList

-- for elemNum test
testElemNum :: Int
testElemNum = elemNum target numList 

-- for iSort test
testISort :: [Int]
testISort = iSort numList


-- for selectEven test
testSelectEven :: [Int]
testSelectEven = selectEven numList

-- for doubleAll test
testDoubleAll :: [Int]
testDoubleAll = doubleAll numList

-- for onElem test
testOnElem :: IO()
testOnElem = putStr ((show (onElem target numList)) ++ "\n")

-- for onConcat test
listlist = [[2,3],[1],[9,5,10],[]]
testOnConcat :: [Int]
testOnConcat = onConcat listlist

-- for firstDigis test
strList = ["hell1h3h34hda!", "hello wolrd!"]
testFirstDigit :: IO()
testFirstDigit = putStr (([firstDigit str |str <- strList]) ++ "\n")

-- for onSum test
testOnSum :: IO()
testOnSum = putStr ((show (onSum numList)) ++ "\n")
-- for onProduce test
testOnProduct :: IO()
testOnProduct = putStr ((show (onProduct numList)) ++ "\n")


boolList = [False, True, True, False]
-- for onAnd test
testOnAnd :: IO()
testOnAnd = putStr ((show (onAnd boolList)) ++ "\n")

-- for onOr test
testOnOr :: IO()
testOnOr = putStr ((show (onOr boolList)) ++ "\n")

