class Temperature:
    def __init__(self, celsius):
        self.__celsius = celsius

    @property
    def celsius(self):
        return self.__celsius
    
    @celsius.setter
    def celsius(self, value):
        if value < -273.15:
            print("Nhiet do khong the thap hon -273.15°C")
        else:
            self.__celsius = value

    @property
    def fahrenheit(self):
        return self.__celsius * 9/5 + 32

# Sử dụng
temp = Temperature(25)
print(f"Nhiet do: {temp.celsius}°C = {temp.fahrenheit}°F")
temp.celsius = 30
print(f"Nhiet do moi: {temp.celsius}°C = {temp.fahrenheit}°F")
temp.celsius = -300 # Sẽ bị từ chối

print(f"Nhiet do hien tai: {temp.celsius}°C = {temp.fahrenheit}°F")