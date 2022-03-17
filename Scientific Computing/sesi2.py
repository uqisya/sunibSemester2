import numpy as np
# nomor 1
# a = [[8, 3, -3], 
#      [-2, -8, 5], 
#      [3, 5, 10]]
# b = [14, 5, -8]

# nomor 2
# a = [[9, 1, -7], 
#      [-2, 1, 5], 
#      [3, 5, 1]]
# b = [14, 5, -8]

# nomor 3
a = [[9, 10, -7], 
     [-2, 8, 5], 
     [3, 5, 10]]
b = [14, 5, -8]

# find diagonal coefficients
diag = np.diag(np.abs(a))

print("diagonal: ")
print(diag)
print('\n')

# find row sum without diagonal
off_diag = np.sum(np.abs(a), axis = 1) - diag

print("off_diag: ")
print(off_diag)
print('\n')

if np.all(diag > off_diag):
  print("Matrix is diagonally dominant")
else:
  print("Not diagonally dominant")

x1 = 0
x2 = 0
x3 = 0
epsilon = 0.01
converged = False

x_old = np.array([x1, x2, x3])

print("iteration results")
print("k, x1, x2, x3")
for k in range(1,50):
  x1 = (b[0] - a[0][1]*x2 - a[0][2]*x3)/a[0][0] #8
  x2 = (b[1] - a[1][0]*x1 - a[1][2]*x3)/a[1][1] #-8
  x3 = (b[2] - a[2][0]*x1 - a[2][1]*x2)/a[2][2] #10

  x = np.array([x1, x2, x3])
  dx = np.sqrt(np.dot(x-x_old, x-x_old))

  print("%d, %.4f, %.4f, %.4f" % (k, x1, x2, x3))
  if(dx < epsilon):
    converged = True
    print("Converged")
    break
  
  # assign the latest x value to the old value
  x_old = x

if not converged:
  print("Not converge, increase the of iterations")
