nome = input("nome: ")
l = ["*", "*", "*", "*", "*", "*", "*"]
x = len(nome)
print(f'{nome[0]}{l[x + 1:]}')