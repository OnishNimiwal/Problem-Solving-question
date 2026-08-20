# Write your MySQL query statement below
-- names select referee_id!=2 and referee_id is null
select name from Customer
where referee_id <> 2 or referee_id is null;