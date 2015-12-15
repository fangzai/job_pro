import Prelude hiding (max, min)
import Data.Char hiding (toUpper, isDigit)
-- 好奇怪的说，这个import只能在前面，如果在后面的话就会报错
{-
by ht, 2015/12/14
该脚本用于演示Int上的意见简单操作
-}
-- size 的值是一个整数Int,　定义为14 和13的和
size :: Int
size = 12 + 13

-- 计算整数的平方

square :: Int -> Int
square n = n * n

-- 计算整数的2倍

double :: Int -> Int
double n = n * 2

--　利用double, square和size的例子
example :: Int
example = double (size - square ( 2 + 2 ))

-- 守卫
-- 下面第一个max已经在prelude里面有定义了，所以这里如果再继续定义
-- 并且调用的话会报错的
max :: Int -> Int -> Int 
max x y
	| x >= y     = x
	| otherwise  = y

min :: Int -> Int -> Int
min x y
	| x >= y    = y
	| otherwise = x

maxThree :: Int -> Int -> Int -> Int
maxThree x y z
	| x >=y && x >= z   = x
	| y >= z            = y
	| otherwise         = z
minThree :: Int -> Int -> Int-> Int
minThree x y z
	| x <= y && x <= z  = x
	| y <= z            = y
	| otherwise         = z

-- 系统中import Data.Char里面有一些常用的函数
-- isAscii,isControl,isPrint,isSpace,isUpper,isLower
-- ord,chr等等　　ord将字母转换为数字，chr相反
-- 系统自带方法 ord :: Char -> Int 
--				chr :: Int -> Char
offset :: Int
offset = ord 'A' - ord 'a'

toUpper :: Char -> Char
toUpper ch = chr (ord ch + offset)

isDigit :: Char -> Bool  --输出是bool类型
isDigit ch = ('0' <= ch) && (ch <= '9')

-- if 语句
maxNumber :: Int -> Int -> Int
maxNumber x y = if x >= y then x
				else y

-- myToUpper的作用就是将小写字母转化为大写，非小写字母不变
myToUpper :: Char -> Char
myToUpper ch = if (ord ch) >= (ord 'a') && (ord ch) <= (ord 'z') then toUpper ch
			   else ch
-- 将字符转变为数字
charToNum :: Char -> Int
charToNum ch = if (ord ch) >= (ord '0') && (ord ch) <= (ord '9') then (ord ch) - (ord '0')
			   else 0

-- 数值计算 从int转化为float没有默认转换，必须显式进行
averageThree :: Int -> Int -> Int -> Float 
averageThree x y z = fromIntegral (x + y + z) / fromIntegral 3


-- 返回输入中大于平均值的个数
howManyAboveAverage :: Int -> Int -> Int -> Int
above :: Int -> Float -> Int
above x y = if fromIntegral x > y then 1
			else 0
howManyAboveAverage x y z = (above x (averageThree x y z)) + (above y (averageThree x y z)) + (above z (averageThree x y z))

-- 输入a b c，求a b c组成二次方程root的个数 这里假设a !=0
numberNRoots :: Float -> Float -> Float -> Int
numberNRoots a b c = if b*b > 4.0 * a * c  then 2
					else if b*b == 4.0 * a * c then 1
						else 0
-- 这里没有给a的限定条件
numberRoots :: Float -> Float -> Float -> Int
numberRoots a b c 
				| a == 0    = 1
				| otherwise = numberNRoots a b c
