{-------------------------------------------------------------------
 - 计算模型那一章的内容，涉及到map reduce　filter
 - by ht, 2015/12/21
 -------------------------------------------------------------------}
import Prelude
import Data.Char

-- primary function
isEven :: Int -> Bool
isEven x = (x `mod` 2 == 0)

double :: Int -> Int
double x = x * 2

greaterOne :: Int -> Bool
greaterOne n = (n > 6)

addOne :: Int -> Int
addOne n = n + 1

square :: Int -> Int
square n = n * n

positive :: Int -> Bool
positive n = (n > 0)


convertChrs :: [Char] -> [Int]
convertChrs st = map ord st

convertDouble :: [Int] -> [Int]
convertDouble xs = map double xs

-- 关于map实现　可以是列表式的也可以是递归式的
{-
 -- 其实在之前我就已经自己写过这种用法
filter p []	= []
filter p (x:xs)	
	| p x		= x : filter p xs
	| otherwise	=     filter p xs

-- 列表式的
filter p xs = [ x | x <- xs, p x]
-}
-- unit test
-- for map test

nums = [3, 4, 7, 10] :: [Int]  -- 如果不带[Int]会默认是[Integer]
str = "hello"

-- for addUp test
addUp :: [Int] -> [Int]
addUp ns = filter greaterOne (map addOne ns)

-- 关于foldr的用法　foldr func ini list
-- func是函数　ini表示当list为空的时候初始值　list是foldr参数列表
sumSqrt :: Int -> Int
sumSqrt n = foldr (+) 0 (map square [1..n])

sumPos :: [Int] -> Int
sumPos list = foldr (+) 0 (map square (filter positive list))


