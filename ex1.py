import os
clear = lambda: os.system('clear')

print("Informe a carga da particula (q): ")
while(True):
    try:
        carga = float(input())
        break;
    except:
        clear()
        print("Informe a carga da particula (q): ")

print("Informe o vetor Velocidade (Vx, Vy. Vz) (m/s): ")
vel = [0.0, 0.0, 0.0]
entry = str(input()).split(" ")
for i in range(3):
    try:
        vel[i] = float(entry[i])
    except:
        break;


print("Informe o vetor Campo Magnetico (Bx, By. Bz) (T): ")
campmag = [0.0, 0.0, 0.0]
entry = str(input()).split(" ")
for i in range(3):
    try:
        campmag[i] = float(entry[i])
    except:
        break;

result = [  vel[1]*campmag[2] - vel[2]*campmag[1], 
            vel[2]*campmag[0] - vel[0]*campmag[2], 
            vel[0]*campmag[1] - vel[1]*campmag[0]]
    
print("{:.2e}\n".format(carga))
print(["{:.2e}\n".format(out) for out in vel])
print(["{:.2e}\n".format(out) for out in campmag])
print("\nO resultado para Força Magnetica é: ")
print(["{:.2e}".format(out) for out in campmag])
