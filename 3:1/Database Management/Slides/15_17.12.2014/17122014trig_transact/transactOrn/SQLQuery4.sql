use myTestDB
go
Create Proc TranTest1
AS BEGIN TRAN 
INSERT INTO [t1]([id], [t1_value]) VALUES ('8', '8') 
UPDATE t1 SET id = '8' WHERE t1_value = '22' 
COMMIT TRAN 
GO 