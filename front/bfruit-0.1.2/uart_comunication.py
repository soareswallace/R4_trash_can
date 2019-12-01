import RPi.GPIO as GPIO
import time
import serial
import subprocess
from subprocess import run
 
#Configura a serial e a velocidade de transmissao
#ser = serial.Serial("/dev/ttyS0", 9600)
#Configuracao inicial dos terminais GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(15, GPIO.IN)

game_commands = ["python", "bfruit_modified.py"]

while True:
   if GPIO.input(15) == False:
      print("passou lixo")
      run(game_commands)
      time.sleep(10)
   else:
      print("---------")

   #Aguarda reposta
   #resposta = ser.readline()
   #Mostra na tela a resposta enviada
   #pelo Arduino
   #print resposta
   time.sleep(0.0001)
