/* ORA-REPORT-DEMO.SQL			*/
/* Sample Report in SQL PLUS 		*/
/* List products with total costs 	*/
/* Ordered by vendor and product	*/
/* with subtotals by vendor		*/


set headsep |		

ttitle 'Products by Vendor|by Good Student'	
btitle 'SaleCo'			
	
column V_CODE heading 'Vendor|Code' format 9999999
column P_CODE heading 'Product|Code' format a10
column P_DESCRIPT heading 'Description' format a20 truncated 
column P_QOH heading 'Qty|on Hand' format 9999
column P_PRICE heading 'Price' format $9,990.99
column Cost format $9,990.99

break on V_CODE skip 2    							
compute sum of Cost on V_CODE			

set pagesize 55
set newpage 0					

select v_code, p_code, p_descript, P_QOH, p_price, P_QOH*p_price as Cost
from product
order by v_code, p_code;

clear breaks
clear columns
clear computes
clear buffer
clear sql
