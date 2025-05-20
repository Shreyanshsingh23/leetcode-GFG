# Write your MySQL query statement below
SELECT 
    case 
        WHEN id%2 = 0 THEN id-1
        WHEN (id%2 = 1 and id != (select max(id) FROM Seat)) THEN id+1
        ELSE id
        end AS id, student FROM Seat
        ORDER BY id;