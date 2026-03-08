UPDATE chitiet
JOIN sudung ON chitiet.DONGIA=sudung.DONGIA
SET THANHTIEN=SOKW*sudung.DONGIA;

