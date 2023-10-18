#include "MyBigNum.h"

void MyBigNum::setHex(string str)
{
	int r = 0,len=0;
	for (int i = 0; i <= SIZE; i++) {
		_numD[i] = 0;
	}
	Lenght = str.size();
	for (int i = Lenght-1; i >= 0; --i) {
		if (str[i] >= '0' && str[i] <= '9')
			r = str[i] - 48;
		else if (str[i] >= 'a' && str[i] <= 'f')
			r = str[i] - 87;
		else if (str[i] >= 'A' && str[i] <= 'F')
			r = str[i] - 55;
		_numD[len]=  r ;
		len++;
	
	}
}

string MyBigNum::getHex()
{
    string HEX="";
    int i = Lenght - 1;
    //for (int i = Lenght - 1; i >= 0 ; --i);
    while (i >= 0) {
        if (_numD[i] == 10)
            HEX+= 'a';
        else if (_numD[i] == 11)
            HEX+= 'b';
        else if (_numD[i] == 12)
            HEX+= 'c';
        else if (_numD[i] == 13)
            HEX+= 'd';
        else if (_numD[i] == 14)
            HEX+= 'e';
        else if (_numD[i] == 15)
            HEX+= 'f';
        else
            HEX+= to_string(_numD[i]);
        --i;
    }
    return HEX;

}

void MyBigNum::ADD(MyBigNum *rez, MyBigNum* second)
{
    int left = 0;
    for (int i = 0; i < SIZE; ++i) {
        rez->_numD[i] = this->_numD[i] + second->_numD[i] + left;
        left = rez->_numD[i] / 16;
        rez->_numD[i] %= 16;
    }
    return ;
}
