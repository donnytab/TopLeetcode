解题思路
对trips表和users表连接，连接条件是行程对应的乘客非禁止且司机非禁止
筛选订单日期在目标日期之间
用日期进行分组
分别统计所有订单数和被取消的订单数，其中取消订单数用一个bool条件来得到0或1，再用avg求均值
对订单取消率保留两位小数，对输出列名改名

# Write your MySQL query statement below

SELECT
    request_at as 'Day', round(avg(Status!='completed'), 2) as 'Cancellation Rate'
FROM 
    trips t JOIN users u1 ON (t.client_id = u1.users_id AND u1.banned = 'No')
    JOIN users u2 ON (t.driver_id = u2.users_id AND u2.banned = 'No')
WHERE	
    request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY 
    request_at
