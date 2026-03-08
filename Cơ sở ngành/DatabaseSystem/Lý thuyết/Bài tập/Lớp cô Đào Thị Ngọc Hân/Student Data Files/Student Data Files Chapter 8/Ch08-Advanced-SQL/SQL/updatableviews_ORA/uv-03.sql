-- Script Filename: UV-03.SQL
-- PURPOSE:
-- Queries the Oracle data dictionary to see what columns 
-- in the PSVUPD view are updatable. 
-- TO RUN:
-- At the SQL> prompt type: @D:\path\uv-03.sql
-- Where D: is the drive letter and path is the folder 
-- where the file resides.
-- Alternative you can copy and paste each command 
-- or the entire command sequence

SELECT COLUMN_NAME, UPDATABLE, INSERTABLE, DELETABLE 
FROM USER_UPDATABLE_COLUMNS
WHERE TABLE_NAME = 'PSVUPD';
