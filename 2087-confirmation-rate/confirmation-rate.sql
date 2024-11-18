# Write your MySQL query statement below
select s.user_id,Round(count(CASE WHEN action = "confirmed" THEN 1 END)/count(*),2) as confirmation_rate from Signups as s left join Confirmations as c on s.user_id=c.user_id group by s.user_id;