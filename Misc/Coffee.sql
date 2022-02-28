SELECT M.MenuName,S.ItemName
FROM Menu M,Recipe R,Stock S
WHERE M.MenuID = R.MenuID and R.StockID = S.StockID

SELECT MenuName
FROM (
    SELECT MenuName,Count(*) AS MenuCount
    FROM OrderList O,Menu M
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
)

--! Merge ------------------- 

SELECT M.MenuName,S.ItemName
FROM Menu M,Recipe R,Stock S
WHERE M.MenuID = R.MenuID and R.StockID = S.StockID and MenuName IN (
    SELECT MenuName
    FROM (
        SELECT MenuName,Count(*) AS MenuCount
        FROM OrderList O,Menu M
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
    )
)

-- 7
CREATE TABLE OrderList (
    CustOrderID int NOT NULL 
    MenuID int NOT NULL 
    Quantity int NOT NULL
    CONSTRAINT FK_CustOrderID FOREIGN KEY (CustOrderID) REFERENCES CustomerOrder(CustOrderID)
    CONSTRAINT FK_MenuID FOREIGN KEY (MenuID) REFERENCES Menu(MenuID)
)

-- 8
CREATE TABLE Payment (
    PaymentID int PRIMARY KEY
    StockOrderID int NOT NULL 
    PaymentDate DATE NOT NULL
    Amount int NOT NULL
    Note VARCHAR(50)
    CONSTRAINT FK_StockOrderID FOREIGN KEY (StockOrderID) REFERENCES StockOrder(StockOrderID)
)

-- 9
CREATE TABLE Income (
    IncomeID int PRIMARY KEY
    CustOrderID int NOT NULL 
    IncomeDate DATE NOT NULL
    Amount FLOAT(2) NOT NULL
    Note VARCHAR(50)
    CONSTRAINT FK_CustOrderID FOREIGN KEY (CustOrderID) REFERENCES CustomerOrder(CustOrderID)
)

---------------------------------------

SELECT SupplierID,Sum(Price) AS TotalPayment
FROM StockOrder
WHERE Price IN (
    SELECT Min(TotalPrice) AS MinPrice
    FROM (
        SELECT Sum(Price) AS TotalPrice
        FROM StockOrder
        GROUP BY SupplierID
    )
)
GROUP BY O.SupplierID

SELECT MIN(Price)
FROM (
SELECT Sum(Price)
FROM StockOrder
)

-----------------------------------------

SELECT StockID,Sum(Quantity)
FROM StockOrderQuantity
WHERE 
GROUP BY StockID

SELECT Max(TQ)
FROM (
SELECT Sum(Quantity) AS TQ
FROM StockOrderQuantity
GROUP BY StockID
)



SELECT FirstName
FROM (SELECT FirstName,Count(*) AS WorkCount
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