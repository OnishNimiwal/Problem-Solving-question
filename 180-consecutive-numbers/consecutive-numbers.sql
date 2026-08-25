# Write your MySQL query statement below
select distinct log1.num as ConsecutiveNums
from Logs as log1,Logs as log2,Logs as log3
where log1.id+1=log2.id and
    log2.id+1=log3.id and
    log1.num=log2.num and
    log2.num=log3.num;