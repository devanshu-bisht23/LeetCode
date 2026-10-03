# Write your MySQL query statement below
select name as Employee from
(
select e.id,e.name,e.salary,temp1.msal
from
(
    select salary as msal, id
    from employee
)temp1 Join employee e on 
e.managerId = temp1.id
)temp2
where salary>msal