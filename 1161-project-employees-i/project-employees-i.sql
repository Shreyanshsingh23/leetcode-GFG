# Write your MySQL query statement below
SELECT project_id, round(avg(experience_years),2) as average_years from  Project left join Employee ON Project.employee_id = Employee.employee_id
Group By project_id ;