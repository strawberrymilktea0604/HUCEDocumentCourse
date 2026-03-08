CREATE OR REPLACE procedure analyze_tables as
ojn varchar2(100);
user_name varchar2(20);
dml_str VARCHAR2(200);
CURSOR c1 IS
SELECT table_name FROM user_tables WHERE   temporary <> 'Y';
BEGIN
select user into user_name from dual;
open c1;
loop
fetch  c1 into ojn;
dbms_output.put_line ('Now '|| ojn ||' is analyzing ');
exit when c1%NOTFOUND;
dml_str := 'begin  dbms_stats.gather_table_stats( '||''''||user_name||''''
||','|| ''''||ojn  ||'''' || ',null,1) ;end;';
dbms_output.put_line (dml_str);
execute immediate dml_str;
END LOOP;
END;
/

