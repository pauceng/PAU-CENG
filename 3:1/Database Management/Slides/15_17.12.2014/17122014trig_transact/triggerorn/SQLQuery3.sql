create trigger update_t2 on t1
for update
as
begin
 set nocount on
 
 declare @id int, @t1_value varchar(50)
 
 select @id = id, @t1_value = t1_value from inserted

 update t2
 set t2_value = @t1_value
 where id = @id
 
end
go
update t1
set t1_value = cast(id as varchar(50))
go

--AÇIKLAMALAR
 --inserted ve deleted diye 
 --iki tane geçici tablo oluþturur.