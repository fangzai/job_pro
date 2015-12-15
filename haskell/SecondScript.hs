import Prelude hiding(length, elem)
import Data.Char

-- 该函数判定x y z三个数字中y是否是中间的数字
between :: Int -> Int -> Int -> Bool
between x y z = if (y <= z && x <= y) || (y <=x && z <= y) then True
				else False

-- 输出给定三个数字中的中间的那个
middleNumber x y z
	| between y x z = x
	| between x y z = y
	| otherwise     = z

-- 计算阶乘
factor :: Int -> Int
factor n
	| n == 0    = 1   --递归出口
	| n > 0     = (factor (n-1)) * n
	| otherwise = error "factor only define on natural numbers"

-- 计算斐波拉契数列
fib :: Int -> Int
fib n
	| n == 0    = 0
	| n == 1    = 1
	| n > 1     = fib (n-2) + fib (n-1)

-- 计算余数和整除
remainder :: Int -> Int -> Int
remainder m n  
	| m < n     = n
	| otherwise = remainder (m - n) n

divide m n
	| n == 0    = error "除数不能为0"
	| m < n     = 0 
	| otherwise = 1 + divide (m - n) n


{-------------------------------------------------------------------
 - 元组问题
--------------------------------------------------------------------}
minAndMax :: Int -> Int -> (Int, Int) --返回最小值和最大值
minAndMax x y
	| x >= y    = (x, y)
	| otherwise = (y, x)

-- 模式匹配 函数定义中不使用单个变量表示，而用元组表示的参数称为模式
addPair :: (Int, Int) -> Int
addPair (x, y) = x + y

-- 斐波拉契数列的二元组函数递推
fibStep :: (Int, Int) -> (Int, Int)
fibStep (u, v) = (v, u + v)

fibPair :: Int -> (Int, Int)
fibPair n
	| n < 0     = error "输入不能是负数！"
	| n == 0    = (0, 1)
	| otherwise = fibStep(fibPair(n - 1))

-- 下面是更快的版本
-- fst :: (Int, Int) -> Int
-- fst (x, y) = x
-- snd :: (Int, Int) -> Int
-- snd (x, y) = y  --这两个函数Prelude里面都有定义


fastFib :: Int -> Int
fastFib = fst . fibPair  
-- 函数合成 fst输入就是fibPair提供的输出,执行的命令是从右边网左边执行

{----------------------------------------------------------------------
 - 列表操作
 ----------------------------------------------------------------------}
 --列表概括
doubleList :: [Int] -> [Int] --这个和元组的声明方式还有些不同
doubleList range =  [2*n | n <- range]

addOrdPairs :: [(Int, Int)] -> [Int]
addOrdPairs pairList = [m + n | (m, n) <- pairList, m < n]

isEven :: Int -> Bool
isEven n = ((n `mod` 2) == 0)
listIsEven :: [Int] -> [Bool]  -- 判断列表中的元素是否是偶数
listIsEven list = [isEven n | n <- list]

-- 判断String中的元素数字提取出来
digits :: String -> String
digits st = [ch | ch <- st, not (isDigit ch)]

-- 定义将字符串中的所有小写字母转换为大写字母其他字符保持不变
capitablize :: String -> String
capitablize st = [toUpper ch | ch <- st]

-- 获取某个数字的所有因子
fullDiv :: Int -> Int -> Bool
fullDiv m n 
	| n== 0               = error "除数不能是０"
	| (m `mod` n) == 0    = True
	| otherwise           = False
divisors :: Int -> [Int]
divisors n = [nu | nu <- [1 .. n], fullDiv n nu]

-- 检查某个整数是否是素数
isPrime :: Int -> Bool
isPrime n
	| n <= 1                     = False
	| n == 2                     = True
	| (length (divisors n)) == 2 = True
	| otherwise                  = False

-- 求列表的长度
length :: [Int] -> Int
length list = sum [1 | xs <- list]

-- 检查某个元素是否在列表中出现
matches :: Int -> [Int] -> [Int]
matches n list = [st | st <- list, st == n]

-- 实现elem函数，检查某个元素是否在list中出现
-- 该函数是内部函数，所以上面需要hiding一下
elem :: Int -> [Int] -> Bool
elem n list = if length (matches n list) >=1 then True
			   else False


