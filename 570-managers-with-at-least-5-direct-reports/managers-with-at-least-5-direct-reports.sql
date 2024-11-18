# Write your MySQL query statement below
select s.name from Employee as s JOIN Employee as t on s.id = t.managerId group by s.id having count(*)>=5;