select distinct a.product_id, coalesce(b.new_price,10) as price
from Products a left join
                    (select product_id, rank() over(partition by product_id order by change_date desc)
                        as xrank, new_price
                        from Products 
                        where change_date <= "2019-08-16"
                   ) b
        on a.product_id = b.product_id and b.xrank = 1 
        order by 2 desc;
                    