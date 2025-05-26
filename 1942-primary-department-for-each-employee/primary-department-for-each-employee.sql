select employee_id, department_id
from Employee 
where primary_flag = "Y"
or (employee_id, department_id) in 
                        (
                            select employee_id, department_id
                            from Employee
                            group by employee_id
                            having count(department_id) = 1
                        )

