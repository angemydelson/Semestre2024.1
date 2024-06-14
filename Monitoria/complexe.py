class complexo:
    def __init__(self, real, imaginario):
        self.real = real
        self.imaginario = imaginario
        
    def __str__(self):
        if self.imaginario >= 0:
            return f'{self.real} + {self.imaginario}i'
        else:
            return f'{self.real} - {abs(self.real)}i'
        
    def __add__(self, other):
        return complexo(self.real + other.real, self.imaginario + other.imaginario)
    
    def __sub__(self, other):
        return complexo(self.real - other.real, self.imaginario - other.imaginario)
    
    def __mul__(self, other):
        real = (self.real * other.real) - (self.imaginario * other.imaginario)
        imaginario = (self.real * other.imaginario) + (self.imaginario * other.real)
        return complexo(real, imaginario)
    
c1 = complexo(2, 1)
c2 = complexo(3, 2)
result = c1 + c2

print(result)
result = c1 - c2
print(result)
result = c1 * c2
print(result)