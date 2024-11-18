# Write your MySQL query statement below
select v.id from weather as w join weather as v on datediff(v.recordDate,w.recordDate)=1 where v.temperature>w.temperature;