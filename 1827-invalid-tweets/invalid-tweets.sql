# Write your MySQL query statement below
-- to count the number of char in sql CHAR_LENGTH(col) if wanted
-- to return the number of rows count(*)
select tweet_id from 
Tweets where CHAR_LENGTH(content)>15;