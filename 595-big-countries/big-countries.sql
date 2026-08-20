# Write your MySQL query statement below
-- name population and area
-- big is area>=3000000 or population>=25000000
select name,population,area from World
where area>=3000000 or population>=25000000; 