SELECT W.ShiftID, Avg(R.Rating) AS AvgOfRating
FROM Review AS R, CustomerOrder AS C, Workshift AS W
WHERE (((R.CustOrderID)=C.CustOrderID) And ((C.ShiftID)=W.ShiftID))
GROUP BY W.ShiftID;

SELECT S.SupplierName,Sum(Price) AS TotalPayment
FROM StockOrder O,Supplier S
WHERE O.SupplierID = S.SupplierID and Price IN (
    SELECT Min(TotalPrice)
    FROM (
        SELECT Sum(Price) AS TotalPrice
        FROM StockOrder
        GROUP BY SupplierID
    )
)
GROUP BY S.SupplierName


SELECT M.MenuName
FROM Menu M,Recipe R,Stock S
WHERE M.MenuID = R.MenuID and R.StockID = S.StockID and S.ItemName='นม'
INTERSECT
SELECT M.MenuName
FROM Menu M,Recipe R,Stock S
WHERE M.MenuID = R.MenuID and R.StockID = S.StockID and S.ItemName='เมล็ดกาแฟ';


SELECT Sum(Amount) AS TotalIncome
FROM Income I


SELECT MenuName
FROM Membership AS MB, CustomerOrder AS C, OrderList AS O, Menu AS M
WHERE MB.MemberID = C.MemberID and C.CustOrderID = O.CustOrderID and O.MenuID = M.MenuID and C.MemberID IN (
    SELECT MemberID
    FROM Membership
    WHERE Point IN (
        SELECT MAX(Point) 
        FROM Membership
    )
) and O.Quantity IN (
        SELECT MAX(Quantity)
        FROM Membership MB,CustomerOrder C,OrderList O,Menu M
        WHERE MB.MemberID = C.MemberID and C.CustOrderID = O.CustOrderID and O.MenuID = M.MenuID and MB.Point IN (
        SELECT MAX(Point)
        FROM MemberShip
    )
);


SELECT DISTINCT Nickname
FROM Employee AS E, EmployeeShift AS S, Workshift AS W
WHERE E.EmployeeID = S.EmployeeID and S.ShiftID = W.ShiftID and W.Day = 'WED';


SELECT ItemName
FROM (
    SELECT S.ItemName,Sum(O.Quantity) AS TQ
    FROM StockOrderQuantity O,Stock S
    WHERE O.StockID = S.StockID
    GROUP BY S.ItemName
)
WHERE TQ IN (
        SELECT Max(TQ)
        FROM (
        SELECT Sum(Quantity) AS TQ
        FROM StockOrderQuantity
        GROUP BY StockID
    )
)


SELECT Period, COUNT(*) AS OrderCount
FROM Workshift AS W, CustomerOrder AS O
WHERE W.ShiftID = O.ShiftID
GROUP BY Period
HAVING COUNT(*) < 3;


SELECT FirstName
FROM (
    SELECT FirstName,Count(*) AS WorkCount
    FROM Employee E,EmployeeShift S
    WHERE E.EmployeeID = S.EmployeeID
    GROUP BY FirstName
)
WHERE WorkCount IN (
    SELECT Max(WorkCount)
    FROM (
        SELECT FirstName,Count(*) AS WorkCount
        FROM Employee E,EmployeeShift S
        WHERE E.EmployeeID = S.EmployeeID
        GROUP BY FirstName
    )
);


SELECT MenuName
FROM (
    SELECT MenuName, Count(*) AS MenuCount
    FROM OrderList AS O, Menu AS M
    WHERE M.MenuID = O.MenuID
    GROUP BY M.MenuName
)
WHERE MenuCount IN (     
    SELECT Min(MenuCount)     
    FROM (         
        SELECT Count(*) AS MenuCount         
        FROM OrderList O,Menu M         
        WHERE M.MenuID = O.MenuID         
        GROUP BY M.MenuName     
    ) 
);


SELECT MemberID, FirstName, LastName
FROM Membership AS M
WHERE NOT EXISTS (
    SELECT M.MemberID
    FROM CustomerOrder O
    WHERE M.MemberID = O.MemberID 
);

--TODO --------------------------------------------------------------------

--* 1 ---------------------------------------------------------------------
SELECT MenuName
FROM Membership AS MB, CustomerOrder AS C, OrderList AS O, Menu AS M
WHERE MB.MemberID = C.MemberID and C.CustOrderID = O.CustOrderID and O.MenuID = M.MenuID and C.MemberID IN (
    SELECT MemberID
    FROM Membership
    WHERE Point IN (
        SELECT MAX(Point)
        FROM Membership
    )
) and O.Quantity IN (
        SELECT MAX(Quantity)
        FROM Membership MB,CustomerOrder C,OrderList O,Menu M
        WHERE MB.MemberID = C.MemberID and C.CustOrderID = O.CustOrderID and O.MenuID = M.MenuID and MB.Point IN (
        SELECT MAX(Point)
        FROM MemberShip
    )
);

--* 2 ---------------------------------------------------------------------
SELECT W.ShiftID, Avg(R.Rating) AS AvgOfRating
FROM Review AS R, CustomerOrder AS C, Workshift AS W
WHERE (((R.CustOrderID)=C.CustOrderID) And ((C.ShiftID)=W.ShiftID))
GROUP BY W.ShiftID;

--* 3 ---------------------------------------------------------------------
SELECT ItemName
FROM (
    SELECT S.ItemName,Sum(O.Quantity) AS TQ
    FROM StockOrderQuantity O,Stock S
    WHERE O.StockID = S.StockID
    GROUP BY S.ItemName
)
WHERE TQ IN (
        SELECT Max(TQ)
        FROM (
        SELECT Sum(Quantity) AS TQ
        FROM StockOrderQuantity
        GROUP BY StockID
    )
)

--* 4 ---------------------------------------------------------------------
SELECT M.MenuName, S.ItemName, R.Quantity AS ItemQuantity, S.Quantity AS StockQuantity
FROM CustomerOrder AS CO, OrderList AS O, Menu AS M, Recipe AS R, Stock AS S
WHERE CO.CustOrderID = 1 AND CO.CustOrderID = O.CustOrderID AND O.MenuID = M.MenuID AND M.MenuID = R.MenuID AND R.StockID = S.StockID;