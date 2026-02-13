class BankAccount:
    def __init__(self, account_number, balance):
        self.account_number = account_number # Public
        self.__balance = balance # Private

    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount
            print(f"Nop {amount}. So du moi: {self.__balance}")
        else:
            print("So tien nop phai lon hon 0")

    def withdraw(self, amount):
        if 0 < amount <= self.__balance:
            self.__balance -= amount
            print(f"Rut {amount}. So du con lai: {self.__balance}")
        else:
            print("So tien khong hop le hoac khong du")

    def get_balance(self):
        return self.__balance

# Sử dụng
account = BankAccount("123456", 1000)
account.deposit(500)
account.withdraw(200)
print(f"So du hien tai: {account.get_balance()}")
# Không thể truy cập trực tiếp __balance từ bên ngoài
# print(account.__balance) # Sẽ gây lỗi
