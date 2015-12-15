import Prelude

-- 定义类型
type Person = String 
type Book	= String 

-- 数据库每次借阅用下列元组表示
-- (Person, Book)
type DataBase = [(Person, Book)] 

exampleBase :: DataBase
exampleBase = [("Alice", "Tintin"), ("Anan", "Little Women"), ("Alice", "Asterix"), ("Rory", "Tintin")]

-- 考虑数据库上的函数
-- 给出一个读者，求该读者借阅的图书
books	     :: DataBase -> Person -> [Book]
-- 给出一本书求借阅此书的读者(一本书可能有多个拷贝)
borrowers    :: DataBase -> Book -> [Person]
-- 给出一本书，问次数是否被借出
borrowed     :: DataBase -> Book -> Bool
-- 给出一个读者，求该读者借出图书的数目
numBorrowed  :: DataBase -> Person -> Int


-- update database
makeLoan	 :: DataBase -> Person -> Book -> DataBase
returnLoan	 :: DataBase -> Person -> Book -> DataBase

-- 函数体　定义
books dBase findPerson =  [book | (person, book) <- dBase, person == findPerson]

borrowers dBase findBook = [person | (person, book) <- dBase, book == findBook]

borrowed dBase findBook = if length (borrowers dBase findBook) > 0 then True
						  else False
numBorrowed dBase findPerson = length (books dBase findPerson)

-- update database 

makeLoan dBase person book = [(person, book)] ++ dBase
returnLoan dBase person book = [pair | pair <- dBase, pair /= (person, book)]


-- unit test

-- 查询某人借了什么书
testBooks :: Int -> [Book]
testBooks n
		| n == 0  = books exampleBase "Alice"
		| n == 1  = books exampleBase "Rory"
		| n == 2  = books exampleBase "Wang"
		| otherwise = error "请输入n = 0, 1 or 2"

-- 查询某书被什么借了
testBorrowers :: Int -> [Person]
testBorrowers n
		|n == 0    = borrowers exampleBase "Little Women"
		|n == 1    = borrowers exampleBase "Tintin"
		|n == 2    = borrowers exampleBase "wang"
		| otherwise = error "请输入n = 0, 1 or 2"

-- 查询某些书是否被借了
testBorrowed :: [Book] -> [Bool]
testBorrowed bookList = [borrowed exampleBase book | book <- bookList]

bkList = ["Little Woman", "Tintin", "wang"]
testBed :: [Bool]
testBed = (testBorrowed bkList)

-- 查询某人借了几本书
testNumBorrowed :: [Person] -> [Int]
testNumBorrowed personList = [numBorrowed exampleBase person | person <- personList]
pnList = ["Alice", "Rory", "wang"]

testNBed :: [Int]
testNBed = (testNumBorrowed pnList)

-- update database 
pairList = ("wang", "Red and Black")
--pairList = ("Li Qian", "Fang")
testMakeLoan :: DataBase
testMakeLoan = makeLoan exampleBase (fst pairList) (snd pairList)

returnList = ("Alice", "Tintin")
-- returnList = ("Anan", "Little Women")
testReturnLoad :: DataBase
testReturnLoad = returnLoan exampleBase (fst returnList) (snd returnList)


