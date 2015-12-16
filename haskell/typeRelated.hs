{-----------------------------------------------------------
 - by ht, 2015/12/16
 - type related  处理相关的类型问题
 -----------------------------------------------------------}
import Prelude

-- 内置函数putStr的原型是 putStr :: String -> IO()
--onLine :: String -> IO()
--onLine str = putStr (str ++ "\n")

onLine :: String -> String
onLine str = str ++ "\n"

onThreeLines :: String -> String -> String -> String
onThreeLines str1 str2 str3 = str1 ++ "\n" ++ str2 ++ "\n" ++ str3 ++ "\n"


onSeparateLines :: [String] -> String
onSeparateLines strList = concat [onLine str | str <- strList]

-- 字符串拼接
onDuplicate :: String -> Int -> String
onDuplicate str n
		| n <= 0    = " \n"
		| n == 1    = str ++ "\n"
		| otherwise = str ++ (onDuplicate str (n-1))

-- 计算斐波拉契数列的递推
fibStep :: (Int, Int) -> (Int, Int)
fibStep (u, v) = (v, u + v)

fibSeq :: Int -> (Int, Int)
fibSeq n 
	| n == 0 = (0, 1)
	| otherwise = fibStep (fibSeq (n-1))

-- 字符拼接
fibTable :: Int -> String
fibTable n 
	| n < 0      = error "输入不能是负数"
	| n == 0  　 = "0\t0"
	| otherwise  = fibTable (n-1) ++"\n" ++ (show n) ++ "\t" ++ (show (snd(fibSeq (n-1))))

-- haskell 语言中where语句可以用来存储中间结果

maxsq :: Int -> Int -> Int
maxsq x y 
	| sq x > sq y	= sq x
	| otherwise		= sq y
		where sq z = z * z -- 定义函数

-- unit test
-- for maxsq　test
testMaxsq :: IO()
testMaxsq = putStr ((show (maxsq 3 4)) ++ "\n")


-- for fibTable test
n = 5
testFibTable :: IO()
testFibTable = putStr ((fibTable n) ++ "\n")



-- for onDuplicate test
str = "wang"
testOnDuplicate :: Int -> IO()
testOnDuplicate n = putStr (onDuplicate str n)


-- for onThreeLines　test
testOnThreeLines :: IO()
testOnThreeLines = putStr (onThreeLines "hello" "world" "j2001")

-- for onSeparateLines test
strList = ["Are", "you", "OK!"]
--testOnSeparateLines :: [String] -> IO()
--testOnSeparateLines strList = putStr (onSeparateLines strList)
testOnSeparateLines :: IO()
testOnSeparateLines = putStr (onSeparateLines strList)
