use myTestDB
go
CREATE TRIGGER trg_UpdateShoppingListFood
ON dbo.ShoppingListFood
AFTER INSERT, UPDATE
AS
    UPDATE dbo.ShoppingList
    SET LastModifiedDate = GETDATE()
    WHERE ShopListID IN (SELECT DISTINCT ShopListID FROM Inserted)

-- Inserted tablosundan id'leri al get date ile ShoppingListFood i güncelle