# Write your MySQL query statement below
-- sorted by id in asen
select author_id as id  from Views as v 
where v.author_id = v.viewer_id
group by author_id
order by author_id; 