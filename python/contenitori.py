#LISTE simile array c ma molto piu' potente

#lista a quattro nuemri come un array in c
l = [1, 2, 3, 4]

print(type(l))

#stampa l'intera lista
print(l)

#stampa la prima posizione della lista
print(l[0])

#stampa 2 e 3 due caratteri centrali
print(l[1:3])

#stampa la lista al contrario
print(l[::-1])

#le liste sono mutabili
l[1] = 9
print(l)

#si possono aggiungere elementi
l.append(5)
print(l)

#replica della lista per 4 volte
l1 = [1, 2, 3]
l2 = 4 * l1
print(l2)

#concatena la lista 2 alla 1
l1 = [1, 2, 3]
l2 = [4, 5]
l3 = l1 + l2
print(l3)