#include"ohama.h"
int face(int card) {
	return card % 13; 
}
int suit(int card) {
	return card / 13; 
}
int displayMenu() {
	int mode;
	cout << endl << endl << endl << "Welcome to Dark Net - New generation of Poker" << endl;
	cout << "Select mode" << endl;
	cout << "1. Singleplayer" << endl;
	cout << "2. Multiplayer" << endl;
	cout << "3. Players vs Intelligent Dealer" << endl;
	cout << "4. Extra mode : Human vs Artificial Intelligent" << endl;
	cout << "0 : Leave " << endl;
	cout << "Your choice : " << endl;
	cin >> mode;
	return mode;
}
void shuffleCards(int* deck) {
	bool* check = new bool[CARDS];
	for (int i = 0; i < CARDS; i++)
		check[i] = true;
	for (int i = 0; i < CARDS; i++) {
		int num;
		{
			num = rand() % 52;
		} while (!check[num]);
		deck[i] = num;
	}
	delete[] check;
}
void printCardsShuffling(int deck[], string suits[], string faces[]) {
	for (int i = 0; i < CARDS; i++) {
		if (i % 4 == 0) {
			cout << endl;
		}
		cout <<"(" << faces[face(deck[i])] << "," << suits[suit(deck[i])] << ")    ";

	}
}bool isFourOfAKind(int* hand, int size) {
	int faceCount[FACES];
	for (int i = 0; i < FACES; i++) {
		faceCount[i] = 0; 
	}
	for (int i = 0; i < size; i++) {
		int faceCard = face(hand[i]);  
		if (++faceCount[faceCard] == 4)
			return true; 
	}
	return false; 
}
bool isFullHouse(int* hand, int size) {
	int faceCount[FACES];
	for (int i = 0; i < FACES; i++) {
		faceCount[i] = 0;
	}
	bool pair = false, toak = false;
	for (int i = 0; i < FACES; i++) {
		if (faceCount[i] == 2)
			pair = true;
		else if (faceCount[i] == 3)
			toak = true; 
	}
	return pair && toak; 
}
bool isFlush(int* hand, int size) {
	int suitCount[SUITS]; 
	for (int i = 0; i < SUITS; i++)
		suitCount[i] = 0 ;
	for (int i = 0; i < size; i++)
		if (++suitCount[suit(hand[i])] == 4)
			return true; 
	return false; 
}
bool isStraight(int* hand, int size) {
	int faceCount[FACES];
	for (int i = 0; i < FACES; i++) {
		faceCount[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		faceCount[face(hand[i])]++;
	}
	int cnt = 0; 
	for (int i = 1; i < FACES; i++) {
		if (faceCount[i] == 0) 
			cnt = 0;
		cnt++; 
		if (cnt == 5) 
			return true; 
	}
	return false; 
}
bool isStraightFlush(int* hand, int size) {
	int size = 5; 
	for (int i = 0; i < size - 5 + 1; i++)
		if (isStraight(hand + i, size) && isFlush(hand + i, size))
			return true; 
	return false; 
}
bool isThreeOfAKind(int* hand, int size) {
	int faceCount[FACES];
	for (int i = 0; i < FACES; i++) {
		faceCount[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		int faceCard = face(hand[i]);
		if (++faceCount[faceCard] == 3)
			return true;
	}
	return false;
}
bool isTwoPairs(int* hand, int size) {
	int faceCount[FACES];
	for (int i = 0; i < FACES; i++) {
		faceCount[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		int faceCard = face(hand[i]);
		++faceCount[faceCard]; 
	}
	int count = 0; 
	for (int i = 0; i < FACES; i++) {
		if (faceCount[i] == 2)
			count++; 
	}
	return count == 2;
}
bool isPairs(int* hand, int size) {
	int faceCount[FACES];
	for (int i = 0; i < FACES; i++) {
		faceCount[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		int faceCard = face(hand[i]);
		if (++faceCount[faceCard] == 2)
			return true; 
	}
	return false; 
}
int highestCard(int* hand, int size) {
	int maxx = 0; 
	for (int i = 0; i < size; i++) {
		maxx = (face(hand[i]) > maxx) ? face(hand[i]) : maxx; 
	}
	return maxx;
}