#include <iostream>
#include <string>
using namespace std;

class Sprite {
	int level[16][16];
public:
	Sprite();
	Sprite(string art);
	void show();

	Sprite operator~();
    Sprite operator!();
    Sprite operator-();
    Sprite operator+(Sprite op2);
};


Sprite::Sprite() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			level[i][j] = 0;
		}
	}
}

Sprite::Sprite(string art) {
	string palette = " .+#@";
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			level[i][j] = 0;
			int pos = i * 16 + j;
			if (pos >= (int)art.size()) continue;
			for (int k = 0; k <= 4; k++) {
				if (art[pos] == palette[k]) level[i][j] = k;
			}
		}
	}
}

void Sprite::show() {
	string palette = " .+#@";
	cout << "+----------------+\n";
	for (int i = 0; i < 16; i++) {
		cout << '|';
		for (int j = 0; j < 16; j++) {
			int v = level[i][j];
			if (v < 0 || v > 4) cout << '?';
			else cout << palette[v];
		}
		cout << "|\n";
	}
	cout << "+----------------+\n";
}

Sprite Sprite::operator~() {
	Sprite result;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			result.level[i][j] = 4 - level[i][j];
		}
	}
	return result;
}

Sprite Sprite::operator!(){
    Sprite result;
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            result.level[i][j]=level[i][15-j];
        }
    }
    return result;
}

Sprite Sprite::operator-(){
    Sprite result;
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            result.level[i][j]=level[15-i][j];
        }
    }
    return result;
}

Sprite Sprite::operator+(Sprite op2){
    Sprite result;
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            result.level[i][j]=level[i][j]+op2.level[i][j];
        }
    }
    return result;
}

Sprite readSprite() {
	string art;
	for (int i = 0; i < 16; i++) {
		string line;
		getline(cin, line);
		line.resize(16, ' ');
		art += line;
	}
	return Sprite(art);
}

int main() {
	string op, rest;
	cin >> op;
	getline(cin, rest);

	Sprite a = readSprite();

	cout << op << '\n';
	if (op == "~a") {
		(~a).show();
	} else if (op == "!a") {
		(!a).show();
	} else if (op == "-a") {
		(-a).show();
	} else if (op == "a+b") {
		Sprite b = readSprite();
		(a + b).show();
	} else if (op == "a+!a") {
		(a + !a).show();
	}

	return 0;
}