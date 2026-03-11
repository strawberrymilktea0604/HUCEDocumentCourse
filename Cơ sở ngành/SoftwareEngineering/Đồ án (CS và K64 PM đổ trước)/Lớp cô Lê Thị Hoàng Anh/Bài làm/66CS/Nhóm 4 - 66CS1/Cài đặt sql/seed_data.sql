-- !!! REQUIRE: Run all line in this file one shot!
BEGIN TRANSACTION
BEGIN TRY 
DECLARE @AdminId uniqueidentifier = NEWID()
DECLARE @vinhhdId uniqueidentifier = NEWID()
DECLARE @hoangnmId uniqueidentifier = NEWID()
DECLARE @huyenntId uniqueidentifier = NEWID()
INSERT INTO Users VALUES
(@AdminId, N'Admin', 'admin', 'admin@123', 1,1, default, null),
(@vinhhdId, N'Hoang Dinh Vinh', 'vinhhd', 'DinhVinh123', 1,1, 2023-9-1, null),
(@hoangnmId, N'Nguyen Minh Hoang', 'hoangnm', 'MinhHo@ng234', 2, 1, 2023-10-1, null),
(@huyenntId, N'Nguyen Thu Huyen', 'huyennt', 'Huyenmun2003', 2, 1, 2023-10-2, null)

DECLARE @CoffeeId uniqueidentifier = NEWID()
DECLARE @TeaId uniqueidentifier = NEWID()
DECLARE @JuiceId uniqueidentifier = NEWID()
DECLARE @BookId uniqueidentifier = NEWID()
INSERT INTO Categories VALUES
(@CoffeeId, 'Coffee', 1),
(@TeaId, 'Tea', 1),
(@JuiceId, 'Juice', 1),
(@BookId, 'Book', 2)


INSERT INTO Books VALUES
(default, N'Khung cua hep', N'Andre Gide', N'H1', 2023-10-01, 2023-11-01, @BookId),
(default, N'Mystery at the Cafe', N'John Smith', N'H2', 2023-10-01, 2023-11-01, @BookId),
(default, N'The Art of Espresso', N'Sophia Miller', N'H2', 2023-10-01, 2023-11-01, @BookId),
(default, N'Ong gia va bien ca', N'Ernest Hemingway', N'H3', 2023-10-01, 2023-11-01, @BookId),
(default, N'Love Brews', N'Emma Wilson', N'H2', 2023-10-01, 2023-11-01, @BookId),
(default, N'Ten toi la do', N'Mikhail Solokhov', N'H1', 2023-10-01, 2023-11-01, @BookId),
(default, N'Cay cam ngot cua toi', N'Jose Mauro', N'H3', 2023-10-01, 2023-11-01, @BookId),
(default, N'Chet o Venice', N'Thomas Mann', N'H3', 2023-10-01, 2023-11-01, @BookId),
(default, N'Tup lleu bac Tom', N'Harriet Beecher Stowe', N'H3', 2023-10-01, 2023-11-01, @BookId),
(default, N'Chuyen lang', N'Pham Quang Long', N'H3', 2023-10-01, 2023-11-01, @BookId)

DECLARE @CafeDenId uniqueidentifier = NEWID()
DECLARE @CafeNauId uniqueidentifier = NEWID()
DECLARE @BacXiuId uniqueidentifier = NEWID()
DECLARE @LatteId uniqueidentifier = NEWID()
DECLARE @VietQuatMatOngId uniqueidentifier = NEWID()
DECLARE @ChanhTuyetId uniqueidentifier = NEWID()
INSERT INTO Products VALUES
(@CafeDenId, N'Cafe den', null, 0, 2023-10-01, null, @CoffeeId),
(@CafeNauId, N'Cafe nau', null, 0, 2023-10-01, null, @CoffeeId),
(@BacXiuId, N'Bac xiu', null, 0, 2023-10-01, null, @CoffeeId),
(@LatteId, N'Latte', null, 0, 2023-10-01, null, @TeaId),
(@VietQuatMatOngId, N'Viet quat mat ong', null, 0, 2023-10-01, null, @TeaId),
(@ChanhTuyetId, N'Chanh tuyet', null, 0, 2023-10-01, null, @JuiceId)

DECLARE @prdProperty1Id uniqueidentifier = NEWID()
DECLARE @prdProperty2Id uniqueidentifier = NEWID()
DECLARE @prdProperty3Id uniqueidentifier = NEWID()
DECLARE @prdProperty4Id uniqueidentifier = NEWID()
DECLARE @prdProperty5Id uniqueidentifier = NEWID()
DECLARE @prdProperty6Id uniqueidentifier = NEWID()
DECLARE @prdProperty7Id uniqueidentifier = NEWID()
INSERT INTO Properties VALUES
(@prdProperty1Id, N'M', N'Coc', 20000, @CafeDenId),
(@prdProperty2Id, N'M', N'Coc', 25000, @CafeNauId),
(@prdProperty3Id, N'M', N'Coc', 30000, @BacXiuId), 
(@prdProperty4Id, N'M', N'Coc', 50000, @LatteId), 
(@prdProperty5Id, N'L', N'Coc', 40000, @LatteId), 
(@prdProperty6Id, N'M', N'Coc', 50000, @VietQuatMatOngId), 
(@prdProperty7Id, N'M', N'Coc', 25000, @ChanhTuyetId)

INSERT INTO Images VALUES
(default, N'cf_den1.jpg', '/images/', 1, @CafeDenId),
(default, N'cf_den2.jpg', '/images/', 2, @CafeDenId),
(default, N'cf_nau.jpeg', '/images/', 1, @CafeNauId),
(default, N'bx.png', '/images/', 1, @BacXiuId),
(default, N'1.png', '/images/', 1, @LatteId),
(default, N'khabanh.png', '/images/', 1, @VietQuatMatOngId),
(default, N'chanhtuyet.jpeg', '/images/', 1, @ChanhTuyetId),
(default, N'chanhtuyetcancanh.jpeg', '/images/', 2, @ChanhTuyetId)

DECLARE @GRANDOPENINGId uniqueidentifier = NEWID()
DECLARE @COMEWITHFRIENDId uniqueidentifier = NEWID()
INSERT INTO Promotions VALUES
(@GRANDOPENINGId, 'GRANDOPENING', N'Khai Truong', 0.15, '2023-10-01','2023-11-01',default,null),
(@COMEWITHFRIENDId, 'COMEWITHFRIEND', N'Di cung ban', 0.10, '2023-10-01',null,default,null)

DECLARE @Order1Id uniqueidentifier = NEWID()
DECLARE @Order2Id uniqueidentifier = NEWID()
DECLARE @Order3Id uniqueidentifier = NEWID()
DECLARE @Order4Id uniqueidentifier = NEWID()
INSERT INTO Orders VALUES
(@Order1Id, N'Table 1', '2', '2023-10-01',null,@GRANDOPENINGId),
(@Order2Id, N'Table 2', '1', '2023-10-01',null,@GRANDOPENINGId),
(@Order3Id, N'Takeout', '1', '2023-10-01',null,@GRANDOPENINGId),
(@Order4Id, N'Table 3', '2', '2023-11-02',null,@COMEWITHFRIENDId)

INSERT INTO OrderItems VALUES
(@Order1Id, @CafeDenId, @prdProperty1Id, 2), 
(@Order1Id, @CafeNauId, @prdProperty2Id, 3),
(@Order3Id, @LatteId, @prdProperty4Id, 2), 
(@Order4Id, @VietQuatMatOngId, @prdProperty6Id, 3),
(@Order4Id, @ChanhTuyetId, @prdProperty7Id, 2)

COMMIT
END TRY
BEGIN CATCH 
	SELECT
		ERROR_NUMBER() AS ErrorNumber,
		ERROR_STATE() AS ErrorState,
		ERROR_SEVERITY() AS ErrorSeverity,
		ERROR_PROCEDURE() AS ErrorProcedure,
		ERROR_LINE() AS ErrorLine,
		ERROR_MESSAGE() AS ErrorMessage;
		ROLLBACK
END CATCH