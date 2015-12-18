{--------------------------------------------------------------
 - by ht, 2015/12/17
 - 关于文本处理的例子
 --------------------------------------------------------------}
-- import System.IO
import Data.Char
import Prelude hiding (getLine)
-- 提取单词
whitespace = ['\t', '\n', ' ']

-- getWord String 提取String里面的第一个单词
getWord :: String -> String
{-
getWord str = case str of
	[]		-> []
	(x:xs)	-> if elem x whitespace  then []
			   else x : getWord xs
-}
getWord [] = []
getWord (x:xs) 
	| elem x whitespace	= []
	| otherwise		= x : getWord xs

-- dropWord String 删除String中的第一个单词
dropWord :: String -> String
dropWord [] = []
dropWord (x:xs)
	| elem x whitespace = (x:xs)
	| otherwise			= dropWord xs

-- dropSpace String 删除String开始的空白
dropSpace :: String -> String
dropSpace [] = []
dropSpace (x:xs)
	| elem x whitespace	= dropSpace xs
	| otherwise			= (x:xs)


type Word = String 

split :: String -> [Word]
split [] = []
split st = (getWord st) : split (dropSpace (dropWord st))
splitWords :: String -> [Word]
splitWords st = split (dropSpace st)

-- 将文本分解为行文本
type Line = [Word]
getLine :: Int -> [Word] -> Line
-- 行的长度,文本
getLine len [] = []
getLine len (w:ws)
	| length w <= len	= w : restOfLine   -- 如果len的长度还没有填满，一直递归
	| otherwise 		= []			   -- 一旦len已经填满，递归结束
	  where
	  newLen	 = len - (length w + 1)	   -- 临时变量
	  restOfLine = getLine newLen ws 

dropLine :: Int -> [Word] -> Line		   -- 和getLine函数配合使用
dropLine len []	= []
dropLine len (w:ws)
	| length w <= len	= restOfLine
	| otherwise  		= (w:ws)
	  where 
	  newLen	 = len - (length w + 1)
	  restOfLine = dropLine newLen ws

-- 将文本分解为行长度为lineLen的格式化文本
splitLines :: Int -> [Word] -> [Line]
splitLines len [] = []
splitLines len list = 
	(getLine len list) :(splitLines len (dropLine len list))

-- 函数合成先splitWords，接着splitLines
fill :: String -> [Line]
fill context = splitLines range (splitWords context)

-- fill函数之后的合并函数
joinWords :: [Word] -> String
joinWords words = (concat [ch ++ " " | ch <- words]) ++ "\n" 
-- 这里只是简单的在每个word后面添加了一个空白相当于左边对齐

-- fillSpace函数真正是两边对齐
fillSpace :: [Word] -> Int -> Int -> [Word]
fillSpace words n m = case words of
	[]		-> []
	(x:[])  -> [x]  -- 最后一个元素后面就不加空白了
	(x:xs)	-> if m >= 0 then ((x ++ (replicate n ' ') ++ " ") : fillSpace xs n (m-1))
			   else ((x ++ (replicate n ' ')) : fillSpace xs n (m-1))
	-- 最后一个循环判定前面m个空白要多加一个空白

joinWords2 :: [Word] -> String
joinWords2 words = ((concat (fillSpace words n m)) ++ "\n")
	where 
		interval	= if (length words) == 1 then 1
					  else (length words) - 1　　-- 如果words里面只有一个元素,则interval可能是０
		space		= range -length (concat words)
		n			= space `quot` interval
		m			= space `mod` interval
{-
joinWords2 words = do
	let interval = (length words)
	let space = range - length (concat words)
	let n = space `quot` interval
	let m = space `mod` interval
	--return ((concat (fillSpace words n m)) ++ "\n")
	return "\n"
-}

-- 函数的目标是将每一行都合并起来成为String
joinLines :: [Line] -> String
joinLines list = concat [joinWords2 ch | ch <- list]
-- joinLines　list = concat [joinWords ch | ch <- list]

-- fill与joinLines合成函数,相当于格式化的过程
stringFormat :: String -> String
stringFormat  st= joinLines (fill st)

{-
filename = "src.txt"
-- 传入句柄，读取每行数据
readLines :: Handle -> IO [String]
readLines fileHandle = do
	eof <- hIsEOF fileHandle
	if eof then return []
	else do
		line <- hGetLine fileHandle
		rest <- readLines fileHandle
		return (line:rest)
myreadFile :: String -> IO [String] 
myreadFile name = do
	fileHandle <- openFile name ReadMode
	readLines fileHandle

getF :: IO()
--getF = readFile filename >>= (\str -> return str) 
getF = do
	str <- readFile filename
	putStrLn str
-}
text = "The head bloomed     in Decemeber \n as the    carnival    season   kicked into    gear.\nNearly helpless with sun and glare, I avoided Rio's brilliant \nsidewalks \nand glittering breaches,\npanting in dark  corners  and waiting out the inverted southern \n summer."

textFormat = splitWords text			-- text文本转化为[Word]

-- 下面的函数处理和上面的String format没有太大的关系
blank = ['\t', ' '] 
dropBlank :: String -> String
dropBlank [] = []
dropBlank (x:xs) 
	| elem x blank = dropBlank xs
	| otherwise	   = x:xs

-- 统计　字母数　单词数　行数
wc :: String -> (Int, Int, Int)
wc str = case str of
	[]		-> (0, 0, 0)
	(x:xs)	-> 
		if elem x whitespace then
			let (m,n,k) = wc (dropBlank xs) --　这一句执行删除空白和\t，不能删除\n需要统计行数
			in
			if x == '\n' then (m, n + 1, k + 1)
			else (m, n + 1, k)
		else
			let (m,n,k) = wc xs
			in
			(m + 1, n, k)  --默认非whitespace就是字母,当然也可以做一个判定
-- 判断回文字符
isPlain :: String -> Bool
isPlain str = case str of
	[]		-> True
	(x:xs)	-> 
		if (isAlphaNum m) && (isAlphaNum n) then
			if m == n then isPlain (init xs)  --把最后一个字符去掉
			else False	
		else if not (isAlphaNum m) then isPlain xs -- 把第一个字符去掉
			 else isPlain (init (x:xs))  -- 把最后一个字符去掉
		where
			m = (toUpper x)
			n = (toUpper (last xs))

range  = 20
plain = "hell eh"
-- unit test

-- for isPlain test
testIsPlain :: Bool
testIsPlain = isPlain plain
-- for wc test
testWc :: (Int, Int, Int)
testWc = wc text

--for wc format　test
testWcFormat :: (Int, Int, Int)
testWcFormat = wc (stringFormat text)
-- 这两个wc计数　计行得到的结果不一样，因为wc里面其实是有bug的
-- for stringFormat test
testStringFormat :: IO()
testStringFormat = putStr (stringFormat text)

-- for getLine test   这个函数在Prelude里面有，所以需要屏蔽一下
testGetLine :: Line
testGetLine = getLine range textFormat

-- fro dropLine test
testDropLine :: [Word]
testDropLine = dropLine range textFormat


-- for splitWord test
testSplitWords :: [Word]
testSplitWords = splitWords text

-- for dropSpace test
testDropSpace :: Int -> String
testDropSpace n
	| n == 1 = dropSpace str1
	| n == 2 = dropSpace str2
	| otherwise = error "请输入参数1或者2"
-- for dropWord test
testDropWord :: Int -> String
testDropWord n
	| n == 1 = dropWord str1
	| n == 2 = dropWord str2
	| otherwise  = error "请输入参数1或者2"
-- for getWord test
str1 = " boo"
str2 = "cat hat"
testGetWord :: Int -> String
testGetWord n
	| n == 1 = getWord str1
	| n == 2 = getWord str2
	| otherwise = error "请输入参数1或者2"
