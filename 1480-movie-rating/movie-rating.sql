# Write your MySQL query statement below
(select name as results
from MovieRating join users using(user_id)
group by name
order by count(*) desc , name
limit 1)
union all
(select title as results
from MovieRating join Movies using(movie_id)
where created_at between '2020-02-01' and '2020-02-29'
group by title
order by avg(rating) desc,title
limit 1);
