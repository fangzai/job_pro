{--------------------------------------------------------------
 - by ht, 2015/12/16
 - 处理有关超市market的相关问题
 --------------------------------------------------------------}

---------------
-- 定义数据结构
---------------
type Name		= String
type Price		= Int
type BarCode	= Int
type Database	= [(BarCode, Name, Price)]  -- 数组库由若干元组组成
codeIndex :: Database
codeIndex = [(4179, "Fish Fingers", 121), (5643, "Nappies", 1010), (3814, "Orange Jelly", 56),(1111, "Hula Hoops", 21), (1112, "Hula hoops(Giant)", 133), (1234, "Dry Sherry, 1lt", 540)]

type TillType	= [BarCode]  --定义条形码串
type BillType	= [(Name, Price)]

-----------
-- 函数定义
-----------
locateBarCode :: BarCode -> [(Name, Price)]  -- 先查找单个条形码
locateBarCode findBarCode = [(name, price) |(barCode, name, price) <- codeIndex, barCode == findBarCode] 
catBarCode :: BillType -> (Name, Price)
catBarCode billList 
	| length billList == 0   = ("Unknown Item", 0)
	| otherwise				 = billList !! 0

makeBill :: TillType -> BillType	-- 将条码转换称实际的商品名字和价格二元组
--makeBill till = [(locateBarCode barCode)!!0 | barCode <- till, length (locateBarCode barCode) > 0]
makeBill till = [catBarCode (locateBarCode barCode) | barCode <- till]

formatPence :: Price -> String
formatPence m = show ((fromIntegral m)/100.0)
formatLine :: (Name, Price) -> String
formatLine (name, price) = (show name) ++ "\t" ++ (formatPence price) ++ "\n"
formatBill :: BillType -> String	-- 将实际二元组格式化为账单
formatBill billList = concat [formatLine bill | bill <- billList]

produceBill :: TillType -> String	-- 上面两个函数的组合
produceBill till = formatBill (makeBill till)

lineLength :: Int					-- 定义账单的长度
lineLength = 30


------------
-- unit test
------------
barCodeList = [4178, 5643]
testMakeBill :: [(Name,Price)]
testMakeBill = makeBill barCodeList

billList = [("Fish Fingers",121),("Nappies",1010)] 
testFormatBill :: IO()
testFormatBill = putStr (formatBill billList)

-- for produceBill test
testProduceBill :: IO()
testProduceBill = putStr (produceBill barCodeList)
