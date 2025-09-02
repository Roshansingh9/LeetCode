# Write your MySQL query statement below
select e1.name
from Employee as e1
join Employee as e2
where (e2.managerId=e1.id)
group by e1.name,e1.id
having count(e1.id)>=5;