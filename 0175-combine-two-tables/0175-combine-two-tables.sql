# Write your MySQL query statement below
select p.firstName, p.lastName, a.city, a.state
from person p left JOIN 
address a ON a.personId = p.personId;