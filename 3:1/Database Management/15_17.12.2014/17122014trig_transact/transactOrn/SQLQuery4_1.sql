use myTestDB
go
Create Proc TranTest2
AS BEGIN TRAN 
INSERT INTO [t1]([id], [t1_value]) VALUES ('9', '9') 
IF @@ERROR <> 0 
	BEGIN 
		ROLLBACK TRAN 
		return 10
	END
UPDATE t1 SET id = '9' WHERE t1_value = '8' 
IF @@ERROR <> 0 
	BEGIN 
		ROLLBACK TRAN 
		return 11 
	END
COMMIT TRAN 