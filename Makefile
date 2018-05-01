cc3k: main.o cell.o floor.o subject.o textdisplay.o board.o allenemy.o allhoard.o allplayer.o allpotion.o character.o enemy.o player.o item.o potion.o treasure.o stair.o
	g++ -g -std=c++14 main.o cell.o floor.o subject.o textdisplay.o board.o allenemy.o allhoard.o allplayer.o allpotion.o character.o enemy.o player.o item.o potion.o treasure.o stair.o -o cc3k
main.o: main.cc allenemy.h allhoard.h allplayer.h allpotion.h board.h cell.h character.h enemy.h floor.h item.h observer.h player.h position.h potion.h stair.h subject.h subscriptions.h textdisplay.h treasure.h
	g++ -g -std=c++14 -c main.cc -o main.o
cell.o: cell.cc cell.h subscriptions.h observer.h subject.h textdisplay.h
	g++ -g -std=c++14 -c cell.cc -o cell.o
floor.o: floor.cc cell.h floor.h textdisplay.h
	g++ -g -std=c++14 -c floor.cc -o floor.o
subject.o: subject.cc subject.h subscriptions.h
	g++ -g -std=c++14 -c subject.cc -o subject.o
textdisplay.o: info.h cell.h textdisplay.h textdisplay.cc
	g++ -g -std=c++14 -c textdisplay.cc -o textdisplay.o
board.o: floor.h potion.h player.h enemy.h treasure.h stair.h allhoard.h allenemy.h allpotion.h allplayer.h character.h allplayer.h board.cc
	g++ -g -std=c++14 -c board.cc -o board.o
allenemy.o: enemy.h allenemy.cc
	g++ -g -std=c++14 -c allenemy.cc -o allenemy.o
allhoard.o: treasure.h allhoard.cc
	g++ -g -std=c++14 -c allhoard.cc -o allhoard.o
allplayer.o: player.h allplayer.cc
	g++ -g -std=c++14 -c allplayer.cc -o allplayer.o
allpotion.o: potion.h allpotion.cc
	g++ -g -std=c++14 -c allpotion.cc -o allpotion.o
character.o: position.h character.cc
	g++ -g -std=c++14 -c character.cc -o character.o
enemy.o: enemy.cc character.h
	g++ -g -std=c++14 -c enemy.cc -o enemy.o
player.o: character.h potion.h player.cc
	g++ -g -std=c++14 -c player.cc -o player.o
item.o: item.cc
	g++ -g -std=c++14 -c item.cc -o item.o
potion.o: potion.cc item.h
	g++ -g -std=c++14 -c potion.cc -o potion.o
treasure.o: treasure.cc item.h
	g++ -g -std=c++14 -c treasure.cc -o treasure.o
stair.o: stair.cc item.h
	g++ -g -std=c++14 -c stair.cc -o stair.o
