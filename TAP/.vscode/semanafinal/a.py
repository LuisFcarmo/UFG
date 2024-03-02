def buscar(n):
    if n == 1:
        return 1
    if n%2 == 0:
        return buscar(n-1)*2
    else:
        return (buscar(n-1)*2)+1

n = int(input())
print(buscar(n))