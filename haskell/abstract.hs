-- 列表概括
double :: [Int] -> [Int]
double xs = [2*x | x <- xs]

-- 函数递归
double [] = []
double (x:xs) = 2*x : double xs


-- map的原型函数 
map :: (a -> b) -> [a] -> [b]

-- 原子函数
double :: Int -> Int
double x = 2*x

map double list  -- list就是输入的参数

-- 原子函数
isEven :: Int -> Bool
isEven n = (n `mod` 2 == 0)

positive :: Int -> Bool
positive n = (n > 0)
--filter 函数原型
filter :: (a -> Bool) -> [a] -> [a]

-- 递归
filter p [] = []
filter p (x:xs)
	| p x 		= x :filter p xs
	| otherwise =    filter p xs 
--列表概括
filter p xs = [ x | x <- xs, p x]

filter isEven list    -- 求解list中所有偶数
filter positive list  -- 求解list中所有正数

--折叠函数
-- foldr1 定义
foldr1 :: (a -> a -> a) -> [a] -> a
-- 第一个是函数，输入有两个，比如关于Int上的(+)
-- 第二个是列表,最后一个是输出，比如
foldr1 (+) [3, 2, 1]   -- 结果就是 6

-- foldr 定义
foldr :: (a -> a -> a) -> a ->[a] -> a  --和上面最大的区别就是有了初始值，第2个参数
-- 递归定义
foldr f s []	= s
foldr f s (x:xs)= f x (foldr f s xs)   
-- 理论上来说 foldr1是 foldr的特殊形式，也就是说s = 0或者是True等等


-- 关于foldr的用法　foldr func ini list                                                                            
-- func是函数　ini表示当list为空的时候初始值　list是foldr参数列表                                                  
-- 求1 -> n 的平方和
sumSqrt :: Int -> Int                                                                                              
sumSqrt n = foldr (+) 0 (map square [1..n])                                                                        
-- 求list中大于0的整数的平方和                                                                                                        
sumPos :: [Int] -> Int                                                                                             
sumPos list = foldr (+) 0 (map square (filter positive list)) 

-- f是原子函数
twice f = (f . f)  -- twice函数的定义将f在输入上应用两次
-- succ是取输入的下一个值，比如succ n 返回 n +１
-- 如此而言
(twice succ) 12  -- 返回的结果就是 14 
-- 上面的一句其实是等价于 succ . succ的

-- 在Prelude其实有一个内置的函数 iter可以自动将函数复合指定次数
-- iter定义
iter :: Int -> (a -> a) -> (a -> a)

iter :: n f
	| n > 0		= f . iter (n-1) f
	| otherwise = id --表示空什么都不做

-- 举个例子
iter n double 1 -- 相当于把 (double 1) 复合n次，也就是2^n

-- 输入n，输出是一个函数
addNum :: [Int] -> (Int -> Int)
addNum n = addN
	where
		addN m = n + m   --m是返回函数的输入 
--关于addN我们可以简单写为  
\m -> n + m  -- 这是lambda函数的写法
-- 箭头左边是输入参数，右边是输出结果
-- 所以addNum可以写成
addNum n = (\m -> n + m)  

-- comp2的严格定义
comp2 :: (a -> b) -> (b -> b ->ｃ) -> (a -> a ->c)
-- 第一个输入是f,第二个输入是g, 最后是合成函数
--等价于
comp2 f g = (\x y -> g (f x) (f y))
--应用
comp2 sq add 3 4 -- 该用法的就是将 3和4的平方相加

--另外，由于lambda隐函数的作用
f x y x = result
-- 和
\x y z -> result --的作用是完全一样的

multiply :: Int -> Int -> Int
multiply x y = x * y
 
doubleAll :: [Int] -> [Int]
doubleAll xs = map (multiply 2) xs

member :: String -> Char -> Bool
member xs x = elem x xs


-- unit test
-- data 
nums = [1,5, (-2),7] :: [Int]
whitespace = "\t\n" :: String 
str = "hello world \n \t base \n I am \t OK!"

-- for member test
testMember :: (String -> String) -- 过滤掉whitespace里面的内i容
-- 返回的是函数
--testMember = filter (not . (member whitespace))
testMember = filter (\x -> not (elem x whitespace))

testOpt :: ([Int] -> [Int])
testOpt = filter (>0) . map (+1)  -- 先加上1然后过滤掉小于0的元素

-- for doubleAll test 
testDoubleAll :: [Int]
testDoubleAll = doubleAll nums




















