USE myTestDB
SELECT 'Before BEGIN TRAN main', @@TRANCOUNT
   -- The value of @@TRANCOUNT is 0

BEGIN TRAN main
    SELECT 'After BEGIN TRAN main', @@TRANCOUNT
   -- The value of @@TRANCOUNT is 1
    DELETE t1
    SAVE TRAN t1deleted  -- Mark a save point
    SELECT 'After SAVE TRAN sales', @@TRANCOUNT
   -- The value of @@TRANCOUNT is still 1

    BEGIN TRAN nested
        SELECT 'After BEGIN TRAN nested', @@TRANCOUNT
        -- The value of @@TRANCOUNT is 2
        DELETE t2
        SAVE TRAN t2deleted  -- Mark a save point
        SELECT 'After SAVE TRAN t2deleted', @@TRANCOUNT
        -- The value of @@TRANCOUNT is still 2
    ROLLBACK TRAN t1deleted

    SELECT 'After ROLLBACK TRAN t1deleted', @@TRANCOUNT
     -- The value of @@TRANCOUNT is still 2

    SELECT *  FROM t2

IF (@@TRANCOUNT > 0) BEGIN
    ROLLBACK TRAN
    SELECT 'AFTER ROLLBACK TRAN', @@TRANCOUNT
    -- The value of @@TRANCOUNT is 0 because 
    -- ROLLBACK TRAN always rolls back all transactions and sets @@TRANCOUNT 
    -- to 0.
END
    
SELECT * FROM t2