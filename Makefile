prog: main.o enemy.o perso.o background.o
	gcc main.o enemy.o perso.o background.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
perso.o:perso.c
	gcc -c perso.c -g
enemy.o:enemy.c
	gcc -c enemy.c -g
background.o:background.c
	gcc -c background.c -g
main.o:main.c
	gcc -c main.c -g

