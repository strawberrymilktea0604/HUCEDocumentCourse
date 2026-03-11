/*
Project: Coffee Book Shop Management
Last Commit: #04 3:21AM 06/11/2023
*/

CREATE DATABASE cbs_management_project
USE cbs_management_project

SELECT * FROM sys.tables
SELECT * FROM sys.types
SELECT * FROM sys.procedures
SELECT * FROM sys.triggers

-- Migrations ===========================================================

/*
Role: Admin=1; Employee2
*/
CREATE TABLE Users (
	Id uniqueidentifier PRIMARY KEY default NEWID(),
	FullName nvarchar(max) not null,
	UserName varchar(256) not null,
	Password varchar(256) not null,
	Role int not null,
	IsActive bit not null default 1,
	CreatedAt datetime not null default CURRENT_TIMESTAMP,
	ModifiedAt datetime default CURRENT_TIMESTAMP,
)

/*
Type: Product=1; Book=2;
*/
CREATE TABLE Categories (
	Id uniqueidentifier PRIMARY KEY	default NEWID(),
	Name nvarchar(max) not null,
	Type int not null
)

CREATE TABLE Books (
	Id uniqueidentifier PRIMARY KEY default NEWID(),
	Name nvarchar(max) not null,
	Author nvarchar(max),
	Place nvarchar(max),
	CreatedAt datetime not null default CURRENT_TIMESTAMP,
	ModifiedAt datetime default CURRENT_TIMESTAMP,
	CategoryId uniqueidentifier FOREIGN KEY references Categories(Id)
)

/*
IsDeleted: False=0; True=1
*/
CREATE TABLE Products (
	Id uniqueidentifier PRIMARY KEY default NEWID(),
	Name nvarchar(max) not null,
	Description nvarchar(max),
	IsDeleted bit not null default 0,
	CreatedAt datetime not null default CURRENT_TIMESTAMP,
	ModifiedAt datetime default CURRENT_TIMESTAMP,
	CategoryId uniqueidentifier FOREIGN KEY references Categories(Id)
)

CREATE TABLE Properties (
	Id uniqueidentifier PRIMARY KEY default NEWID(),
	Size nvarchar(max) not null,
	Unit nvarchar(max) not null,
	Price int not null,
	ProductId uniqueidentifier not null FOREIGN KEY references Products(Id)
)

CREATE TABLE Images (
	Id uniqueidentifier PRIMARY KEY default NEWID(),
	FileName nvarchar(max) not null,
	Path varchar(max) not null,
	Position int not null,
	ProductId uniqueidentifier not null FOREIGN KEY references Products(Id)
)

CREATE TABLE Promotions (
	Id uniqueidentifier PRIMARY KEY default NEWID(),
	Code varchar(max) not null,
	Name nvarchar(max) not null,
	Discount float not null,
	StartTime datetime not null,
	EndTime datetime,
	CreatedAt datetime not null default CURRENT_TIMESTAMP,
	ModifiedAt datetime default CURRENT_TIMESTAMP,
)

/*
Status: Cancelled=0; Transaction=1, Success=2
*/
CREATE TABLE Orders (
	Id uniqueidentifier PRIMARY KEY default NEWID(),
	Note nvarchar(max),
	Status int not null,
	CreatedAt datetime not null default CURRENT_TIMESTAMP,
	ModifiedAt datetime default CURRENT_TIMESTAMP,
	PromotionId uniqueidentifier FOREIGN KEY references Promotions(Id)
)

CREATE TABLE OrderItems (
	OrderId uniqueidentifier not null,
	ProductId uniqueidentifier not null,
	ProductPropertyId uniqueidentifier not null,
	Quantity int not null,
	PRIMARY KEY (OrderId, ProductId),
	FOREIGN KEY (OrderId) references Orders(Id),
	FOREIGN KEY (ProductId) references Products(Id)
)

/*
Method: Cash=1; Banking=2; Card=3
*/
CREATE TABLE Payments (
	Id uniqueidentifier PRIMARY KEY default NEWID(),
	Method int not null,
	Total int not null,
	CreatedAt datetime not null default CURRENT_TIMESTAMP,
	CreatedBy uniqueidentifier not null FOREIGN KEY references Users(Id),
	OrderId uniqueidentifier not null FOREIGN KEY references Orders(Id)
)

-- Views ================================================================

-- Types ================================================================
CREATE TYPE ProductPropertyType AS TABLE (
	Size nvarchar(max) not null,
	Unit nvarchar(max) not null,
	Price int not null
)

CREATE TYPE ProductImageType AS TABLE (
	FileName nvarchar(max) not null,
	Path varchar(max) not null,
	Position int not null
)

CREATE TYPE OrderItemType AS TABLE (
	ProductId varchar(36) not null,
	ProductPropertyId varchar(36) not null,
	Quantity int not null
)

-- Triggers ===============================================================

-- Store Procedures =======================================================
/*
Account
*/
GO
-- Tạo tài khoản nhân viên mới
CREATE PROCEDURE AddUserProcedure (
	@FullName nvarchar(max),
	@UserName varchar(256),
	@Password varchar(256),
	@Role int
)
AS
BEGIN
	IF EXISTS (SELECT * FROM Users WHERE UserName = LTRIM(RTRIM(@UserName)))
		BEGIN
			RAISERROR ('Username already exists', 16, 1); 
			RETURN
		END
	INSERT INTO Users (Id, FullName, UserName, Password, Role, CreatedAt, ModifiedAt, IsActive)
	VALUES (default, @FullName, @UserName, @Password, @Role, default, null, default)
END

GO
-- Đăng nhập
CREATE PROCEDURE SignInProcedure(
	@UserName varchar(256),
	@Password varchar(256)
)
AS
BEGIN
	DECLARE @Id uniqueidentifier
	SET @Id = (SELECT Users.Id FROM Users WHERE UserName =@UserName AND Password = @Password AND IsActive = 1)
	IF @Id IS NULL
		BEGIN
			RAISERROR ('Username or password is incorrect', 16, 1); 
			RETURN
		END
	SELECT * FROM Users WHERE Users.Id = @Id
END

-- Cập nhật thông tin: Tương tự
/*
Category
*/
GO
-- Tạo thể loại mới
CREATE PROCEDURE AddCategoryProcedure(
	@Name nvarchar(max), 
	@Type int
)
AS
BEGIN
	INSERT INTO Categories (Id, Name, Type)
	VALUES (default, @Name, @Type)
END

/*
Book
*/
GO
-- Tạo sách mới
CREATE PROCEDURE AddBookProcedure(
	@Name nvarchar(max),
	@Author nvarchar(max) = null,
	@Place nvarchar(max) = null,
	@CategoryId uniqueidentifier = null
)
AS
BEGIN
	INSERT INTO Books (Id, Name, Author, Place, CreatedAt, ModifiedAt, CategoryId)
	VALUES (default, @Name, @Author, @Place, default, null, @CategoryId)
END

/*
Product
*/
GO
-- Tạo sản phẩm mới
CREATE PROCEDURE AddProductProcedure (
	@Name nvarchar(max),
	@Description nvarchar(max) = null,
	@CategoryId uniqueidentifier = null,
	@ListProperty ProductPropertyType READONLY,
	@ListProductImage ProductImageType READONLY
)
AS
BEGIN
	BEGIN TRANSACTION
	BEGIN TRY
		DECLARE @ProductId uniqueidentifier = NEWID()
		-- Thêm sản phẩm
		INSERT INTO Products (Id, Name, Description, IsDeleted, CreatedAt, ModifiedAt, CategoryId)
		VALUES (@ProductId, @Name, @Description, default, default, null, @CategoryId)
		-- Thêm thuộc tính cho sản phẩm
		INSERT INTO Properties (Id, Size, Unit, Price, ProductId)
		SELECT NEWID(), Size, Unit, Price, @ProductId 
		FROM @ListProperty
		-- Thêm ảnh cho sản phẩm
		INSERT INTO Images (Id, FileName, Path, Position, ProductId)
		SELECT NEWID(), FileName, Path, Position, @ProductId 
		FROM @ListProductImage
		-- Commit
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
END

GO
-- Cập nhật sản phẩm
CREATE PROCEDURE UpdateProductProcedure (
	@ProductExistedId uniqueidentifier,
	@Name nvarchar(max),
	@Description nvarchar(max) = null,
	@CategoryId uniqueidentifier = null,
	@ListProperty ProductPropertyType READONLY,
	@ListProductImage ProductImageType READONLY
)
AS
BEGIN
	BEGIN TRANSACTION
	BEGIN TRY
		IF NOT EXISTS (SELECT 1 FROM Products WHERE Id = @ProductExistedId)
		BEGIN
			RAISERROR (N'Không tìm thấy sản phẩm', 16, 1)
			RETURN
		END
		-- Cập nhật sản phẩm
		UPDATE Products SET 
		Name = @Name,
		Description = @Description, 
		ModifiedAt = CURRENT_TIMESTAMP, 
		CategoryId = @CategoryId
		-- Cập nhật thuộc tính cho sản phẩm
		DELETE FROM Properties WHERE ProductId = @ProductExistedId
		INSERT INTO Properties (Id, Size, Unit, Price, ProductId)
		SELECT NEWID(), Size, Unit, Price, @ProductExistedId 
		FROM @ListProperty
		-- Cập nhật ảnh cho sản phẩm
		DELETE FROM Images WHERE ProductId = @ProductExistedId
		INSERT INTO Images (Id, FileName, Path, Position, ProductId)
		SELECT NEWID(), FileName, Path, Position, @ProductExistedId 
		FROM @ListProductImage
		-- Commit
		COMMIT
	END TRY
	BEGIN CATCH
		ROLLBACK
		SELECT
		ERROR_NUMBER() AS ErrorNumber,
		ERROR_STATE() AS ErrorState,
		ERROR_SEVERITY() AS ErrorSeverity,
		ERROR_PROCEDURE() AS ErrorProcedure,
		ERROR_LINE() AS ErrorLine,
		ERROR_MESSAGE() AS ErrorMessage;
	END CATCH
END

GO
-- Xóa sản phẩm
CREATE PROCEDURE DeleteProductProcedure (@ProductExistedId uniqueidentifier)
AS
BEGIN
	IF NOT EXISTS (SELECT 1 FROM Products WHERE Id = @ProductExistedId)
		BEGIN
			RAISERROR (N'Không tìm thấy sản phẩm', 16, 1)
			RETURN
		END
	-- Cập nhật Deleted = True
	UPDATE Products	SET IsDeleted = 1 WHERE Id = @ProductExistedId
END

/*
Promotion
*/
GO
-- Tạo mã khuyến mãi
CREATE PROCEDURE AddPromotionProcedure(
	@Code varchar(max),
	@Name nvarchar(max),
	@Discount float,
	@StartTime datetime,
	@EndTime datetime = null
)
AS
BEGIN
	INSERT INTO Promotions (ID, Code, Name, Discount, StartTime, EndTime, CreatedAt, ModifiedAt)
	VALUES (default, @Code, @Name, @Discount, @StartTime, @EndTime, default, null)
END

-- Cập nhật & Xóa mã khuyến mãi: Hệ thống không cho phép cập nhật & xóa

/*
Order
*/
GO
-- Thêm đơn hàng
CREATE PROCEDURE AddOrderProcedure (
	@ListOrderItem OrderItemType READONLY,
	@Note nvarchar(max) = null,
	@PromotionId uniqueidentifier = null
)
AS
BEGIN
	BEGIN TRANSACTION
	BEGIN TRY
		DECLARE @OrderId uniqueidentifier = NEWID()
		-- Tạo đơn hàng với trạng thái đang giao dịch Transaction=1
		INSERT INTO Orders (Id, Note, Status, CreatedAt, ModifiedAt, PromotionId)
		VALUES (@OrderId, @Note, 1, default, null, @PromotionId)
		-- Thêm chi tiết đơn hàng
		INSERT INTO OrderItems (OrderId, ProductId, ProductPropertyId, Quantity)
		SELECT @OrderId, CAST(ProductId AS uniqueidentifier), CAST(ProductPropertyId AS uniqueidentifier), Quantity 
		FROM @ListOrderItem
		-- Commit
		COMMIT
	END TRY
	BEGIN CATCH
		ROLLBACK
		SELECT
		ERROR_NUMBER() AS ErrorNumber,
		ERROR_STATE() AS ErrorState,
		ERROR_SEVERITY() AS ErrorSeverity,
		ERROR_PROCEDURE() AS ErrorProcedure,
		ERROR_LINE() AS ErrorLine,
		ERROR_MESSAGE() AS ErrorMessage;
	END CATCH
END

GO
-- Cập nhật đơn hàng
CREATE PROCEDURE UpdateOrderProcedure (
	@OrderExistedId uniqueidentifier,
	@ListOrderItem OrderItemType READONLY,
	@Note nvarchar(max) = null,
	@Status int,
	@PromotionId uniqueidentifier = null
)
AS
BEGIN
	BEGIN TRANSACTION
	BEGIN TRY
		IF NOT EXISTS (SELECT 1 FROM Orders WHERE Id = @OrderExistedId)
		BEGIN
			RAISERROR (N'Không tìm thấy đơn hàng', 16, 1)
			RETURN
		END
		-- Cập nhật đơn hàng
		UPDATE Orders SET 
		Note = @Note, 
		Status = Status, 
		ModifiedAt = CURRENT_TIMESTAMP, 
		PromotionId = @PromotionId
		-- Cập nhật chi tiết
		DELETE FROM OrderItems WHERE OrderId = @OrderExistedId
		INSERT INTO OrderItems (OrderId, ProductId, ProductPropertyId, Quantity)
		SELECT @OrderExistedId, CAST(ProductId AS uniqueidentifier), CAST(ProductPropertyId AS uniqueidentifier), Quantity 
		FROM @ListOrderItem
		-- Commit
		COMMIT
	END TRY
	BEGIN CATCH
		ROLLBACK
		SELECT
		ERROR_NUMBER() AS ErrorNumber,
		ERROR_STATE() AS ErrorState,
		ERROR_SEVERITY() AS ErrorSeverity,
		ERROR_PROCEDURE() AS ErrorProcedure,
		ERROR_LINE() AS ErrorLine,
		ERROR_MESSAGE() AS ErrorMessage;
	END CATCH
END

GO
-- Xóa đơn hàng đồng thời Xóa hóa đơn nếu có
CREATE PROCEDURE DelelteOrderProcedure(
	@OrderExistedId uniqueidentifier
)
AS
BEGIN
	BEGIN TRANSACTION
	BEGIN TRY
		IF NOT EXISTS (SELECT 1 FROM Products WHERE Id = @OrderExistedId)
		BEGIN
			RAISERROR (N'Không tìm thấy đơn hàng', 16, 1)
			RETURN
		END
		-- Xóa hóa đơn
		DELETE FROM Payments WHERE OrderId = @OrderExistedId
		-- Xóa chi tiết đơn hàng
		DELETE FROM OrderItems WHERE OrderId = @OrderExistedId
		-- Xóa đơn hàng
		DELETE FROM Orders WHERE Id = @OrderExistedId
		-- Commit
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
END

/*
Payment
*/
GO
-- Tạo hóa đơn cho đơn hàng
CREATE PROCEDURE AddPaymentProcedure (
	@OrderId uniqueidentifier,
	@PaymentMethod int,
	@UserId uniqueidentifier
)
AS
BEGIN
	BEGIN TRANSACTION
	BEGIN TRY
		IF NOT EXISTS (SELECT 1 FROM Orders WHERE Id = @OrderId)
			BEGIN
				RAISERROR (N'Không tìm thấy đơn hàng', 16, 1)
				RETURN
			END
		IF NOT EXISTS (SELECT 1 FROM Users WHERE Id = @UserId)
			BEGIN
				RAISERROR (N'Không tìm thấy nhân viên', 16, 1)
				RETURN
			END
		-- Tính tổng đơn hàng
		DECLARE @Total int
		DECLARE @HasDiscountAmount float -- Check lượng khuyến mãi được áp dụng
		SET @Total = (
			SELECT SUM ((OrderItems.Quantity * Properties.Price))
			FROM Orders
			INNER JOIN OrderItems 
			ON Orders.Id = OrderItems.OrderId
			INNER JOIN Properties
			ON Properties.Id = OrderItems.ProductPropertyId
			INNER JOIN Promotions
			ON Orders.PromotionId = Promotions.Id
			WHERE Orders.Id = @OrderId
		)
		SET @HasDiscountAmount = (
			SELECT 
				CASE WHEN Promotions.EndTime IS NOT NULL OR Promotions.EndTime > CURRENT_TIMESTAMP 
					THEN Promotions.Discount
					ELSE 0 
				END
			FROM Orders
			INNER JOIN Promotions
			ON Orders.PromotionId = Promotions.Id
			WHERE Orders.Id = @OrderId
		)
		SET @Total = @Total * (1 - @HasDiscountAmount)
		-- Thêm hóa đơn
		INSERT INTO Payments (Id, Method, Total, CreatedAt, CreatedBy, OrderId)
		VALUES (default, @PaymentMethod, @Total, default, @UserId, @OrderId)
		-- Cập nhật trạng thái Success=2 cho đơn hàng
		UPDATE Orders SET Status = 2 WHERE Id = @OrderId
		-- Commit
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
END

-- Cập nhật hóa đơn
-- !! Pending: Hệ thống bảo toàn action giao dịch, chỉ xuất hóa đơn cho đơn hàng và lưu database
-- [] Explain: Chỉ có thể xóa hóa đơn từ xóa đơn hàng, cập nhật đơn hàng, và tạo hóa đơn mới


-- Functions =========================================================
/*
Book
*/
GO
-- Trả về danh sách Book:  @Limit số records trong 1 page, @Index của page khi phân trang
CREATE FUNCTION ListBookFunction (
    @BookName nvarchar(max),
    @Limit int,
    @Index int
)
RETURNS TABLE
AS
RETURN (
    SELECT Books.Id, Books.Name, Books.Author, Books.Place, Categories.Name AS CategoryName 
    FROM Books
    LEFT JOIN Categories ON Books.CategoryId = Categories.Id
    WHERE @BookName IS NULL OR Books.Name LIKE '%' + @BookName + '%'
    ORDER BY CreatedAt DESC
    OFFSET (@Index - 1) * @Limit ROWS
    FETCH NEXT @Limit ROWS ONLY
);

/*
Product
*/
GO
-- Trả về danh sách sản phẩm với filter, nếu @ProductName=null return all
CREATE FUNCTION ListProductFunction (
    @ProductName nvarchar(max)
)
RETURNS TABLE
AS
RETURN (
    SELECT 
		Products.Id, 
		Products.Name, 
		Products.Description, 
		Categories.Name AS CategoryName, 
		ROW_NUMBER() OVER (PARTITION BY Products.Id ORDER BY Products.CreatedAt DESC) AS VariantNumber,
		Properties.Size, 
		Properties.Unit, 
		Properties.Price, 
		Products.CreatedAt
	FROM Products
	LEFT JOIN Categories ON Products.CategoryId = Categories.Id
	LEFT JOIN Properties ON Properties.ProductId = Products.Id
	WHERE (@ProductName IS NULL OR @ProductName LIKE '%' + @ProductName + '%') AND Products.IsDeleted = 0
)

/*
Promotion
*/
GO
-- Tìm mã khuyến mại theo @Code
CREATE FUNCTION ListPromotionFunction (
	@Code varchar(max)
)
RETURNS TABLE
AS
RETURN (
		SELECT *
		FROM Promotions 
		WHERE @Code IS NULL OR Promotions.Code LIKE '%' + @Code + '%'
)

/*
Order
*/
GO
-- Danh sách đơn hàng tìm theo trạng thái, khoảng thời gian
CREATE FUNCTION ListOrderFunction (
	@Status int,
	@StartTime datetime,
	@EndTime datetime
)
RETURNS TABLE
AS RETURN(
	SELECT 
		OrderItems.OrderId,
		Orders.Status,
		Orders.Note,
		Products.Name AS ProductName,
		Properties.Size,
		Properties.Price,
		OrderItems.Quantity,
		OrderItems.Quantity * Properties.Price AS TotalLine,
		Payments.Total AS TotalInPayment,
		Promotions.Code AS PromotionCode,
		Promotions.Discount AS PromotionDiscount,
		Payments.Method AS PaymentMethod,
		Payments.CreatedBy AS EmployeeCreatedId,
		Orders.CreatedAt
	FROM OrderItems
	LEFT JOIN Orders ON OrderItems.OrderId = Orders.Id
	LEFT JOIN Products ON OrderItems.ProductId = Products.Id
	LEFT JOIN Properties ON OrderItems.ProductPropertyId = Properties.Id
	LEFT JOIN Promotions ON Orders.PromotionId = Promotions.Id
	LEFT JOIN Payments ON Payments.OrderId = OrderItems.OrderId
	WHERE (@Status IS NULL OR Orders.Status = @Status) 
		AND (@StartTime IS NULL OR Orders.CreatedAt > @StartTime) 
		AND (@EndTime IS NULL OR Orders.CreatedAt < @EndTime)
)

/*
Report
*/
-- Báo cáo doanh thu theo thời gian năm - tháng
GO
CREATE FUNCTION ExportRevenueReportFunction()
RETURNS TABLE
AS
RETURN (
	SELECT 
		DATEPART(YEAR, CreatedAt) AS Year,
		DATEPART(MONTH, CreatedAt) AS Month,
		COUNT(*) AS PaymentCount,
		SUM(Payments.Total) AS Revenue
	FROM Payments
	GROUP BY DATEPART(YEAR, CreatedAt), DATEPART(MONTH, CreatedAt)
)