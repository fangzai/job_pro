{--------------------------------------------------------------------------
 - by ht, 2015/12/21
 - 关于函数复合　函数返回的高级应用
 --------------------------------------------------------------------------}
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


