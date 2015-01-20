use myTestDB
go
create table t1 (id int primary key, t1_value varchar(50))
insert into t1 select 1, '1'
insert into t1 select 2, '2'
insert into t1 select 3, '3'
create table t2 (id int primary key, t2_value varchar(50))
insert into t2 select 1, NULL
insert into t2 select 2, NULL
insert into t2 select 3, NULL