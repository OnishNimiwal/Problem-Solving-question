# Write your MySQL query statement below
-- limit of the bus 1000
-- return the last person fitted
-- for the cumulative sum
-- select sum(col) over(order by turn) as cumulative
select person_name from ( select person_name, turn, sum(weight) over(order by turn) as cumu
from Queue) q
where cumu<=1000
order by turn desc
limit 1;