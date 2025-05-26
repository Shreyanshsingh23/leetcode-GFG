select distinct a.num as ConsecutiveNums
from Logs a join Logs b
on a.num = b.num and a.id + 1 = b.id
join Logs c 
on a.num = c.num and a.id + 2 = c.id;