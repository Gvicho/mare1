import pygame
import serial
import time

pygame.init()

screen = pygame.display.set_mode((800,600))

pygame.display.set_caption("Mare1")
icon = pygame.image.load('logo.png')
pygame.display.set_icon(icon)

try:
    arduino = serial.Serial('COM4',9600)
    print("Connection to " + "COM4" + " established succesfully!\n")
except Exception as e:
    print(e)

playerImg = pygame.image.load('logo1.png')

vel = 100

def player(x,y):
    screen.blit(playerImg,(x,y))

nateli = True
bneli = False

b=1


while nateli:
    d=0
    print(b)
    x = 370
    y = 280
    time.sleep(.03)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            nateli = bneli

    keys = pygame.key.get_pressed()

    if keys[pygame.K_LEFT]:
        x -= vel
        arduino.write(bytes(b'4'))

    if keys[pygame.K_RIGHT]:
        x += vel
        arduino.write(bytes(b'3'))

    if keys[pygame.K_UP]:
        y -= vel
        arduino.write(bytes(b'1'))

    if keys[pygame.K_DOWN]:
        y += vel
        arduino.write(bytes(b'2'))
    if keys[pygame.K_SPACE]:
        if b==2 :
            arduino.write(bytes(b'8'))
            b=1
            d=1
            time.sleep(.3)
        if b==1 :
            if d==0:
                arduino.write(bytes(b'7'))
                b=2
                time.sleep(.3)


    screen.fill((0, 0, 0))  # Fills the screen with black
    player(x,y)
    pygame.display.update()

