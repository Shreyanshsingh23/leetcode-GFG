select 
a.employee_id, a.name, count(b.employee_id) as reports_count, round(avg(b.age),0) as average_age 
from Employees a join Employees b
on a.employee_id = b.reports_to
group by a.employee_id
order by a.employee_id;