USE TestDB
GO

CREATE TABLE Sales(
 ID INT IDENTITY(1,1)
,ProductCode VARCHAR(20)
,Price FLOAT(53)
,DateTransaction DATETIME);